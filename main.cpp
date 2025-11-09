#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "parser.tab.h"
#include "parser.h"
#include "ast_printer.h"
#include "scope_analyzer.h"

extern Lexer* global_lexer;
extern std::shared_ptr<ProgramNode> program_root;
extern int yyparse();

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <source_file>" << std::endl;
        return 1;
    }

    // First, debug the lexer output
    std::cout << "=== LEXER DEBUG ===" << std::endl;
    Lexer debug_lexer(argv[1], true);
    std::vector<Token> tokens = debug_lexer.tokenize();
    
    std::cout << "Total tokens: " << tokens.size() << std::endl;
    for (const Token& tok : tokens) {
        std::cout << tok.toString() << std::endl;
    }
    std::cout << "===================" << std::endl << std::endl;

    // Now parse
    Lexer lexer(argv[1], true);
    global_lexer = &lexer;

    std::cout << "Parsing..." << std::endl;
    int result = yyparse();

    if (result == 0) {
        std::cout << "Parsing successful!" << std::endl;
        
        if (program_root) {
            std::cout << "\n=== PROGRAM SUMMARY ===" << std::endl;
            std::cout << "Functions: " << program_root->functions.size() << std::endl;
            std::cout << "Global Variables: " << program_root->globalVariables.size() << std::endl;
            std::cout << "======================\n" << std::endl;
            
            // Print detailed AST
            ASTPrinter printer;
            printer.print(program_root);
            
            // Print function details
            for (const auto& func : program_root->functions) {
                std::cout << "Function: " << func->name 
                         << " (return type: " << func->returnType << ")" << std::endl;
                std::cout << "  Parameters: " << func->parameters.size() << std::endl;
                for (const auto& param : func->parameters) {
                    std::cout << "    - " << param->type << " " << param->name << std::endl;
                }
                std::cout << "  Body statements: " 
                         << (func->body ? func->body->statements.size() : 0) << std::endl;
                std::cout << std::endl;
            }
            
            // ===== SCOPE ANALYSIS PHASE =====
            std::cout << "\n=== SCOPE ANALYSIS ===" << std::endl;
            ScopeAnalyzer scopeAnalyzer;
            bool scopeSuccess = scopeAnalyzer.analyze(program_root);
            
            // Print scope analysis results
            scopeAnalyzer.printErrors();
            
            if (scopeSuccess) {
                std::cout << "\n";
                scopeAnalyzer.printSymbolTables();
            } else {
                std::cerr << "\nScope analysis failed! Cannot proceed to type checking." << std::endl;
                return 1;
            }
            std::cout << "======================\n" << std::endl;
            
        } else {
            std::cerr << "Warning: program_root is null!" << std::endl;
        }
    } else {
        std::cerr << "Parsing failed!" << std::endl;
        return 1;
    }

    return 0;
}


