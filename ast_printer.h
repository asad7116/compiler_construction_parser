#ifndef AST_PRINTER_H
#define AST_PRINTER_H

#include "parser.h"
#include <iostream>
#include <string>

class ASTPrinter {
private:
    int indentLevel = 0;
    
    void printIndent() {
        for (int i = 0; i < indentLevel; i++) {
            std::cout << "  ";
        }
    }
    
    void printExpression(const std::shared_ptr<ExpressionNode>& expr) {
        if (!expr) {
            std::cout << "<null>";
            return;
        }
        
        if (auto lit = std::dynamic_pointer_cast<LiteralNode>(expr)) {
            std::cout << "Literal(" << lit->type << ": " << lit->value << ")";
        } else if (auto id = std::dynamic_pointer_cast<IdentifierNode>(expr)) {
            std::cout << "Identifier(" << id->name << ")";
        } else if (auto bin = std::dynamic_pointer_cast<BinaryOpNode>(expr)) {
            std::cout << "BinaryOp(" << bin->op << ")" << std::endl;
            printIndent();
            std::cout << "  Left: ";
            printExpression(bin->left);
            std::cout << std::endl;
            printIndent();
            std::cout << "  Right: ";
            printExpression(bin->right);
        } else if (auto tern = std::dynamic_pointer_cast<TernaryNode>(expr)) {
            std::cout << "Ternary(?:)" << std::endl;
            printIndent();
            std::cout << "  Condition: ";
            printExpression(tern->condition);
            std::cout << std::endl;
            printIndent();
            std::cout << "  True: ";
            printExpression(tern->trueValue);
            std::cout << std::endl;
            printIndent();
            std::cout << "  False: ";
            printExpression(tern->falseValue);
        } else if (auto unary = std::dynamic_pointer_cast<UnaryOpNode>(expr)) {
            std::cout << "UnaryOp(" << unary->op << ") ";
            printExpression(unary->operand);
        } else if (auto call = std::dynamic_pointer_cast<FunctionCallNode>(expr)) {
            std::cout << "FunctionCall(" << call->functionName << ")";
            if (!call->arguments.empty()) {
                std::cout << " with " << call->arguments.size() << " args";
            }
        } else if (auto arr = std::dynamic_pointer_cast<ArrayAccessNode>(expr)) {
            std::cout << "ArrayAccess(" << arr->arrayName << "[";
            printExpression(arr->index);
            std::cout << "])";
        } else {
            std::cout << "<expression>";
        }
    }
    
    void printBlock(const std::shared_ptr<BlockNode>& block, const std::string& prefix = "") {
        if (!block) {
            printIndent();
            std::cout << prefix << "<null block>" << std::endl;
            return;
        }
        
        printIndent();
        std::cout << prefix << "Block {" << std::endl;
        indentLevel++;
        for (const auto& s : block->statements) {
            printStatement(s);
        }
        indentLevel--;
        printIndent();
        std::cout << "}" << std::endl;
    }
    
