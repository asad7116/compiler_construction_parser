#include "scope_analyzer.h"
#include <iostream>

// Main analysis entry point
bool ScopeAnalyzer::analyze(const std::shared_ptr<ProgramNode>& program) {
    errors.clear();
    
    // Initialize global scope
    scopeLevel = 0;
    currentScope = std::make_shared<ScopeNode>(0, nullptr);
    
    // Phase 1: Register all global variables and function prototypes
    // This allows functions to be called before they're defined (C-style)
    for (const auto& varDecl : program->globalVariables) {
        if (!currentScope->declare(varDecl->name, varDecl->type)) {
            reportError(ScopeError::VariableRedefinition,
                       "Global variable '" + varDecl->name + "' redefined");
        }
    }
    
    for (const auto& func : program->functions) {
        auto it = functionTable.find(func->name);
        if (it != functionTable.end()) {
            reportError(ScopeError::FunctionPrototypeRedefinition,
                       "Function '" + func->name + "' redefined");
        } else {
            auto funcSymbol = std::make_shared<FunctionSymbol>(func->name, func->returnType);
            funcSymbol->isDefined = true;
            
            for (const auto& param : func->parameters) {
                funcSymbol->addParameter(param->type, param->name);
            }
            
            functionTable[func->name] = funcSymbol;
        }
    }
    
    // Phase 2: Analyze function bodies
    for (const auto& func : program->functions) {
        analyzeFunction(func);
    }
    
    return !hasErrors();
}

// Analyze a function
void ScopeAnalyzer::analyzeFunction(const std::shared_ptr<FunctionNode>& function) {
    // Enter function scope
    enterScope();
    
    // Declare parameters in function scope
    for (const auto& param : function->parameters) {
        if (!currentScope->declare(param->name, param->type, true)) {
            reportError(ScopeError::VariableRedefinition,
                       "Parameter '" + param->name + "' in function '" + 
                       function->name + "' redefined");
        }
    }
    
    // Analyze function body
    if (function->body) {
        // Don't enter a new scope for the function body block
        // The function itself creates the scope
        for (const auto& statement : function->body->statements) {
            analyzeStatement(statement);
        }
    }
    
    // Exit function scope
    exitScope();
}

// Analyze a block (creates a new scope)
void ScopeAnalyzer::analyzeBlock(const std::shared_ptr<BlockNode>& block) {
    enterScope();
    
    for (const auto& statement : block->statements) {
        analyzeStatement(statement);
    }
    
    exitScope();
}

// Analyze a statement
void ScopeAnalyzer::analyzeStatement(const std::shared_ptr<StatementNode>& statement) {
    if (!statement) return;
    
    // Variable declaration
    if (auto varDecl = std::dynamic_pointer_cast<VariableDeclarationNode>(statement)) {
        analyzeVariableDeclaration(varDecl);
    }
    // Assignment
    else if (auto assignment = std::dynamic_pointer_cast<AssignmentNode>(statement)) {
        analyzeAssignment(assignment);
    }
    // If statement
    else if (auto ifStmt = std::dynamic_pointer_cast<IfStatementNode>(statement)) {
        analyzeIfStatement(ifStmt);
    }
    // While statement
    else if (auto whileStmt = std::dynamic_pointer_cast<WhileStatementNode>(statement)) {
        analyzeWhileStatement(whileStmt);
    }
    // For statement
    else if (auto forStmt = std::dynamic_pointer_cast<ForStatementNode>(statement)) {
        analyzeForStatement(forStmt);
    }
    // Do-while statement
    else if (auto doWhileStmt = std::dynamic_pointer_cast<DoWhileStatementNode>(statement)) {
        analyzeDoWhileStatement(doWhileStmt);
    }
    // Switch statement
    else if (auto switchStmt = std::dynamic_pointer_cast<SwitchStatementNode>(statement)) {
        analyzeSwitchStatement(switchStmt);
    }
    // Return statement
    else if (auto returnStmt = std::dynamic_pointer_cast<ReturnStatementNode>(statement)) {
        analyzeReturnStatement(returnStmt);
    }
    // Print statement
    else if (auto printStmt = std::dynamic_pointer_cast<PrintStatementNode>(statement)) {
        analyzePrintStatement(printStmt);
    }
    // Break/Continue statements (no scope checking needed)
    else if (auto breakStmt = std::dynamic_pointer_cast<BreakStatementNode>(statement)) {
        // No scope checking needed
    }
    else if (auto continueStmt = std::dynamic_pointer_cast<ContinueStatementNode>(statement)) {
        // No scope checking needed
    }
}

