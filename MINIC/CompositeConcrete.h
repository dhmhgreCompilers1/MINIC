#ifndef COMPOSITE_CONCRETE_
#define COMPOSITE_CONCRETE_
#include "Composite.h"

class CExpression;

class CCompileUnit : public CSTNode {
public:
	CCompileUnit(CSTNode* arg1, CSTNode* arg2);
	CCompileUnit(CSTNode* arg1);
};
class CFunctionDefinition: public CSTNode {
public:
	CFunctionDefinition(CSTNode* id, CSTNode* fargs, CSTNode* compoundst);
	CFunctionDefinition(CSTNode* id, CSTNode* compoundst);
};
class CFormalArgs : public CSTNode {
public:
	CFormalArgs(CSTNode* fargs, CSTNode* id);
	CFormalArgs(CSTNode* id);
};
class CActualArgs : public CSTNode {
public:
	CActualArgs(CSTNode* actargs, CSTNode* expr);
	CActualArgs(CSTNode* expr);
};
class CStatement : public CSTNode {
protected:
	CStatement(NodeType tp, int children);
	CStatement(NodeType tp, int children, CSTNode* arg);
	CStatement(NodeType tp, int children, CSTNode* arg1, CSTNode* arg2);
	CStatement(NodeType tp, int children, CSTNode* arg1,CSTNode *arg2, CSTNode *arg3);
	CStatement(NodeType tp);
};
class CExpressionStatement : public CStatement {
public:
	CExpressionStatement(CSTNode* arg);
};
class CCompoundStatement : public CStatement {
public:
	CCompoundStatement(CSTNode* arg = nullptr);
};
class CIfStatement : public CStatement {
public:
	CIfStatement(CSTNode* cond, CSTNode* ifpath, CSTNode* elsepath);
	CIfStatement(CSTNode* cond, CSTNode* ifpath);
};
class CWhileStatement : public CStatement {
public:	
	CWhileStatement(CSTNode* cond, CSTNode* body);
};
class CReturnStatement : public CStatement {
public:
	CReturnStatement(CSTNode* expr);
};
class CBreakStatement : public CStatement {
public:
	CBreakStatement();
};
class CStatementList : public CSTNode {
public:
	CStatementList(CSTNode* arg1);
	CStatementList(CSTNode* arg1, CSTNode* arg2);
};
class CExpression : public CSTNode {
public:
	CExpression(NodeType tp, int children, CSTNode* arg1, CSTNode* arg2);
	CExpression(NodeType tp, int children, CSTNode* arg1);
};
class CExpressionNUMBER : public CExpression {
public:
	CExpressionNUMBER(CSTNode* num);
};
class CExpressionIDENTIFIER : public CExpression {
public:
	CExpressionIDENTIFIER(CSTNode* id);
};
class CExpressionFCall : public CExpression {
public:
	CExpressionFCall(CSTNode* id, CSTNode* actual);
	CExpressionFCall(CSTNode* id);
};
class CExpressionAdd : public CExpression {
public:
	CExpressionAdd(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionMinus : public CExpression {
public:
	CExpressionMinus(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionMult : public CExpression {
public:
	CExpressionMult(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionDiv : public CExpression {
public:
	CExpressionDiv(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionUnaryPLus : public CExpression {
public:
	CExpressionUnaryPLus(CSTNode* arg1);
};
class CExpressionUnaryMinus : public CExpression {
public:
	CExpressionUnaryMinus(CSTNode* arg1);
};
class CExpressionAssign : public CExpression {
public:
	CExpressionAssign(CSTNode* id, CSTNode* expr);
};
class CExpressionAND : public CExpression {
public:
	CExpressionAND(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionOR : public CExpression {
public:
	CExpressionOR(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionNOT : public CExpression {
public:
	CExpressionNOT(CSTNode* expr);
};
class CExpressionGT : public CExpression {
public:
	CExpressionGT(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionGTE : public CExpression {
public:
	CExpressionGTE(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionLT : public CExpression {
public:
	CExpressionLT(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionLTE : public CExpression {
public:
	CExpressionLTE(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionEQUAL : public CExpression {
public:
	CExpressionEQUAL(CSTNode* arg1, CSTNode* arg2);
};
class CExpressionNEQUAL : public CExpression {
public:
	CExpressionNEQUAL(CSTNode* arg1, CSTNode* arg2);
};








#endif

