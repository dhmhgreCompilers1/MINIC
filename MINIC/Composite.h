#ifndef COMPOSITE_
#define COMPOSITE_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdarg.h>
using namespace std;

class CSTNode;
extern CSTNode* g_root;
extern const char* g_nodeTypeLabels[];
typedef enum nodeType {
	COMPILE_UNIT,FUNCTION_DEFINITION,FORMALARGS,STATEMENT,IF_STATEMENT,IFWITHELSE_STATEMENT,
	WHILE_STATEMENT,COMPOUND_STATEMENT,STATEMENT_LIST,EXPRESSION_NUMBER,EXPRESSION_IDENTIFIER,
	EXPRESSION_FCALL,EXPRESSION_ADD,EXPRESSION_MINUS,EXPRESSION_MULT,EXPRESSION_DIV,
    EXPRESSION_UNARYPLUS,EXPRESSION_UNARYMINUS,EXPRESSION_PAREN,EXPRESSION_ASSIGN,EXPRESSION_AND,
	EXPRESSION_OR,EXPRESSION_NOT,EXPRESSION_GT,EXPRESSION_GTE,EXPRESSION_LT,EXPRESSION_LTE,
	EXPRESSION_EQUAL,EXPRESSION_NEQUAL,ACTUALARGS
} NodeType;

class CSTNode {
public:
	CSTNode(NodeType, int, ...);
	virtual ~CSTNode();

	//  ********* QUERY METHODS **************
	NodeType GetNodeType();
	virtual string GetGraphVizLabel();
	CSTNode* GetChild(int index);
	

	// ********** MODIFIER METHODS ***********

	
protected:
	// Type of node
	NodeType m_nodeType;
	// A label that will be used to render the node in graphviz
	string m_graphvizLabel;
	int m_serial;
	// A counter counting the nodes created for giving a
	// unique serial counter
	static int ms_serialCounter;
	list<CSTNode*>* m_children;	
};

#endif