// Analyze an expression
void ScopeAnalyzer::analyzeExpression(const std::shared_ptr<ExpressionNode>& expression) {
    if (!expression) return;
    
    // Function call
    if (auto funcCall = std::dynamic_pointer_cast<FunctionCallNode>(expression)) {
        analyzeFunctionCall(funcCall);
    }
    // Identifier (variable reference)
    else if (auto identifier = std::dynamic_pointer_cast<IdentifierNode>(expression)) {
        analyzeIdentifier(identifier);
    }
    // Binary operation
    else if (auto binaryOp = std::dynamic_pointer_cast<BinaryOpNode>(expression)) {
        analyzeBinaryOp(binaryOp);
    }
    // Unary operation
    else if (auto unaryOp = std::dynamic_pointer_cast<UnaryOpNode>(expression)) {
        analyzeUnaryOp(unaryOp);
    }
    // Ternary operation
    else if (auto ternary = std::dynamic_pointer_cast<TernaryNode>(expression)) {
        analyzeTernary(ternary);
    }
    // Literal (no scope checking needed)
    else if (auto literal = std::dynamic_pointer_cast<LiteralNode>(expression)) {
        // No scope checking needed for literals
    }
}

// Variable Declaration
void ScopeAnalyzer::analyzeVariableDeclaration(const std::shared_ptr<VariableDeclarationNode>& varDecl) {
    // Check if initializer references valid variables
    if (varDecl->initializer) {
        analyzeExpression(varDecl->initializer);
    }
    
    // Declare the variable in current scope
    if (!currentScope->declare(varDecl->name, varDecl->type)) {
        reportError(ScopeError::VariableRedefinition,
                   "Variable '" + varDecl->name + "' redefined in same scope");
    }
}

// Assignment
void ScopeAnalyzer::analyzeAssignment(const std::shared_ptr<AssignmentNode>& assignment) {
    // Check if assigned variable exists
    auto varSymbol = currentScope->lookupRecursive(assignment->variable);
    if (!varSymbol) {
        reportError(ScopeError::UndeclaredVariableAccessed,
                   "Assignment to undeclared variable '" + assignment->variable + "'");
    }
    
    // Check the value expression
    analyzeExpression(assignment->value);
}

// If Statement
void ScopeAnalyzer::analyzeIfStatement(const std::shared_ptr<IfStatementNode>& ifStmt) {
    // Analyze condition
    analyzeExpression(ifStmt->condition);
    
    // Analyze then block (creates new scope)
    if (ifStmt->thenBlock) {
        analyzeBlock(ifStmt->thenBlock);
    }
    
    // Analyze else block (creates new scope)
    if (ifStmt->elseBlock) {
        analyzeBlock(ifStmt->elseBlock);
    }
}

// While Statement
void ScopeAnalyzer::analyzeWhileStatement(const std::shared_ptr<WhileStatementNode>& whileStmt) {
    // Analyze condition
    analyzeExpression(whileStmt->condition);
    
    // Analyze body (creates new scope)
    if (whileStmt->body) {
        analyzeBlock(whileStmt->body);
    }
}

