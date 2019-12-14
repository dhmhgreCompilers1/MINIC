#include "CompositeConcrete.h"
void MapActualToFormalArguments();
CCompileUnit::CCompileUnit(CSTNode* arg1, CSTNode* arg2): CSTNode(NT_COMPILEUNIT,2,arg1,arg2) {}
CCompileUnit::CCompileUnit(CSTNode* arg1) :CSTNode(NT_COMPILEUNIT,1,arg1) {}
CFunctionDefinition::CFunctionDefinition(CSTNode* id, CSTNode* fargs, CSTNode* compoundst) :CSTNode(NT_FUNCTIONDEFINITION,3,id,fargs,compoundst){}
CFunctionDefinition::CFunctionDefinition(CSTNode* id, CSTNode* compoundst):CSTNode(NT_FUNCTIONDEFINITION,3,id,new CFormalArgs(),compoundst) {}
CFormalArgs::CFormalArgs(CSTNode* fargs, CSTNode* id) :CSTNode(NT_FORMALARGS,2,fargs,id){}
CFormalArgs::CFormalArgs(CSTNode* id):CSTNode(NT_FORMALARGS,1,id) {}
CFormalArgs::CFormalArgs() :CSTNode(NT_FORMALARGS,0) {}
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
CExpressionVariable::CExpressionVariable(CSTNode *id) : CExpression(NT_EXPRESSION_VARIABLE) {
	m_text = _strdup(((CIDENTIFIER*)id)->m_text.c_str());
}
CIDENTIFIER::CIDENTIFIER(const char* text) :CSTNode(NT_IDENTIFIER,0) {
	m_text = _strdup(text);
}
CIDENTIFIER::~CIDENTIFIER() {}
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
void CExpressionVariable::PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) {
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
void CIDENTIFIER::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	(*dotfile) << "\"" << parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile, this);
}

double CExpressionNUMBER::Evaluate(CSTNode* parent) {
	return m_value;
}
double CExpressionVariable::Evaluate(CSTNode* parent) {
	return g_symbolTable.GetSymbol(m_text)->value;
}
double CIDENTIFIER::Evaluate(CSTNode* parent) {
	return 0;
}

double CExpressionAssign::Evaluate(CSTNode* parent) {
	CExpressionVariable *id = (CExpressionVariable*)GetChild(0);
	Symbol *s = g_symbolTable.GetSymbol(id->m_text);
	s->value = GetChild(1)->Evaluate(this);
	cout << s->m_text << "=" << s->value << endl;
	return s->value;
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

void GetFormalArguments(CSTNode* currentnode, list<CIDENTIFIER*>* arguments) {
	list<CSTNode*>::iterator it;
	double result = 0;

	if (dynamic_cast<CIDENTIFIER*>(currentnode) != nullptr) {
		arguments->push_back((CIDENTIFIER*)currentnode);
	}

	for (it = currentnode->m_children->begin(); it != currentnode->m_children->end(); it++) {
		GetFormalArguments((*it), arguments);
	}
}

void CExpressionFCall::MapActualToFormalArguments() {
	CIDENTIFIER* fid = (CIDENTIFIER*)GetChild(0);
	CActualArgs* aArgs = (CActualArgs*)GetChild(1);
	CFunctionDefinition* fundef = (CFunctionDefinition*)g_symbolTable.GetSymbol(fid->m_text)->syntaxNode;
	CFormalArgs* fargs = (CFormalArgs*)fundef->GetChild(1);
	list<CIDENTIFIER*>::iterator it;
	list<CExpression*>::iterator ite;
	m_actualArguments = new list<CExpression*>();
	m_formalArguments = new list<CIDENTIFIER*>();
	GetActualArguments(aArgs, m_actualArguments);
	GetFormalArguments(fargs, m_formalArguments);
	for ( it = m_formalArguments->begin(), ite=m_actualArguments->begin();
		  it != m_formalArguments->end() ;it++,ite++) {
		g_symbolTable.GetSymbol((*it)->m_text)->value = (*ite)->Evaluate(this);
	}
}

void GetActualArguments(CSTNode* currentnode, list<CExpression*>* arguments) {
	list<CSTNode*>::iterator it;
	double result = 0;

	if (dynamic_cast<CExpression*>(currentnode) != nullptr) {
		arguments->push_back((CExpression*)currentnode);
	}

	for (it = currentnode->m_children->begin(); it != currentnode->m_children->end(); it++) {
		GetActualArguments((*it), arguments);
	}
}
double CExpressionFCall::GetActualArgument(int index) {
	CActualArgs *aArgs = (CActualArgs*)GetChild(1);
	list<CExpression*>::iterator it;
	if ( m_actualArguments == nullptr) {
		m_actualArguments = new list<CExpression*>();
		GetActualArguments(aArgs,m_actualArguments);
	}
	it = m_actualArguments->begin();
	advance(it, index);
	return (*it)->Evaluate(this);
}

double CReturnStatement::Evaluate(CSTNode* parent) {
	//1.Mark the end of function
	m_breakVisit = true;
	m_returnedValue = GetChild(0)->Evaluate(this);
	return m_returnedValue;
}

double CExpressionFCall::Evaluate(CSTNode* parent) {
	double result = 0;
	CIDENTIFIER* functionId = (CIDENTIFIER*)GetChild(0);
	CFunctionDefinition* fundef;
	
	if ( !functionId->m_text.compare("sqrt") ) {
		result = sqrt(GetActualArgument(0));
	}
	else if (!functionId->m_text.compare("pow")) {
		result = pow(GetActualArgument(0), GetActualArgument(1));
	}
	else {
		// 1. Get access to the function definition object
		fundef = (CFunctionDefinition *)g_symbolTable.GetSymbol(functionId->m_text)->syntaxNode;
		// Map actual to formal arguments 
		MapActualToFormalArguments();
		// Evaluate
		fundef->GetChild(2)->Evaluate(this);
		// Return value
		result = m_returnedValue;
		m_breakVisit = false;
	}

	return result;
}
double CFunctionDefinition::Evaluate(CSTNode* parent) { return 0; }