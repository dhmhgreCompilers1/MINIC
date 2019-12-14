%option noyywrap

%{
#include <iostream>
#include <cstdlib>
#include "MINIC.tab.h"
#include "CompositeConcrete.h"
#include "SymbolTable.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval ,yy::parser::location_type *yylloc)
typedef yy::parser::token token;
// make location include the current token
# define YY_USER_ACTION yylloc->columns(yyleng);
%}
INT "0"|[1-9][0-9]*
%%
%{
// start where previous token ended
yylloc->step ();
%}


"if"			{ return token::IF;}
"else"			{ return token::ELSE; }
"return"		{ return token::RETURN; }
"break"			{ return token::BREAK; }
"while"			{ return token::WHILE; }
"function"		{ return token::FUNCTION; }

"("				{ return '(';}
")"				{ return ')';}
"{"				{ return '{';}
"}"				{ return '}';}
";"				{ return ';';}
","				{ return ',';}
"+"				{ return token::PLUS;}
"-"				{ return token::MINUS;}
"*"				{ return token::MULT;}
"/"				{ return token::DIV;}
"&&"			{ return token::AND;}
"||"			{ return token::OR;}
"!"				{ return token::NOT;}
"<"				{ return token::LT;}
">"				{ return token::GT;}
">="			{ return token::GTE;}
"<="			{ return token::LTE;}
"=="			{ return token::EQUAL;}
"!="			{ return token::NEQUAL;}
"="				{ return '=';}

({INT}?\.{INT})|({INT}\.{INT}?)		{	yylval->node = new CExpressionNUMBER(yytext,atof(yytext));
										return token::NUMBER; }
{INT}								{   yylval->node = new CExpressionNUMBER(yytext,(double)atoi(yytext));
										return token::NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*				{   yylval->node = g_symbolTable.GetSymbol(yytext)->Idnode;
										return token::IDENTIFIER; }

[ \t]									{ yylloc->step (); }
[\r\n]									{ yylloc->lines(1);}
%%