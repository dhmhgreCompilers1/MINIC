#ifndef SYMBOLTABLE_
#define SYMBOLTABLE_

#include "CompositeConcrete.h"
#include <map>
#include <optional>
using namespace std;

class SymbolTable {
	map<string, CSTNode*>* m_symbolTable;
public:
	SymbolTable() {
		m_symbolTable = new map<string, CSTNode*>();
	}
	virtual ~SymbolTable() {}

	CSTNode* GetSymbol(string);
};

extern SymbolTable g_symbolTable;



#endif

