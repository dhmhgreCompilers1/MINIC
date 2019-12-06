#include <iostream>
#include <fstream>
#include "MINIC.tab.h"
extern FILE* yyin;
using namespace std;


void main(int argc, char** argv) {

	ofstream* dotfile;
	fopen_s(&yyin, "test.txt", "r");
	yy::parser* p = new yy::parser();
	p->parse();
	cout << "Finished!!!";

}