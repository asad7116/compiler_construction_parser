%{
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "parser.h"
#include "token.h"
#include "lexer.h"

// Forward declarations
void yyerror(const char* msg);
int yylex();

// Declare as extern - definition is in parser.cpp
extern std::shared_ptr<ProgramNode> program_root;

%}

// Define the types AFTER including the headers
%code requires {
    #include <memory>
    #include <vector>
    #include <string>
    #include "parser.h"
    
    struct DeclarationWrapper {
        enum Type { FUNCTION, VARIABLE, ARRAY, POINTER } type;
        void* ptr;
        DeclarationWrapper(Type t, void* p) : type(t), ptr(p) {}
    };
}

%union {
    std::string* str_val;
    ProgramNode* program_node;
    FunctionNode* function_node;
    ParameterNode* parameter_node;
    StatementNode* statement_node;
    ExpressionNode* expression_node;
    BlockNode* block_node;
    VariableDeclarationNode* var_decl_node;
    ArrayDeclarationNode* array_decl_node;
    PointerDeclarationNode* pointer_decl_node;
    ArrayInitializationNode* array_init_node;
    CaseStatementNode* case_node;
    DefaultStatementNode* default_node;
    std::vector<std::shared_ptr<ParameterNode>>* param_list;
    std::vector<std::shared_ptr<StatementNode>>* stmt_list;
    std::vector<std::shared_ptr<ExpressionNode>>* expr_list;
    std::vector<std::shared_ptr<CaseStatementNode>>* case_list;
    std::vector<DeclarationWrapper*>* decl_list;
    DeclarationWrapper* decl_wrapper;
}

// Tokens with semantic values
%token <str_val> T_IDENTIFIER T_INT_LITERAL T_FLOAT_LITERAL T_STRING_LITERAL T_CHAR_LITERAL T_BOOL_LITERAL T_NULL_LITERAL T_HEX_LITERAL T_OCTAL_LITERAL T_BINARY_LITERAL

// Keywords
%token T_FUNCTION T_INT T_FLOAT T_STRING T_BOOL T_CHAR T_VOID
%token T_IF T_ELSE T_ELIF T_WHILE T_FOR T_DO
%token T_SWITCH T_CASE T_DEFAULT
%token T_RETURN T_BREAK T_CONTINUE
%token T_PRINT T_READ
%token T_TRUE T_FALSE T_NULL T_INCLUDE

// Operators
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_MODULO
%token T_EQUAL T_NOT_EQUAL T_GREATER_THAN T_LESS_THAN
%token T_GREATER_THAN_EQUAL T_LESS_THAN_EQUAL
%token T_AND T_OR T_NOT
%token T_BIT_AND T_BIT_OR T_BIT_XOR T_BIT_NOT
%token T_LEFT_SHIFT T_RIGHT_SHIFT
%token T_ASSIGN
%token T_PLUS_ASSIGN T_MINUS_ASSIGN T_MULT_ASSIGN
%token T_DIV_ASSIGN T_MOD_ASSIGN
%token T_AND_ASSIGN T_OR_ASSIGN T_XOR_ASSIGN
%token T_LSHIFT_ASSIGN T_RSHIFT_ASSIGN
%token T_INCREMENT T_DECREMENT

// Punctuation
%token T_COMMA T_SEMICOLON T_COLON T_DOT
%token T_LPAREN T_RPAREN T_LBRACE T_RBRACE T_LBRACKET T_RBRACKET
%token T_QUESTION T_QUOTES

// Non-terminal types
%type <program_node> program
%type <decl_list> global_declaration_list
%type <decl_wrapper> global_declaration
%type <stmt_list> statement_list
%type <statement_node> statement assignment_statement if_statement while_statement for_statement do_while_statement switch_statement return_statement break_statement continue_statement print_statement expression_statement for_init for_update
%type <function_node> function_declaration
%type <var_decl_node> variable_declaration
%type <array_decl_node> array_declaration
%type <pointer_decl_node> pointer_declaration
%type <block_node> block
%type <expression_node> expression assignment_expression ternary_expression logical_or_expression logical_and_expression bitwise_or_expression bitwise_xor_expression bitwise_and_expression equality_expression relational_expression shift_expression additive_expression multiplicative_expression unary_expression postfix_expression primary_expression literal
%type <array_init_node> array_initializer
%type <str_val> type base_type assignment_operator
%type <param_list> parameter_list
%type <parameter_node> parameter
%type <expr_list> argument_list expression_list
%type <case_list> case_list
%type <case_node> case_statement
%type <default_node> default_case

