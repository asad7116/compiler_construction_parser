#include "parser.tab.h"
#include "parser.h"
#include "lexer.h"
#include "token.h"
#include <string>
#include <memory>
#include <iostream>

extern Lexer* global_lexer;

int yylex() {
    if (!global_lexer) return 0;
    
    static std::vector<Token> tokens;
    static size_t token_index = 0;
    
    // First call: tokenize the entire input
    if (token_index == 0 && tokens.empty()) {
        tokens = global_lexer->tokenize();
    }
    
    // Return tokens one by one
    if (token_index >= tokens.size()) {
        return 0;
    }
    
    Token currentToken = tokens[token_index++];
    TokenType tokenType = currentToken.getType();
    
    // Store string values in yylval for tokens that need them
    if (tokenType == TokenType::T_IDENTIFIER || 
        tokenType == TokenType::T_INT_LITERAL ||
        tokenType == TokenType::T_FLOAT_LITERAL ||
        tokenType == TokenType::T_STRING_LITERAL ||
        tokenType == TokenType::T_CHAR_LITERAL ||
        tokenType == TokenType::T_BOOL_LITERAL ||
        tokenType == TokenType::T_NULL_LITERAL ||
        tokenType == TokenType::T_HEX_LITERAL ||
        tokenType == TokenType::T_OCTAL_LITERAL ||
        tokenType == TokenType::T_BINARY_LITERAL) {
        yylval.str_val = new std::string(currentToken.getLexeme());
    }
    
    // Return 0 for EOF
    if (tokenType == TokenType::T_EOF) {
        return 0;
    }
    
    int bisonToken = 0;
    
    // Map TokenType to Bison token numbers
    switch (tokenType) {
        case TokenType::T_IDENTIFIER: bisonToken = T_IDENTIFIER; break;
        case TokenType::T_INT_LITERAL: bisonToken = T_INT_LITERAL; break;
        case TokenType::T_FLOAT_LITERAL: bisonToken = T_FLOAT_LITERAL; break;
        case TokenType::T_STRING_LITERAL: bisonToken = T_STRING_LITERAL; break;
        case TokenType::T_CHAR_LITERAL: bisonToken = T_CHAR_LITERAL; break;
        case TokenType::T_BOOL_LITERAL: bisonToken = T_BOOL_LITERAL; break;
        case TokenType::T_NULL_LITERAL: bisonToken = T_NULL_LITERAL; break;
        case TokenType::T_HEX_LITERAL: bisonToken = T_HEX_LITERAL; break;
        case TokenType::T_OCTAL_LITERAL: bisonToken = T_OCTAL_LITERAL; break;
        case TokenType::T_BINARY_LITERAL: bisonToken = T_BINARY_LITERAL; break;
        
        // Keywords
        case TokenType::T_FUNCTION: bisonToken = T_FUNCTION; break;
        case TokenType::T_INT: bisonToken = T_INT; break;
        case TokenType::T_FLOAT: bisonToken = T_FLOAT; break;
        case TokenType::T_STRING: bisonToken = T_STRING; break;
        case TokenType::T_BOOL: bisonToken = T_BOOL; break;
        case TokenType::T_CHAR: bisonToken = T_CHAR; break;
        case TokenType::T_VOID: bisonToken = T_VOID; break;
        case TokenType::T_IF: bisonToken = T_IF; break;
        case TokenType::T_ELSE: bisonToken = T_ELSE; break;
        case TokenType::T_ELIF: bisonToken = T_ELIF; break;
        case TokenType::T_WHILE: bisonToken = T_WHILE; break;
        case TokenType::T_FOR: bisonToken = T_FOR; break;
        case TokenType::T_DO: bisonToken = T_DO; break;
        case TokenType::T_SWITCH: bisonToken = T_SWITCH; break;
        case TokenType::T_CASE: bisonToken = T_CASE; break;
        case TokenType::T_DEFAULT: bisonToken = T_DEFAULT; break;
        case TokenType::T_RETURN: bisonToken = T_RETURN; break;
        case TokenType::T_BREAK: bisonToken = T_BREAK; break;
        case TokenType::T_CONTINUE: bisonToken = T_CONTINUE; break;
        case TokenType::T_PRINT: bisonToken = T_PRINT; break;
        case TokenType::T_READ: bisonToken = T_READ; break;
        case TokenType::T_TRUE: bisonToken = T_TRUE; break;
        case TokenType::T_FALSE: bisonToken = T_FALSE; break;
        case TokenType::T_NULL: bisonToken = T_NULL; break;
        case TokenType::T_INCLUDE: bisonToken = T_INCLUDE; break;
        
        // Operators
        case TokenType::T_PLUS: bisonToken = T_PLUS; break;
        case TokenType::T_MINUS: bisonToken = T_MINUS; break;
        case TokenType::T_MULTIPLY: bisonToken = T_MULTIPLY; break;
        case TokenType::T_DIVIDE: bisonToken = T_DIVIDE; break;
        case TokenType::T_MODULO: bisonToken = T_MODULO; break;
        case TokenType::T_EQUAL: bisonToken = T_EQUAL; break;
        case TokenType::T_NOT_EQUAL: bisonToken = T_NOT_EQUAL; break;
        case TokenType::T_GREATER_THAN: bisonToken = T_GREATER_THAN; break;
        case TokenType::T_LESS_THAN: bisonToken = T_LESS_THAN; break;
        case TokenType::T_GREATER_THAN_EQUAL: bisonToken = T_GREATER_THAN_EQUAL; break;
        case TokenType::T_LESS_THAN_EQUAL: bisonToken = T_LESS_THAN_EQUAL; break;
        case TokenType::T_AND: bisonToken = T_AND; break;
        case TokenType::T_OR: bisonToken = T_OR; break;
        case TokenType::T_NOT: bisonToken = T_NOT; break;
        case TokenType::T_BIT_AND: bisonToken = T_BIT_AND; break;
        case TokenType::T_BIT_OR: bisonToken = T_BIT_OR; break;
        case TokenType::T_BIT_XOR: bisonToken = T_BIT_XOR; break;
        case TokenType::T_BIT_NOT: bisonToken = T_BIT_NOT; break;
        case TokenType::T_LEFT_SHIFT: bisonToken = T_LEFT_SHIFT; break;
        case TokenType::T_RIGHT_SHIFT: bisonToken = T_RIGHT_SHIFT; break;
        case TokenType::T_ASSIGN: bisonToken = T_ASSIGN; break;
        case TokenType::T_PLUS_ASSIGN: bisonToken = T_PLUS_ASSIGN; break;
        case TokenType::T_MINUS_ASSIGN: bisonToken = T_MINUS_ASSIGN; break;
        case TokenType::T_MULT_ASSIGN: bisonToken = T_MULT_ASSIGN; break;
        case TokenType::T_DIV_ASSIGN: bisonToken = T_DIV_ASSIGN; break;
        case TokenType::T_MOD_ASSIGN: bisonToken = T_MOD_ASSIGN; break;
        case TokenType::T_AND_ASSIGN: bisonToken = T_AND_ASSIGN; break;
        case TokenType::T_OR_ASSIGN: bisonToken = T_OR_ASSIGN; break;
        case TokenType::T_XOR_ASSIGN: bisonToken = T_XOR_ASSIGN; break;
        case TokenType::T_LSHIFT_ASSIGN: bisonToken = T_LSHIFT_ASSIGN; break;
        case TokenType::T_RSHIFT_ASSIGN: bisonToken = T_RSHIFT_ASSIGN; break;
        case TokenType::T_INCREMENT: bisonToken = T_INCREMENT; break;
        case TokenType::T_DECREMENT: bisonToken = T_DECREMENT; break;
        
        // Punctuation
        case TokenType::T_COMMA: bisonToken = T_COMMA; break;
        case TokenType::T_SEMICOLON: bisonToken = T_SEMICOLON; break;
        case TokenType::T_COLON: bisonToken = T_COLON; break;
        case TokenType::T_DOT: bisonToken = T_DOT; break;
        case TokenType::T_LPAREN: bisonToken = T_LPAREN; break;
        case TokenType::T_RPAREN: bisonToken = T_RPAREN; break;
        case TokenType::T_LBRACE: bisonToken = T_LBRACE; break;
        case TokenType::T_RBRACE: bisonToken = T_RBRACE; break;
        case TokenType::T_LBRACKET: bisonToken = T_LBRACKET; break;
        case TokenType::T_RBRACKET: bisonToken = T_RBRACKET; break;
        case TokenType::T_QUESTION: bisonToken = T_QUESTION; break;
        case TokenType::T_QUOTES: bisonToken = T_QUOTES; break;
        
        case TokenType::T_ERROR:
            std::cerr << "Lexical error: " << currentToken.getLexeme() << std::endl;
            return 0;
            
        default:
            std::cerr << "Unknown token type: " << static_cast<int>(tokenType) << std::endl;
            return 0;
    }
    
    return bisonToken;
}

// Define global_lexer
Lexer* global_lexer = nullptr;