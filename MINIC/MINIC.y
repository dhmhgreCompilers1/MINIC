%language "C++"

%{
#include <iostream>
#include "MINIC.tab.h"

using namespace std;
extern int yylex(yy::parser::semantic_type *yylval ,yy::parser::location_type *yylloc);
extern FILE *yyin;

%}
%verbose
%locations

%initial-action {
// Filename for locations here
@$.begin.filename = @$.end.filename = new std::string("test.txt");
}

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

compile_unit: statement								// COMPILE_UNIT
			| compile_unit statement				// COMPILE_UNIT
			| function_definition					// COMPILE_UNIT
			| compile_unit function_definition		// COMPILE_UNIT
			;

function_definition : FUNCTION IDENTIFIER '(' fargs ')' compound_statement   // FUNCTION_DEFINITION
				;

fargs : IDENTIFIER				// FORMALARGS
		| fargs IDENTIFIER	    // FORMALARGS
		;

statement : expression ';'			// STATEMENT
		  | compound_statement		// STATEMENT
		  | if_statement			// STATEMENT
		  | while_statement			// STATEMENT
		  | RETURN expression ';'	// STATEMENT
		  | BREAK ';'				// STATEMENT
		  | ';'						// STATEMENT

if_statement : IF '(' expression ')' statement %prec IFPREC		// IF_STATEMENT
			| IF '(' expression ')' statement ELSE statement    // IFWITHELSE_STATEMENT
			;

while_statement : WHILE '(' expression ')' statement	// WHILE_STATEMENT
			;

compound_statement : '{' '}'					//COMPOUND_STATEMENT
					| '{' statement_list '}'	//COMPOUND_STATEMENT
					;
statement_list : statement						// STATEMENT_LIST
			   | statement_list statement		// STATEMENT_LIST
			   ;

expression: NUMBER								// EXPRESSION_NUMBER
		  | IDENTIFIER							// EXPRESSION_IDENTIFIER
		  | IDENTIFIER '(' ')'					// EXPRESSION_FCALL
		  | IDENTIFIER '(' args ')'				// EXPRESSION_FCALL
		  | expression PLUS expression			// EXPRESSION_ADD
		  | expression MINUS expression			// EXPRESSION_MINUS
		  | expression MULT expression			// EXPRESSION_MULT
		  | expression DIV expression			// EXPRESSION_DIV
		  | PLUS expression						// EXPRESSION_UNARYPLUS
		  | MINUS expression					// EXPRESSION_UNARYMINUS
		  | '(' expression ')'					// EXPRESSION_PAREN
		  | IDENTIFIER '=' expression			// EXPRESSION_ASSIGN
		  | expression AND expression			// EXPRESSION_AND
		  | expression OR expression			// EXPRESSION_OR
		  | NOT expression						// EXPRESSION_NOT
		  | expression GT expression			// EXPRESSION_GT	
		  | expression GTE expression			// EXPRESSION_GTE
		  | expression LT expression			// EXPRESSION_LT
		  | expression LTE expression			// EXPRESSION_LTE
		  | expression EQUAL expression			// EXPRESSION_EQUAL
		  | expression NEQUAL expression		// EXPRESSION_NEQUAL	
		  ;
args : expression				// ACTUALARGS
	 | args ',' expression		// ACTUALARGS
	 ;
%%

namespace yy{
	void parser::error(yy::location const &loc, const string &message){
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}