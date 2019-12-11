#include "CompositeConcrete.h"

CCompileUnit::CCompileUnit(CSTNode* arg1, CSTNode* arg2): CSTNode(NT_COMPILEUNIT,2,arg1,arg2) {}
CCompileUnit::CCompileUnit(CSTNode* arg1) :CSTNode(NT_COMPILEUNIT,1,arg1) {}
CFunctionDefinition::CFunctionDefinition(CSTNode* id, CSTNode* fargs, CSTNode* compoundst) :CSTNode(NT_FUNCTIONDEFINITION,3,id,fargs,compoundst){}
CFunctionDefinition::CFunctionDefinition(CSTNode* id, CSTNode* compoundst):CSTNode(NT_FUNCTIONDEFINITION,2,id,compoundst) {}
CFormalArgs::CFormalArgs(CSTNode* fargs, CSTNode* id) :CSTNode(NT_FORMALARGS,2,fargs,id){}
CFormalArgs::CFormalArgs(CSTNode* id):CSTNode(NT_FORMALARGS,1,id) {}
CActualArgs::CActualArgs(CSTNode* actargs, CSTNode* expr) :CSTNode(NT_ACTUALARGS,2,actargs,expr) {}
CActualArgs::CActualArgs(CSTNode* expr):CSTNode(NT_ACTUALARGS,1,expr) {}
CStatement::CStatement(NodeType tp, int children, CSTNode* arg) :CSTNode(tp,children,arg){}
CStatement::CStatement(NodeType tp, int children) : CSTNode(tp, children) {}
CStatement::CStatement(NodeType tp, int children, CSTNode* arg1, CSTNode* arg2) : CSTNode(tp, children, arg1,arg2){}
CStatement::CStatement(NodeType tp, int children, CSTNode* arg1, CSTNode* arg2, CSTNode* arg3) : CSTNode(tp, children, arg1,arg2,arg3) {} 
CStatement::CStatement(NodeType tp):CSTNode(tp,0) {}
CExpressionStatement::CExpressionStatement(CSTNode* arg):CStatement(NT_EXPRESSIONSTATEMENT,1,arg) {}
CCompoundStatement::CCompoundStatement(CSTNode* arg):CStatement(NT_COMPOUNDSTATEMENT,1,arg) {}
CIfStatement::CIfStatement(CSTNode* cond, CSTNode* ifpath, CSTNode* elsepath) :CStatement(NT_IFSTATEMENT,3,cond,ifpath,elsepath){}
CIfStatement::CIfStatement(CSTNode* cond, CSTNode* ifpath) :CStatement(NT_IFSTATEMENT,2,cond,ifpath) {}
CWhileStatement::CWhileStatement(CSTNode* cond, CSTNode* body) :CStatement(NT_WHILESTATEMENT,2,cond,body) {}
CReturnStatement::CReturnStatement(CSTNode* expr) :CStatement(NT_RETURNSTATEMENT,1,expr) {}
CBreakStatement::CBreakStatement() :CStatement(NT_BREAKSTATEMENT,0) {}
CNullStatement::CNullStatement() : CStatement(NT_EXPRESSION_NUMBER, 0) {}
CStatementList::CStatementList(CSTNode* arg1, CSTNode* arg2) :CSTNode(NT_STATEMENTLIST,2,arg1,arg2){}
CStatementList::CStatementList(CSTNode* arg1) : CSTNode(NT_STATEMENTLIST, 1, arg1) {}
CExpression::CExpression(NodeType tp, int children, CSTNode* arg1, CSTNode* arg2) :CSTNode(tp,2,arg1,arg2) {}
CExpression::CExpression(NodeType tp, int children, CSTNode* arg1) :CSTNode(tp,children,arg1){}
CExpression::CExpression(NodeType tp) : CSTNode(tp, 0) {}
CExpressionNUMBER::CExpressionNUMBER(const char *text, double value) :CExpression(NT_EXPRESSION_NUMBER) {
	m_value = value;
	m_text = string(text);
}
CExpressionIDENTIFIER::CExpressionIDENTIFIER(const char *text) : CExpression(NT_EXPRESSION_IDENTIFIER) {
	m_text = string(text);
}
CExpressionFCall::CExpressionFCall(CSTNode* id, CSTNode* actual) : CExpression(NT_EXPRESSION_FCALL, 2, id,actual) {}
CExpressionFCall::CExpressionFCall(CSTNode* id) : CExpression(NT_EXPRESSION_FCALL, 1, id) {}