// For Statement
void ScopeAnalyzer::analyzeForStatement(const std::shared_ptr<ForStatementNode>& forStmt) {
    // For loop creates its own scope
    enterScope();
    
    // Analyze initialization (can declare variables)
    if (forStmt->initialization) {
        analyzeStatement(forStmt->initialization);
    }
    
    // Analyze condition
    if (forStmt->condition) {
        analyzeExpression(forStmt->condition);
    }
    
    // Analyze update
    if (forStmt->update) {
        analyzeStatement(forStmt->update);
    }
    
    // Analyze body (but don't create another scope - for already created one)
    if (forStmt->body) {
        for (const auto& stmt : forStmt->body->statements) {
            analyzeStatement(stmt);
        }
    }
    
    exitScope();
}

// Do-While Statement
void ScopeAnalyzer::analyzeDoWhileStatement(const std::shared_ptr<DoWhileStatementNode>& doWhileStmt) {
    // Analyze body (creates new scope)
    if (doWhileStmt->body) {
        analyzeBlock(doWhileStmt->body);
    }
    
    // Analyze condition
    analyzeExpression(doWhileStmt->condition);
}

// Switch Statement
void ScopeAnalyzer::analyzeSwitchStatement(const std::shared_ptr<SwitchStatementNode>& switchStmt) {
    // Analyze switch expression
    analyzeExpression(switchStmt->expression);
    
    // Switch creates its own scope
    enterScope();
    
    // Analyze each case
    for (const auto& caseStmt : switchStmt->cases) {
        // Analyze case value
        analyzeExpression(caseStmt->value);
        
        // Analyze case statements (no new scope - cases share scope)
        for (const auto& stmt : caseStmt->statements) {
            analyzeStatement(stmt);
        }
    }
    
    // Analyze default case
    if (switchStmt->defaultCase) {
        for (const auto& stmt : switchStmt->defaultCase->statements) {
            analyzeStatement(stmt);
        }
    }
    
    exitScope();
}

// Return Statement
void ScopeAnalyzer::analyzeReturnStatement(const std::shared_ptr<ReturnStatementNode>& returnStmt) {
    if (returnStmt->expression) {
        analyzeExpression(returnStmt->expression);
    }
}

// Print Statement
void ScopeAnalyzer::analyzePrintStatement(const std::shared_ptr<PrintStatementNode>& printStmt) {
    if (printStmt->expression) {
        analyzeExpression(printStmt->expression);
    }
}

// Function Call
void ScopeAnalyzer::analyzeFunctionCall(const std::shared_ptr<FunctionCallNode>& funcCall) {
    // Check if function is defined
    auto it = functionTable.find(funcCall->functionName);
    if (it == functionTable.end()) {
        reportError(ScopeError::UndefinedFunctionCalled,
                   "Call to undefined function '" + funcCall->functionName + "'");
    }
    
    // Analyze arguments
    for (const auto& arg : funcCall->arguments) {
        analyzeExpression(arg);
    }
}

// Identifier
void ScopeAnalyzer::analyzeIdentifier(const std::shared_ptr<IdentifierNode>& identifier) {
    // Check if variable is declared
    auto varSymbol = currentScope->lookupRecursive(identifier->name);
    if (!varSymbol) {
        reportError(ScopeError::UndeclaredVariableAccessed,
                   "Use of undeclared variable '" + identifier->name + "'");
    }
}

// Binary Operation
void ScopeAnalyzer::analyzeBinaryOp(const std::shared_ptr<BinaryOpNode>& binaryOp) {
    analyzeExpression(binaryOp->left);
    analyzeExpression(binaryOp->right);
}

// Unary Operation
void ScopeAnalyzer::analyzeUnaryOp(const std::shared_ptr<UnaryOpNode>& unaryOp) {
    analyzeExpression(unaryOp->operand);
}

// Ternary Operation
void ScopeAnalyzer::analyzeTernary(const std::shared_ptr<TernaryNode>& ternary) {
    analyzeExpression(ternary->condition);
    analyzeExpression(ternary->trueValue);
    analyzeExpression(ternary->falseValue);
}