// Operator precedence
%right T_ASSIGN T_PLUS_ASSIGN T_MINUS_ASSIGN T_MULT_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN T_AND_ASSIGN T_OR_ASSIGN T_XOR_ASSIGN T_LSHIFT_ASSIGN T_RSHIFT_ASSIGN
%right T_QUESTION T_COLON
%left T_OR
%left T_AND
%left T_BIT_OR
%left T_BIT_XOR
%left T_BIT_AND
%left T_EQUAL T_NOT_EQUAL
%left T_GREATER_THAN T_LESS_THAN T_GREATER_THAN_EQUAL T_LESS_THAN_EQUAL
%left T_LEFT_SHIFT T_RIGHT_SHIFT
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE T_MODULO
%right T_NOT T_BIT_NOT T_INCREMENT T_DECREMENT UNARY
%left T_LPAREN T_LBRACKET T_DOT

%%

program:
    global_declaration_list
    {
        program_root = std::make_shared<ProgramNode>();
        
        if ($1) {
            for (auto wrapper : *$1) {
                switch (wrapper->type) {
                    case DeclarationWrapper::FUNCTION: {
                        auto func = static_cast<FunctionNode*>(wrapper->ptr);
                        program_root->functions.push_back(std::shared_ptr<FunctionNode>(func));
                        std::cout << "DEBUG: Added function: " << func->name << std::endl;
                        break;
                    }
                    case DeclarationWrapper::VARIABLE: {
                        auto var = static_cast<VariableDeclarationNode*>(wrapper->ptr);
                        program_root->globalVariables.push_back(std::shared_ptr<VariableDeclarationNode>(var));
                        std::cout << "DEBUG: Added variable: " << var->name << std::endl;
                        break;
                    }
                    case DeclarationWrapper::ARRAY: {
                        auto arr = static_cast<ArrayDeclarationNode*>(wrapper->ptr);
                        auto var = std::make_shared<VariableDeclarationNode>();
                        var->name = arr->name;
                        var->type = arr->type;
                        program_root->globalVariables.push_back(var);
                        std::cout << "DEBUG: Added array: " << arr->name << std::endl;
                        delete arr;
                        break;
                    }
                    case DeclarationWrapper::POINTER: {
                        auto ptr = static_cast<PointerDeclarationNode*>(wrapper->ptr);
                        auto var = std::make_shared<VariableDeclarationNode>();
                        var->name = ptr->name;
                        var->type = ptr->baseType + "*";
                        program_root->globalVariables.push_back(var);
                        std::cout << "DEBUG: Added pointer: " << ptr->name << std::endl;
                        delete ptr;
                        break;
                    }
                }
                delete wrapper;
            }
            delete $1;
        }
        
        std::cout << "DEBUG: Program created with " 
                  << program_root->functions.size() << " functions and "
                  << program_root->globalVariables.size() << " global variables" << std::endl;
        
        $$ = program_root.get();
    }
;

global_declaration_list:
    %empty 
    { 
        $$ = new std::vector<DeclarationWrapper*>(); 
    }
    | global_declaration_list global_declaration
    {
        if ($2) $1->push_back($2);
        $$ = $1;
    }
;

global_declaration:
    function_declaration 
    { 
        $$ = new DeclarationWrapper(DeclarationWrapper::FUNCTION, $1);
    }
    | variable_declaration 
    { 
        $$ = new DeclarationWrapper(DeclarationWrapper::VARIABLE, $1);
    }
    | array_declaration 
    { 
        $$ = new DeclarationWrapper(DeclarationWrapper::ARRAY, $1);
    }
    | pointer_declaration 
    { 
        $$ = new DeclarationWrapper(DeclarationWrapper::POINTER, $1);
    }
;

