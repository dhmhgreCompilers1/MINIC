%language "C++"

%{
#include <iostream>
#include "MINIC.tab.h"

using namespace std;
extern int yylex(yy::parser::semantic_type *yylval);
extern FILE *yyin;
%}
%verbose
%error-verbose

%start compile_unit
%token IDENTIFIER NUMBER
%token RETURN BREAK IF ELSE WHILE FUNCTION 
%nonassoc IFPREC
%left '='
%left OR
%left AND
%nonassoc GTE GT LTE LT EQUAL NEQUAL
%left PLUS MINUS
%left MULT DIV
%nonassoc NOT ELSE
%%

compile_unit: statement ';'
			| compile_unit statement ';'
			| function_definition ';'
			| compile_unit function_definition ';'
			;

function_definition : FUNCTION IDENTIFIER '(' fargs ')' compound_statement
				;

fargs : IDENTIFIER
		| fargs IDENTIFIER
		;

statement : expression ';'
		  | compound_statement
		  | if_statement
		  | while_statement
		  | RETURN expression ';'
		  | BREAK ';'
		  | ';'

if_statement : IF '(' expression ')' statement %prec IFPREC
			| IF '(' expression ')' statement ELSE statement
			;

while_statement : WHILE '(' expression ')' statement
			;

compound_statement : '{' '}'
					| '{' statement_list '}'
					;
statement_list : statement
			   | statement_list statement
			   ;

expression: NUMBER
		  | IDENTIFIER
		  | IDENTIFIER '(' ')'
		  | IDENTIFIER '(' args ')'
		  | expression PLUS expression
		  | expression MINUS expression
		  | expression MULT expression
		  | expression DIV expression
		  | PLUS expression
		  | MINUS expression
		  | '(' expression ')'
		  | IDENTIFIER '=' expression
		  | expression AND expression
		  | expression OR expression
		  | NOT expression
		  | expression GT expression
		  | expression GTE expression
		  | expression LT expression
		  | expression LTE expression
		  | expression EQUAL expression
		  | expression NEQUAL expression
		  ;
args : expression
	 | args ',' expression
	 ;
%%

namespace yy{
	void parser::error(yy::location const &loc, const string &message){
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}