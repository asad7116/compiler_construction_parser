/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 20 "parser.y"

    #include <memory>
    #include <vector>
    #include <string>
    #include "parser.h"
    
    struct DeclarationWrapper {
        enum Type { FUNCTION, VARIABLE, ARRAY, POINTER } type;
        void* ptr;
        DeclarationWrapper(Type t, void* p) : type(t), ptr(p) {}
    };

#line 62 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_IDENTIFIER = 258,            /* T_IDENTIFIER  */
    T_INT_LITERAL = 259,           /* T_INT_LITERAL  */
    T_FLOAT_LITERAL = 260,         /* T_FLOAT_LITERAL  */
    T_STRING_LITERAL = 261,        /* T_STRING_LITERAL  */
    T_CHAR_LITERAL = 262,          /* T_CHAR_LITERAL  */
    T_BOOL_LITERAL = 263,          /* T_BOOL_LITERAL  */
    T_NULL_LITERAL = 264,          /* T_NULL_LITERAL  */
    T_HEX_LITERAL = 265,           /* T_HEX_LITERAL  */
    T_OCTAL_LITERAL = 266,         /* T_OCTAL_LITERAL  */
    T_BINARY_LITERAL = 267,        /* T_BINARY_LITERAL  */
    T_FUNCTION = 268,              /* T_FUNCTION  */
    T_INT = 269,                   /* T_INT  */
    T_FLOAT = 270,                 /* T_FLOAT  */
    T_STRING = 271,                /* T_STRING  */
    T_BOOL = 272,                  /* T_BOOL  */
    T_CHAR = 273,                  /* T_CHAR  */
    T_VOID = 274,                  /* T_VOID  */
    T_IF = 275,                    /* T_IF  */
    T_ELSE = 276,                  /* T_ELSE  */
    T_ELIF = 277,                  /* T_ELIF  */
    T_WHILE = 278,                 /* T_WHILE  */
    T_FOR = 279,                   /* T_FOR  */
    T_DO = 280,                    /* T_DO  */
    T_SWITCH = 281,                /* T_SWITCH  */
    T_CASE = 282,                  /* T_CASE  */
    T_DEFAULT = 283,               /* T_DEFAULT  */
    T_RETURN = 284,                /* T_RETURN  */
    T_BREAK = 285,                 /* T_BREAK  */
    T_CONTINUE = 286,              /* T_CONTINUE  */
    T_PRINT = 287,                 /* T_PRINT  */
    T_READ = 288,                  /* T_READ  */
    T_TRUE = 289,                  /* T_TRUE  */
    T_FALSE = 290,                 /* T_FALSE  */
    T_NULL = 291,                  /* T_NULL  */
    T_INCLUDE = 292,               /* T_INCLUDE  */
    T_PLUS = 293,                  /* T_PLUS  */
    T_MINUS = 294,                 /* T_MINUS  */
    T_MULTIPLY = 295,              /* T_MULTIPLY  */
    T_DIVIDE = 296,                /* T_DIVIDE  */
    T_MODULO = 297,                /* T_MODULO  */
    T_EQUAL = 298,                 /* T_EQUAL  */
    T_NOT_EQUAL = 299,             /* T_NOT_EQUAL  */
    T_GREATER_THAN = 300,          /* T_GREATER_THAN  */
    T_LESS_THAN = 301,             /* T_LESS_THAN  */
    T_GREATER_THAN_EQUAL = 302,    /* T_GREATER_THAN_EQUAL  */
    T_LESS_THAN_EQUAL = 303,       /* T_LESS_THAN_EQUAL  */
    T_AND = 304,                   /* T_AND  */
    T_OR = 305,                    /* T_OR  */
    T_NOT = 306,                   /* T_NOT  */
    T_BIT_AND = 307,               /* T_BIT_AND  */
    T_BIT_OR = 308,                /* T_BIT_OR  */
    T_BIT_XOR = 309,               /* T_BIT_XOR  */
    T_BIT_NOT = 310,               /* T_BIT_NOT  */
    T_LEFT_SHIFT = 311,            /* T_LEFT_SHIFT  */
    T_RIGHT_SHIFT = 312,           /* T_RIGHT_SHIFT  */
    T_ASSIGN = 313,                /* T_ASSIGN  */
    T_PLUS_ASSIGN = 314,           /* T_PLUS_ASSIGN  */
    T_MINUS_ASSIGN = 315,          /* T_MINUS_ASSIGN  */
    T_MULT_ASSIGN = 316,           /* T_MULT_ASSIGN  */
    T_DIV_ASSIGN = 317,            /* T_DIV_ASSIGN  */
    T_MOD_ASSIGN = 318,            /* T_MOD_ASSIGN  */
    T_AND_ASSIGN = 319,            /* T_AND_ASSIGN  */
    T_OR_ASSIGN = 320,             /* T_OR_ASSIGN  */
    T_XOR_ASSIGN = 321,            /* T_XOR_ASSIGN  */
    T_LSHIFT_ASSIGN = 322,         /* T_LSHIFT_ASSIGN  */
    T_RSHIFT_ASSIGN = 323,         /* T_RSHIFT_ASSIGN  */
    T_INCREMENT = 324,             /* T_INCREMENT  */
    T_DECREMENT = 325,             /* T_DECREMENT  */
    T_COMMA = 326,                 /* T_COMMA  */
    T_SEMICOLON = 327,             /* T_SEMICOLON  */
    T_COLON = 328,                 /* T_COLON  */
    T_DOT = 329,                   /* T_DOT  */
    T_LPAREN = 330,                /* T_LPAREN  */
    T_RPAREN = 331,                /* T_RPAREN  */
    T_LBRACE = 332,                /* T_LBRACE  */
    T_RBRACE = 333,                /* T_RBRACE  */
    T_LBRACKET = 334,              /* T_LBRACKET  */
    T_RBRACKET = 335,              /* T_RBRACKET  */
    T_QUESTION = 336,              /* T_QUESTION  */
    T_QUOTES = 337,                /* T_QUOTES  */
    UNARY = 338                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "parser.y"

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

#line 184 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
