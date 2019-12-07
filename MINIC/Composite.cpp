#include "Composite.h"

// initialize static variables
CSTNode* g_root = NULL;
int CSTNode::ms_serialCounter = 0;
const char* g_nodeTypeLabels[] = { "COMPILE_UNIT","FUNCTION_DEFINITION","FORMALARGS","STATEMENT","IF_STATEMENT","IFWITHELSE_STATEMENT",
	"WHILE_STATEMENT","COMPOUND_STATEMENT","STATEMENT_LIST","EXPRESSION_NUMBER","EXPRESSION_IDENTIFIER",
	"EXPRESSION_FCALL","EXPRESSION_ADD","EXPRESSION_MINUS","EXPRESSION_MULT","EXPRESSION_DIV",
	"EXPRESSION_UNARYPLUS","EXPRESSION_UNARYMINUS","EXPRESSION_PAREN","EXPRESSION_ASSIGN","EXPRESSION_AND",
	"EXPRESSION_OR","EXPRESSION_NOT","EXPRESSION_GT","EXPRESSION_GTE","EXPRESSION_LT","EXPRESSION_LTE",
	"EXPRESSION_EQUAL","EXPRESSION_NEQUAL","ACTUALARGS" };

CSTNode::CSTNode(NodeType type, int num, ...) :m_nodeType{ type } {
	va_list argumentList;
	CSTNode* child;

	va_start(argumentList, num);

	m_serial = ms_serialCounter++;
	m_graphvizLabel = g_nodeTypeLabels[m_nodeType];
	m_children = new list<CSTNode*>();

	for (int i = 0; i < num; i++) {
		child = va_arg(argumentList, CSTNode*);
		m_children->push_back(child);
	}

	va_end(argumentList);
}

CSTNode::~CSTNode() {
	list<CSTNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); it++) {
		delete* it;
	}
	delete m_children;
}

NodeType CSTNode::GetNodeType() {
	return m_nodeType;

}
string CSTNode::GetGraphVizLabel() {
	return m_graphvizLabel + "_" + to_string(m_serial);
}

CSTNode* CSTNode::GetChild(int index) {
	list<CSTNode*>::iterator it = m_children->begin();
	advance(it, index);
	return (*it);
}


