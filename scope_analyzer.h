#ifndef SCOPE_ANALYZER_H
#define SCOPE_ANALYZER_H

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include <iostream>
#include "parser.h"

// Scope Error Types (following Rust-like enum naming)
enum class ScopeError {
    UndeclaredVariableAccessed,
    UndefinedFunctionCalled,
    VariableRedefinition,
    FunctionPrototypeRedefinition
};

// Convert scope error to string
inline std::string scopeErrorToString(ScopeError error) {
    switch (error) {
        case ScopeError::UndeclaredVariableAccessed:
            return "UndeclaredVariableAccessed";
        case ScopeError::UndefinedFunctionCalled:
            return "UndefinedFunctionCalled";
        case ScopeError::VariableRedefinition:
            return "VariableRedefinition";
        case ScopeError::FunctionPrototypeRedefinition:
            return "FunctionPrototypeRedefinition";
        default:
            return "UnknownError";
    }
}

// Symbol Table Entry for Variables
struct VariableSymbol {
    std::string name;
    std::string type;
    int scopeLevel;
    bool isParameter;
    
    VariableSymbol(const std::string& n, const std::string& t, int level, bool isParam = false)
        : name(n), type(t), scopeLevel(level), isParameter(isParam) {}
};

// Symbol Table Entry for Functions
struct FunctionSymbol {
    std::string name;
    std::string returnType;
    std::vector<std::string> parameterTypes;
    std::vector<std::string> parameterNames;
    bool isDefined;
    
    FunctionSymbol(const std::string& n, const std::string& retType)
        : name(n), returnType(retType), isDefined(false) {}
    
    void addParameter(const std::string& type, const std::string& name) {
        parameterTypes.push_back(type);
        parameterNames.push_back(name);
    }
};

// Spaghetti Stack Node
// Each node represents a scope and points to its parent scope
class ScopeNode {
public:
    int level;
    std::shared_ptr<ScopeNode> parent;
    std::unordered_map<std::string, std::shared_ptr<VariableSymbol>> variables;
    
    ScopeNode(int lvl, std::shared_ptr<ScopeNode> par = nullptr)
        : level(lvl), parent(par) {}
    
    // Look up a variable in this scope
    std::shared_ptr<VariableSymbol> lookup(const std::string& name) {
        auto it = variables.find(name);
        if (it != variables.end()) {
            return it->second;
        }
        return nullptr;
    }
    
    // Look up a variable in this scope or any parent scope
    std::shared_ptr<VariableSymbol> lookupRecursive(const std::string& name) {
        auto result = lookup(name);
        if (result) {
            return result;
        }
        if (parent) {
            return parent->lookupRecursive(name);
        }
        return nullptr;
    }
    
    // Declare a variable in this scope
    bool declare(const std::string& name, const std::string& type, bool isParam = false) {
        // Check if already declared in THIS scope (redefinition error)
        if (variables.find(name) != variables.end()) {
            return false; // Already declared in this scope
        }
        
        variables[name] = std::make_shared<VariableSymbol>(name, type, level, isParam);
        return true;
    }
};

// Scope Analyzer Class
class ScopeAnalyzer {
private:
    // Current scope (top of the spaghetti stack)
    std::shared_ptr<ScopeNode> currentScope;
    
    // Global function table (file-scoped)
    std::unordered_map<std::string, std::shared_ptr<FunctionSymbol>> functionTable;
    
    // Error tracking
    std::vector<std::pair<ScopeError, std::string>> errors;
    
    // Current scope level
    int scopeLevel;
    
    // Helper to enter a new scope
    void enterScope() {
        scopeLevel++;
        currentScope = std::make_shared<ScopeNode>(scopeLevel, currentScope);
    }
    
    // Helper to exit current scope
    void exitScope() {
        if (currentScope && currentScope->parent) {
            currentScope = currentScope->parent;
            scopeLevel--;
        }
    }
    
    // Report an error
    void reportError(ScopeError error, const std::string& details) {
        errors.push_back({error, details});
    }
    
    // Analyze nodes
    void analyzeProgram(const std::shared_ptr<ProgramNode>& program);
    void analyzeFunction(const std::shared_ptr<FunctionNode>& function);
    void analyzeBlock(const std::shared_ptr<BlockNode>& block);
    void analyzeStatement(const std::shared_ptr<StatementNode>& statement);
    void analyzeExpression(const std::shared_ptr<ExpressionNode>& expression);
    
    // Specific node analyzers
    void analyzeVariableDeclaration(const std::shared_ptr<VariableDeclarationNode>& varDecl);
    void analyzeAssignment(const std::shared_ptr<AssignmentNode>& assignment);
    void analyzeIfStatement(const std::shared_ptr<IfStatementNode>& ifStmt);
    void analyzeWhileStatement(const std::shared_ptr<WhileStatementNode>& whileStmt);
    void analyzeForStatement(const std::shared_ptr<ForStatementNode>& forStmt);
    void analyzeDoWhileStatement(const std::shared_ptr<DoWhileStatementNode>& doWhileStmt);
    void analyzeSwitchStatement(const std::shared_ptr<SwitchStatementNode>& switchStmt);
    void analyzeReturnStatement(const std::shared_ptr<ReturnStatementNode>& returnStmt);
    void analyzePrintStatement(const std::shared_ptr<PrintStatementNode>& printStmt);
    void analyzeFunctionCall(const std::shared_ptr<FunctionCallNode>& funcCall);
    void analyzeIdentifier(const std::shared_ptr<IdentifierNode>& identifier);
    void analyzeBinaryOp(const std::shared_ptr<BinaryOpNode>& binaryOp);
    void analyzeUnaryOp(const std::shared_ptr<UnaryOpNode>& unaryOp);
    void analyzeTernary(const std::shared_ptr<TernaryNode>& ternary);
    
public:
    ScopeAnalyzer() : currentScope(nullptr), scopeLevel(-1) {}
    
    // Main analysis entry point
    bool analyze(const std::shared_ptr<ProgramNode>& program);
    
    // Get errors
    const std::vector<std::pair<ScopeError, std::string>>& getErrors() const {
        return errors;
    }
    
    // Check if analysis was successful
    bool hasErrors() const {
        return !errors.empty();
    }
    
    // Print errors
    void printErrors() const {
        if (errors.empty()) {
            std::cout << "✓ Scope analysis passed: No scope errors detected." << std::endl;
        } else {
            std::cout << "✗ Scope analysis failed with " << errors.size() << " error(s):" << std::endl;
            for (const auto& error : errors) {
                std::cout << "  [" << scopeErrorToString(error.first) << "] " 
                         << error.second << std::endl;
            }
        }
    }
    
    // Print symbol tables (for debugging)
    void printSymbolTables() const {
        std::cout << "\n=== SYMBOL TABLES ===" << std::endl;
        
        std::cout << "Functions:" << std::endl;
        for (const auto& [name, func] : functionTable) {
            std::cout << "  " << func->returnType << " " << func->name << "(";
            for (size_t i = 0; i < func->parameterTypes.size(); i++) {
                if (i > 0) std::cout << ", ";
                std::cout << func->parameterTypes[i] << " " << func->parameterNames[i];
            }
            std::cout << ")" << std::endl;
        }
        
        std::cout << "=====================" << std::endl;
    }
};

#endif // SCOPE_ANALYZER_H