function_declaration:
    T_FUNCTION base_type T_IDENTIFIER T_LPAREN parameter_list T_RPAREN block
    {
        auto func = new FunctionNode();
        func->returnType = *$2;
        func->name = *$3;
        if ($5) func->parameters = *$5;
        func->body = std::shared_ptr<BlockNode>($7);
        std::cout << "DEBUG: Created function '" << func->name << "' with return type '" << func->returnType << "'" << std::endl;
        $$ = func;
        delete $2;
        delete $3;
        if ($5) delete $5;
    }
    | T_FUNCTION T_IDENTIFIER T_LPAREN parameter_list T_RPAREN block
    {
        auto func = new FunctionNode();
        func->name = *$2;
        func->returnType = "void";
        if ($4) func->parameters = *$4;
        func->body = std::shared_ptr<BlockNode>($6);
        std::cout << "DEBUG: Created function '" << func->name << "' (void)" << std::endl;
        $$ = func;
        delete $2;
        if ($4) delete $4;
    }
;

parameter_list:
    %empty { $$ = new std::vector<std::shared_ptr<ParameterNode>>(); }
    | parameter { 
        $$ = new std::vector<std::shared_ptr<ParameterNode>>();
        $$->push_back(std::shared_ptr<ParameterNode>($1));
    }
    | parameter_list T_COMMA parameter
    {
        $1->push_back(std::shared_ptr<ParameterNode>($3));
        $$ = $1;
    }
;

parameter:
    base_type T_IDENTIFIER
    {
        auto param = new ParameterNode();
        param->type = *$1;
        param->name = *$2;
        $$ = param;
        delete $1;
        delete $2;
    }
    | type T_IDENTIFIER
    {
        auto param = new ParameterNode();
        param->type = *$1;
        param->name = *$2;
        $$ = param;
        delete $1;
        delete $2;
    }
;

type:
    base_type { $$ = $1; }
    | type T_MULTIPLY { $$ = new std::string(*$1 + "*"); delete $1; }
    | type T_LBRACKET T_RBRACKET { $$ = new std::string(*$1 + "[]"); delete $1; }
    | type T_LBRACKET expression T_RBRACKET { $$ = new std::string(*$1 + "[]"); delete $1; }
;

base_type:
    T_INT { $$ = new std::string("int"); }
    | T_FLOAT { $$ = new std::string("float"); }
    | T_STRING { $$ = new std::string("string"); }
    | T_CHAR { $$ = new std::string("char"); }
    | T_BOOL { $$ = new std::string("bool"); }
    | T_VOID { $$ = new std::string("void"); }
;

block:
    T_LBRACE statement_list T_RBRACE
    {
        auto block_node = new BlockNode();
        if ($2) {
            block_node->statements = *$2;
            delete $2;
        }
        $$ = block_node;
    }
;

statement_list:
    %empty { $$ = new std::vector<std::shared_ptr<StatementNode>>(); }
    | statement_list statement
    {
        if ($2) $1->push_back(std::shared_ptr<StatementNode>($2));
        $$ = $1;
    }
;

statement:
    variable_declaration { $$ = $1; }
    | array_declaration { $$ = $1; }
    | pointer_declaration { $$ = $1; }
    | assignment_statement { $$ = $1; }
    | if_statement { $$ = $1; }
    | while_statement { $$ = $1; }
    | for_statement { $$ = $1; }
    | do_while_statement { $$ = $1; }
    | switch_statement { $$ = $1; }
    | return_statement { $$ = $1; }
    | break_statement { $$ = $1; }
    | continue_statement { $$ = $1; }
    | print_statement { $$ = $1; }
    | expression_statement { $$ = $1; }
    | T_SEMICOLON { $$ = nullptr; }
;

variable_declaration:
    base_type T_IDENTIFIER T_SEMICOLON
    {
        auto var = new VariableDeclarationNode();
        var->type = *$1;
        var->name = *$2;
        $$ = var;
        delete $1;
        delete $2;
    }
    | base_type T_IDENTIFIER T_ASSIGN expression T_SEMICOLON
    {
        auto var = new VariableDeclarationNode();
        var->type = *$1;
        var->name = *$2;
        var->initializer = std::shared_ptr<ExpressionNode>($4);
        $$ = var;
        delete $1;
        delete $2;
    }
;