CExpressionAdd::CExpressionAdd(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_ADD, 2, arg1,arg2) {}
CExpressionMinus::CExpressionMinus(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_MINUS, 2, arg1, arg2) {}
CExpressionMult::CExpressionMult(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_MULT, 2, arg1, arg2) {}
CExpressionDiv::CExpressionDiv(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_DIV, 2, arg1, arg2) {}
CExpressionUnaryPlus::CExpressionUnaryPlus(CSTNode* arg1) : CExpression(NT_EXPRESSION_UNARYPLUS, 1, arg1) {}
CExpressionUnaryMinus::CExpressionUnaryMinus(CSTNode* arg1) : CExpression(NT_EXPRESSION_UNARYMINUS, 1, arg1) {}
CExpressionAssign::CExpressionAssign(CSTNode* id, CSTNode* expr) : CExpression(NT_EXPRESSION_ASSIGN, 2, id, expr) {}
CExpressionAND::CExpressionAND(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_AND, 2, arg1, arg2) {}
CExpressionOR::CExpressionOR(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_OR, 2, arg1, arg2) {}
CExpressionNOT::CExpressionNOT(CSTNode* expr) : CExpression(NT_EXPRESSION_NOT, 1, expr) {}
CExpressionGT::CExpressionGT(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_GT, 2, arg1, arg2) {}
CExpressionGTE::CExpressionGTE(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_GTE, 2, arg1, arg2) {}
CExpressionLT::CExpressionLT(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_LT, 2, arg1, arg2) {}
CExpressionLTE::CExpressionLTE(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_LTE, 2, arg1, arg2) {}
CExpressionEQUAL::CExpressionEQUAL(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_EQUAL, 2, arg1, arg2) {}
CExpressionNEQUAL::CExpressionNEQUAL(CSTNode* arg1, CSTNode* arg2) : CExpression(NT_EXPRESSION_NEQUAL, 2, arg1, arg2) {}

void CCompileUnit::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	if (parent != nullptr) {
		(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	}
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CFunctionDefinition::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CFormalArgs::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CActualArgs::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionStatement::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CCompoundStatement::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CIfStatement::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CWhileStatement::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CReturnStatement::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CBreakStatement::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CNullStatement::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CStatementList::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionNUMBER::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionIDENTIFIER::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionFCall::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionAdd::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionMinus::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionMult::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionDiv::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionUnaryPlus::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionUnaryMinus::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionAssign::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionAND::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionOR::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionNOT::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionGT::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionGTE::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionLT::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionLTE::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionEQUAL::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}
void CExpressionNEQUAL::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}




double CExpressionNUMBER::Evaluate(CSTNode* parent) {
	return m_value;
}
double CExpressionIDENTIFIER::Evaluate(CSTNode* parent) {
	return m_value;
}
double CExpressionAssign::Evaluate(CSTNode* parent) {
	CExpressionIDENTIFIER *id = (CExpressionIDENTIFIER *)GetChild(0);
	id->m_value = GetChild(1)->Evaluate(this);
	cout << id->m_text << "=" << id->m_value << endl;
	return id->m_value;
}

double CExpressionAdd::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) + GetChild(1)->Evaluate(this);
}
double CExpressionMinus::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) - GetChild(1)->Evaluate(this);
}
double CExpressionMult::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) * GetChild(1)->Evaluate(this);
}
double CExpressionDiv::Evaluate(CSTNode* parent) {
	double denom = GetChild(1)->Evaluate(this);
	if ( denom == 0) {
		cout << "Division by zero" << endl;
		exit(1);
	}
	else {
		return GetChild(0)->Evaluate(this) / denom;
	}	
}
double CExpressionUnaryPlus::Evaluate(CSTNode* parent) {
	return +GetChild(0)->Evaluate(this);
}
double CExpressionUnaryMinus::Evaluate(CSTNode* parent) {
	return -GetChild(0)->Evaluate(this);
}
double CExpressionGT::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) > GetChild(1)->Evaluate(this) ? 1 : 0;
}
double CExpressionGTE::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) >= GetChild(1)->Evaluate(this) ? 1 : 0;
}
double CExpressionLT::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) < GetChild(1)->Evaluate(this) ? 1 : 0;
}
double CExpressionLTE::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) <= GetChild(1)->Evaluate(this) ? 1 : 0;
}
double CExpressionEQUAL::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) == GetChild(1)->Evaluate(this) ? 1 : 0;
}
double CExpressionNEQUAL::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) != GetChild(1)->Evaluate(this) ? 1 : 0;
}


double CExpressionAND::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) && GetChild(1)->Evaluate(this);
}
double CExpressionOR::Evaluate(CSTNode* parent) {
	return GetChild(0)->Evaluate(this) || GetChild(1)->Evaluate(this);
}
double CExpressionNOT::Evaluate(CSTNode* parent) {
	return !(GetChild(0)->Evaluate(this)) ;
}


double CExpressionStatement::Evaluate(CSTNode* parent) {
	CExpression* child= (CExpression*)GetChild(0);
	double result = child->Evaluate(this);
	if (child->GetNodeType() != NT_EXPRESSION_ASSIGN) {
		cout << ":" << result << endl;
	}
	return 0;
}
double CWhileStatement::Evaluate(CSTNode* parent) {
	while ( GetChild(0)->Evaluate(this) ) {
		GetChild(1)->Evaluate(this);
		if ( m_breakVisit ) {
			m_breakVisit = false;
			break;
		}
	}
	return 0;
}
double CIfStatement::Evaluate(CSTNode* parent) {
	if (GetChild(0)->Evaluate(this)) {
		GetChild(1)->Evaluate(this);
	}
	else {
		GetChild(2)->Evaluate(this);
	}
	return 0;
}

double CBreakStatement::Evaluate(CSTNode* parent) {
	m_breakVisit = true;
	return  0;
}
