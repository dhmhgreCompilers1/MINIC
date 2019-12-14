#include "SymbolTable.h"
#include "CompositeConcrete.h"
SymbolTable g_symbolTable;
Symbol* SymbolTable::GetSymbol(string textKey) {
	Symbol* symbol;
	map<string, Symbol*>::iterator it;
	it = m_symbolTable->find(textKey);
	if (it == m_symbolTable->end()) {
		symbol = new Symbol{ textKey,0,new CIDENTIFIER(textKey.c_str()) };
		(*m_symbolTable)[textKey] = symbol;
		return  symbol;
	}
	else {
		return (*m_symbolTable)[textKey];
	}
}
