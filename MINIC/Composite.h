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
	NT_COMPILEUNIT, NT_FUNCTIONDEFINITION, NT_FORMALARGS, NT_ACTUALARGS, NT_EXPRESSIONSTATEMENT,
	NT_COMPOUNDSTATEMENT, NT_IFSTATEMENT, NT_WHILESTATEMENT, NT_RETURNSTATEMENT,NT_BREAKSTATEMENT,
	NT_NULLSTATEMENT,
	NT_STATEMENTLIST, NT_EXPRESSION_NUMBER, NT_EXPRESSION_IDENTIFIER, NT_EXPRESSION_FCALL,
	NT_EXPRESSION_ADD, NT_EXPRESSION_MINUS, NT_EXPRESSION_MULT, NT_EXPRESSION_DIV,
	NT_EXPRESSION_UNARYPLUS, NT_EXPRESSION_UNARYMINUS, NT_EXPRESSION_ASSIGN, NT_EXPRESSION_AND,
	NT_EXPRESSION_OR, NT_EXPRESSION_NOT, NT_EXPRESSION_GT, NT_EXPRESSION_GTE, NT_EXPRESSION_LT,
	NT_EXPRESSION_LTE, NT_EXPRESSION_EQUAL, NT_EXPRESSION_NEQUAL
} NodeType;

class CSTNode {
public:
	CSTNode(NodeType, int, ...);
	virtual ~CSTNode();

	//  ********* QUERY METHODS **************
	NodeType GetNodeType();
	virtual string GetGraphVizLabel();
	CSTNode* GetChild(int index);
	virtual void PrintSyntaxTree(ofstream* dotfile,CSTNode *parent);
	virtual double Evaluate(CSTNode* parent);
	virtual double AggregateResult(double result);

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