array_declaration:
    type T_IDENTIFIER T_LBRACKET expression T_RBRACKET T_SEMICOLON
    {
        auto arr = new ArrayDeclarationNode();
        arr->type = *$1;
        arr->name = *$2;
        arr->size = std::shared_ptr<ExpressionNode>($4);
        $$ = arr;
        delete $1;
        delete $2;
    }
    | type T_IDENTIFIER T_LBRACKET T_RBRACKET T_ASSIGN array_initializer T_SEMICOLON
    {
        auto arr = new ArrayDeclarationNode();
        arr->type = *$1;
        arr->name = *$2;
        arr->initializer = std::shared_ptr<ArrayInitializationNode>($6);
        $$ = arr;
        delete $1;
        delete $2;
    }
    | base_type T_IDENTIFIER T_LBRACKET expression T_RBRACKET T_SEMICOLON
    {
        auto arr = new ArrayDeclarationNode();
        arr->type = *$1;
        arr->name = *$2;
        arr->size = std::shared_ptr<ExpressionNode>($4);
        $$ = arr;
        delete $1;
        delete $2;
    }
;

array_initializer:
    T_LBRACE expression_list T_RBRACE
    {
        auto init = new ArrayInitializationNode();
        if ($2) {
            init->elements = *$2;
            delete $2;
        }
        $$ = init;
    }
    | T_LBRACE T_RBRACE
    {
        $$ = new ArrayInitializationNode();
    }
;

expression_list:
    expression { 
        $$ = new std::vector<std::shared_ptr<ExpressionNode>>();
        $$->push_back(std::shared_ptr<ExpressionNode>($1));
    }
    | expression_list T_COMMA expression
    {
        $1->push_back(std::shared_ptr<ExpressionNode>($3));
        $$ = $1;
    }
;

pointer_declaration:
    base_type T_MULTIPLY T_IDENTIFIER T_SEMICOLON
    {
        auto ptr = new PointerDeclarationNode();
        ptr->baseType = *$1;
        ptr->name = *$3;
        $$ = ptr;
        delete $1;
        delete $3;
    }
    | base_type T_MULTIPLY T_IDENTIFIER T_ASSIGN expression T_SEMICOLON
    {
        auto ptr = new PointerDeclarationNode();
        ptr->baseType = *$1;
        ptr->name = *$3;
        ptr->initializer = std::shared_ptr<ExpressionNode>($5);
        $$ = ptr;
        delete $1;
        delete $3;
    }
;

assignment_statement:
    T_IDENTIFIER assignment_operator expression T_SEMICOLON
    {
        auto assign = new AssignmentNode();
        assign->variable = *$1;
        assign->value = std::shared_ptr<ExpressionNode>($3);
        $$ = assign;
        delete $1;
        delete $2;
    }
    | T_IDENTIFIER T_LBRACKET expression T_RBRACKET assignment_operator expression T_SEMICOLON
    {
        // Array element assignment: arr[index] = value
        auto assign = new AssignmentNode();
        assign->variable = *$1 + "[...]";  // Mark as array access
        assign->value = std::shared_ptr<ExpressionNode>($6);
        $$ = assign;
        delete $1;
        delete $5;
    }
;

assignment_operator:
    T_ASSIGN { $$ = new std::string("="); }
    | T_PLUS_ASSIGN { $$ = new std::string("+="); }
    | T_MINUS_ASSIGN { $$ = new std::string("-="); }
    | T_MULT_ASSIGN { $$ = new std::string("*="); }
    | T_DIV_ASSIGN { $$ = new std::string("/="); }
    | T_MOD_ASSIGN { $$ = new std::string("%="); }
;

if_statement:
    T_IF T_LPAREN expression T_RPAREN statement
    {
        auto if_stmt = new IfStatementNode();
        if_stmt->condition = std::shared_ptr<ExpressionNode>($3);
        auto then_block = std::make_shared<BlockNode>();
        if ($5) then_block->statements.push_back(std::shared_ptr<StatementNode>($5));
        if_stmt->thenBlock = then_block;
        $$ = if_stmt;
    }
    | T_IF T_LPAREN expression T_RPAREN statement T_ELSE statement
    {
        auto if_stmt = new IfStatementNode();
        if_stmt->condition = std::shared_ptr<ExpressionNode>($3);
        auto then_block = std::make_shared<BlockNode>();
        if ($5) then_block->statements.push_back(std::shared_ptr<StatementNode>($5));
        if_stmt->thenBlock = then_block;
        auto else_block = std::make_shared<BlockNode>();
        if ($7) else_block->statements.push_back(std::shared_ptr<StatementNode>($7));
        if_stmt->elseBlock = else_block;
        $$ = if_stmt;
    }
