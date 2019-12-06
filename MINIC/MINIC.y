%language "C++"

%{
#include <iostream>
#include "MINIC.tab.h"

using namespace std;
extern int yylex(yy::parser::semantic_type *yylval);
extern FILE *yyin;
%}

%error-verbose

%start explist

%%

explist:;

%%

namespace yy{
	void parser::error(yy::location const &loc, const string &message){
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}