    void printStatement(const std::shared_ptr<StatementNode>& stmt, const std::string& prefix = "") {
        printIndent();
        std::cout << prefix;
        
        if (!stmt) {
            std::cout << "<empty>" << std::endl;
            return;
        }
        
        if (auto varDecl = std::dynamic_pointer_cast<VariableDeclarationNode>(stmt)) {
            std::cout << "VarDecl: " << varDecl->type << " " << varDecl->name;
            if (varDecl->initializer) {
                std::cout << " = ";
                printExpression(varDecl->initializer);
            }
            std::cout << std::endl;
        } else if (auto ret = std::dynamic_pointer_cast<ReturnStatementNode>(stmt)) {
            std::cout << "Return: ";
            if (ret->expression) {
                printExpression(ret->expression);
            }
            std::cout << std::endl;
        } else if (auto assign = std::dynamic_pointer_cast<AssignmentNode>(stmt)) {
            std::cout << "Assignment: " << assign->variable << " = ";
            printExpression(assign->value);
            std::cout << std::endl;
        } else if (auto ifStmt = std::dynamic_pointer_cast<IfStatementNode>(stmt)) {
            std::cout << "If: ";
            printExpression(ifStmt->condition);
            std::cout << std::endl;
            indentLevel++;
            printBlock(ifStmt->thenBlock, "Then: ");
            if (ifStmt->elseBlock) {
                printBlock(ifStmt->elseBlock, "Else: ");
            }
            indentLevel--;
        } else if (auto whileStmt = std::dynamic_pointer_cast<WhileStatementNode>(stmt)) {
            std::cout << "While: ";
            printExpression(whileStmt->condition);
            std::cout << std::endl;
            indentLevel++;
            printBlock(whileStmt->body, "Body: ");
            indentLevel--;
        } else if (auto forStmt = std::dynamic_pointer_cast<ForStatementNode>(stmt)) {
            std::cout << "For:" << std::endl;
            indentLevel++;
            if (forStmt->initialization) {
                printStatement(forStmt->initialization, "Init: ");
            }
            printIndent();
            std::cout << "Condition: ";
            printExpression(forStmt->condition);
            std::cout << std::endl;
            if (forStmt->update) {
                printStatement(forStmt->update, "Update: ");
            }
            printBlock(forStmt->body, "Body: ");
            indentLevel--;
        } else if (auto switchStmt = std::dynamic_pointer_cast<SwitchStatementNode>(stmt)) {
            std::cout << "Switch: ";
            printExpression(switchStmt->expression);
            std::cout << std::endl;
            indentLevel++;
            for (const auto& caseStmt : switchStmt->cases) {
                printIndent();
                std::cout << "Case: ";
                printExpression(caseStmt->value);
                std::cout << std::endl;
                indentLevel++;
                for (const auto& s : caseStmt->statements) {
                    printStatement(s);
                }
                indentLevel--;
            }
            if (switchStmt->defaultCase) {
                printIndent();
                std::cout << "Default:" << std::endl;
                indentLevel++;
                for (const auto& s : switchStmt->defaultCase->statements) {
                    printStatement(s);
                }
                indentLevel--;
            }
            indentLevel--;
        } else if (auto breakStmt = std::dynamic_pointer_cast<BreakStatementNode>(stmt)) {
            std::cout << "Break" << std::endl;
        } else if (auto continueStmt = std::dynamic_pointer_cast<ContinueStatementNode>(stmt)) {
            std::cout << "Continue" << std::endl;
        } else if (auto printStmt = std::dynamic_pointer_cast<PrintStatementNode>(stmt)) {
            std::cout << "Print: ";
            printExpression(printStmt->expression);
            std::cout << std::endl;
        } else if (auto arrayDecl = std::dynamic_pointer_cast<ArrayDeclarationNode>(stmt)) {
            std::cout << "ArrayDecl: " << arrayDecl->type << " " << arrayDecl->name;
            if (arrayDecl->size) {
                std::cout << "[";
                printExpression(arrayDecl->size);
                std::cout << "]";
            }
            if (arrayDecl->initializer) {
                std::cout << " = {...}";
            }
            std::cout << std::endl;
        } else if (auto ptrDecl = std::dynamic_pointer_cast<PointerDeclarationNode>(stmt)) {
            std::cout << "PointerDecl: " << ptrDecl->baseType << "* " << ptrDecl->name;
            if (ptrDecl->initializer) {
                std::cout << " = ";
                printExpression(ptrDecl->initializer);
            }
            std::cout << std::endl;
        } else {
            std::cout << "<unknown statement>" << std::endl;
        }
    }
    
public:
    void print(const std::shared_ptr<ProgramNode>& program) {
        std::cout << "\n=== ABSTRACT SYNTAX TREE ===" << std::endl;
        
        if (!program) {
            std::cout << "Program is null!" << std::endl;
            return;
        }
        
        std::cout << "Program" << std::endl;
        indentLevel++;
        
        // Print global variables
        if (!program->globalVariables.empty()) {
            printIndent();
            std::cout << "Global Variables:" << std::endl;
            indentLevel++;
            for (const auto& var : program->globalVariables) {
                printStatement(var);
            }
            indentLevel--;
        }
        
        // Print functions
        if (!program->functions.empty()) {
            printIndent();
            std::cout << "Functions:" << std::endl;
            indentLevel++;
            for (const auto& func : program->functions) {
                printIndent();
                std::cout << "Function: " << func->returnType << " " << func->name << "(";
                for (size_t i = 0; i < func->parameters.size(); i++) {
                    if (i > 0) std::cout << ", ";
                    std::cout << func->parameters[i]->type << " " << func->parameters[i]->name;
                }
                std::cout << ")" << std::endl;
                
                if (func->body) {
                    indentLevel++;
                    printBlock(func->body, "Body: ");
                    indentLevel--;
                }
            }
            indentLevel--;
        }
        
        indentLevel--;
        std::cout << "============================\n" << std::endl;
    }
};

#endif