;

while_statement:
    T_WHILE T_LPAREN expression T_RPAREN statement
    {
        auto while_stmt = new WhileStatementNode();
        while_stmt->condition = std::shared_ptr<ExpressionNode>($3);
        auto body = std::make_shared<BlockNode>();
        if ($5) body->statements.push_back(std::shared_ptr<StatementNode>($5));
        while_stmt->body = body;
        $$ = while_stmt;
    }
;

for_statement:
    T_FOR T_LPAREN for_init T_SEMICOLON expression T_SEMICOLON for_update T_RPAREN statement
    {
        auto for_stmt = new ForStatementNode();
        for_stmt->initialization = std::shared_ptr<StatementNode>($3);
        for_stmt->condition = std::shared_ptr<ExpressionNode>($5);
        for_stmt->update = std::shared_ptr<StatementNode>($7);
        auto body = std::make_shared<BlockNode>();
        if ($9) body->statements.push_back(std::shared_ptr<StatementNode>($9));
        for_stmt->body = body;
        $$ = for_stmt;
    }
;

for_init:
    %empty { $$ = nullptr; }
    | variable_declaration { $$ = $1; }
    | expression { 
        auto assign = new AssignmentNode();
        assign->value = std::shared_ptr<ExpressionNode>($1);
        $$ = assign;
    }
;

for_update:
    %empty { $$ = nullptr; }
    | expression { 
        auto assign = new AssignmentNode();
        assign->value = std::shared_ptr<ExpressionNode>($1);
        $$ = assign;
    }
;

do_while_statement:
    T_DO statement T_WHILE T_LPAREN expression T_RPAREN T_SEMICOLON
    {
        auto do_while = new DoWhileStatementNode();
        auto body = std::make_shared<BlockNode>();
        if ($2) body->statements.push_back(std::shared_ptr<StatementNode>($2));
        do_while->body = body;
        do_while->condition = std::shared_ptr<ExpressionNode>($5);
        $$ = do_while;
    }
;

switch_statement:
    T_SWITCH T_LPAREN expression T_RPAREN T_LBRACE case_list default_case T_RBRACE
    {
        auto switch_stmt = new SwitchStatementNode();
        switch_stmt->expression = std::shared_ptr<ExpressionNode>($3);
        if ($6) {
            switch_stmt->cases = *$6;
            delete $6;
        }
        if ($7) switch_stmt->defaultCase = std::shared_ptr<DefaultStatementNode>($7);
        $$ = switch_stmt;
    }
;

case_list:
    %empty { $$ = new std::vector<std::shared_ptr<CaseStatementNode>>(); }
    | case_list case_statement
    {
        $1->push_back(std::shared_ptr<CaseStatementNode>($2));
        $$ = $1;
    }
;

case_statement:
    T_CASE expression T_COLON statement_list
    {
        auto case_stmt = new CaseStatementNode();
        case_stmt->value = std::shared_ptr<ExpressionNode>($2);
        if ($4) {
            case_stmt->statements = *$4;
            delete $4;
        }
        $$ = case_stmt;
    }
;

default_case:
    %empty { $$ = nullptr; }
    | T_DEFAULT T_COLON statement_list
    {
        auto default_stmt = new DefaultStatementNode();
        if ($3) {
            default_stmt->statements = *$3;
            delete $3;
        }
        $$ = default_stmt;
    }
;

return_statement:
    T_RETURN T_SEMICOLON
    {
        $$ = new ReturnStatementNode();
    }
    | T_RETURN expression T_SEMICOLON
    {
        auto return_stmt = new ReturnStatementNode();
        return_stmt->expression = std::shared_ptr<ExpressionNode>($2);
        $$ = return_stmt;
    }
;

break_statement:
    T_BREAK T_SEMICOLON { $$ = new BreakStatementNode(); }
;

continue_statement:
    T_CONTINUE T_SEMICOLON { $$ = new ContinueStatementNode(); }
;

print_statement:
    T_PRINT expression T_SEMICOLON
    {
        auto print_stmt = new PrintStatementNode();
        print_stmt->expression = std::shared_ptr<ExpressionNode>($2);
        $$ = print_stmt;
    }
;

