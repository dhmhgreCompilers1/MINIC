#include "SymbolTable.h"
SymbolTable g_symbolTable;
CSTNode* SymbolTable::GetSymbol(string textKey) {
	CSTNode* symbol;
	map<string, CSTNode*>::iterator it;
	it = m_symbolTable->find(textKey);
	if (it == m_symbolTable->end()) {
		symbol = new CExpressionIDENTIFIER(textKey.c_str());
		(*m_symbolTable)[textKey] = symbol;
		return  symbol;
	}
	else {
		return (*m_symbolTable)[textKey];
	}
}