expression_statement:
    expression T_SEMICOLON
    {
        auto assign = new AssignmentNode();
        assign->value = std::shared_ptr<ExpressionNode>($1);
        $$ = assign;
    }
;

expression:
    assignment_expression { $$ = $1; }
;

assignment_expression:
    ternary_expression { $$ = $1; }
;

ternary_expression:
    logical_or_expression { $$ = $1; }
    | logical_or_expression T_QUESTION expression T_COLON ternary_expression
    {
        auto ternary = new TernaryNode();
        ternary->condition = std::shared_ptr<ExpressionNode>($1);
        ternary->trueValue = std::shared_ptr<ExpressionNode>($3);
        ternary->falseValue = std::shared_ptr<ExpressionNode>($5);
        $$ = ternary;
    }
;

logical_or_expression:
    logical_and_expression { $$ = $1; }
    | logical_or_expression T_OR logical_and_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "||";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
;

logical_and_expression:
    bitwise_or_expression { $$ = $1; }
    | logical_and_expression T_AND bitwise_or_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "&&";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
;

bitwise_or_expression:
    bitwise_xor_expression { $$ = $1; }
    | bitwise_or_expression T_BIT_OR bitwise_xor_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "|";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
;

bitwise_xor_expression:
    bitwise_and_expression { $$ = $1; }
    | bitwise_xor_expression T_BIT_XOR bitwise_and_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "^";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
;

bitwise_and_expression:
    equality_expression { $$ = $1; }
    | bitwise_and_expression T_BIT_AND equality_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "&";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
;

equality_expression:
    relational_expression { $$ = $1; }
    | equality_expression T_EQUAL relational_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "==";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
    | equality_expression T_NOT_EQUAL relational_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "!=";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
;

relational_expression:
    shift_expression { $$ = $1; }
    | relational_expression T_GREATER_THAN shift_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = ">";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
    | relational_expression T_LESS_THAN shift_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "<";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
    | relational_expression T_GREATER_THAN_EQUAL shift_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = ">=";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
    | relational_expression T_LESS_THAN_EQUAL shift_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "<=";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
;

shift_expression:
    additive_expression { $$ = $1; }
    | shift_expression T_LEFT_SHIFT additive_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "<<";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
    | shift_expression T_RIGHT_SHIFT additive_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = ">>";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
;

additive_expression:
    multiplicative_expression { $$ = $1; }
    | additive_expression T_PLUS multiplicative_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "+";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
    | additive_expression T_MINUS multiplicative_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "-";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
;

multiplicative_expression:
    unary_expression { $$ = $1; }
    | multiplicative_expression T_MULTIPLY unary_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "*";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
    | multiplicative_expression T_DIVIDE unary_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "/";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
    | multiplicative_expression T_MODULO unary_expression
    {
        auto binary = new BinaryOpNode();
        binary->op = "%";
        binary->left = std::shared_ptr<ExpressionNode>($1);
        binary->right = std::shared_ptr<ExpressionNode>($3);
        $$ = binary;
    }
;

unary_expression:
    postfix_expression { $$ = $1; }
    | T_NOT unary_expression
    {
        auto unary = new UnaryOpNode();
        unary->op = "!";
        unary->operand = std::shared_ptr<ExpressionNode>($2);
        $$ = unary;
    }
    | T_MINUS unary_expression %prec UNARY
    {
        auto unary = new UnaryOpNode();
        unary->op = "-";
        unary->operand = std::shared_ptr<ExpressionNode>($2);
        $$ = unary;
    }
    | T_BIT_NOT unary_expression
    {
        auto unary = new UnaryOpNode();
        unary->op = "~";
        unary->operand = std::shared_ptr<ExpressionNode>($2);
        $$ = unary;
    }
    | T_INCREMENT unary_expression
    {
        auto unary = new UnaryOpNode();
        unary->op = "++";
        unary->operand = std::shared_ptr<ExpressionNode>($2);
        $$ = unary;
    }
    | T_DECREMENT unary_expression
    {
        auto unary = new UnaryOpNode();
        unary->op = "--";
        unary->operand = std::shared_ptr<ExpressionNode>($2);
        $$ = unary;
    }
    | T_MULTIPLY unary_expression %prec UNARY
    {
        auto deref = new DereferenceNode();
        deref->operand = std::shared_ptr<ExpressionNode>($2);
        $$ = deref;
    }
    | T_BIT_AND unary_expression %prec UNARY
    {
        auto addr = new AddressOfNode();
        addr->operand = std::shared_ptr<ExpressionNode>($2);
        $$ = addr;
    }
;

postfix_expression:
    primary_expression { $$ = $1; }
    | postfix_expression T_INCREMENT
    {
        auto unary = new UnaryOpNode();
        unary->op = "++";
        unary->operand = std::shared_ptr<ExpressionNode>($1);
        $$ = unary;
    }
    | postfix_expression T_DECREMENT
    {
        auto unary = new UnaryOpNode();
        unary->op = "--";
        unary->operand = std::shared_ptr<ExpressionNode>($1);
        $$ = unary;
    }
    | postfix_expression T_LBRACKET expression T_RBRACKET
    {
        auto access = new ArrayAccessNode();
        if (auto id = dynamic_cast<IdentifierNode*>($1)) {
            access->arrayName = id->name;
            delete $1;
        }
        access->index = std::shared_ptr<ExpressionNode>($3);
        $$ = access;
    }
    | postfix_expression T_LPAREN argument_list T_RPAREN
    {
        auto call = new FunctionCallNode();
        if (auto id = dynamic_cast<IdentifierNode*>($1)) {
            call->functionName = id->name;
            delete $1;
        }
        if ($3) {
            call->arguments = *$3;
            delete $3;
        }
        $$ = call;
    }
;

primary_expression:
    literal { $$ = $1; }
    | T_IDENTIFIER
    {
        auto id = new IdentifierNode();
        id->name = *$1;
        delete $1;
        $$ = id;
    }
    | T_LPAREN expression T_RPAREN { $$ = $2; }
;

literal:
    T_INT_LITERAL
    {
        auto lit = new LiteralNode();
        lit->value = *$1;
        lit->type = "int";
        delete $1;
        $$ = lit;
    }
    | T_FLOAT_LITERAL
    {
        auto lit = new LiteralNode();
        lit->value = *$1;
        lit->type = "float";
        delete $1;
        $$ = lit;
    }
    | T_STRING_LITERAL
    {
        auto lit = new LiteralNode();
        lit->value = *$1;
        lit->type = "string";
        delete $1;
        $$ = lit;
    }
    | T_CHAR_LITERAL
    {
        auto lit = new LiteralNode();
        lit->value = *$1;
        lit->type = "char";
        delete $1;
        $$ = lit;
    }
    | T_TRUE
    {
        auto lit = new LiteralNode();
        lit->value = "true";
        lit->type = "bool";
        $$ = lit;
    }
    | T_FALSE
    {
        auto lit = new LiteralNode();
        lit->value = "false";
        lit->type = "bool";
        $$ = lit;
    }
    | T_NULL_LITERAL
    {
        auto lit = new LiteralNode();
        lit->value = "null";
        lit->type = "null";
        delete $1;
        $$ = lit;
    }
    | T_HEX_LITERAL
    {
        auto lit = new LiteralNode();
        lit->value = *$1;
        lit->type = "hex";
        delete $1;
        $$ = lit;
    }
    | T_OCTAL_LITERAL
    {
        auto lit = new LiteralNode();
        lit->value = *$1;
        lit->type = "octal";
        delete $1;
        $$ = lit;
    }
    | T_BINARY_LITERAL
    {
        auto lit = new LiteralNode();
        lit->value = *$1;
        lit->type = "binary";
        delete $1;
        $$ = lit;
    }
;

argument_list:
    %empty { $$ = new std::vector<std::shared_ptr<ExpressionNode>>(); }
    | expression
    {
        $$ = new std::vector<std::shared_ptr<ExpressionNode>>();
        $$->push_back(std::shared_ptr<ExpressionNode>($1));
    }
    | argument_list T_COMMA expression
    {
        $1->push_back(std::shared_ptr<ExpressionNode>($3));
        $$ = $1;
    }
;

%%


void yyerror(const char* msg) {
    extern Lexer* global_lexer;
    std::cerr << "Parse error: " << msg << std::endl;
    if (global_lexer) {
        std::cerr << "At line " << global_lexer->getLineNumber() 
                  << ", column " << global_lexer->getColumnNumber() << std::endl;
    }
}