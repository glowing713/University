%{
#include <stdio.h>
#include <string.h>

typedef struct Node {
	char arr[10];
	union {
		double dval;
		char * sval;
	} value;
	struct Node * bro;
	struct Node * son;
} Node;

Node * makeNode(char *, Node *, Node *);
Node * rootNode;

int p = 0;
%}
%union {
double dval;
char * sval;
struct Node * nodeP;
}

%token <dval> TNUMBER 
%token <sval> TNAME TINT TLONG
%token TPROGRAM TMAIN TPROC TFUNC TRETURNS TVAR TINT TLONG TIF TTHEN TELSE TWHILE
%token TDO TFOR TTO TCALL TRETURN TBEGIN TEND
%token TLE TGE TNE TASS TAND TOR TNOT TLT TGT TPLUS TMINUS TMUL TDIV
%type <nodeP> Program
%type <nodeP> SubPgmList
%type <nodeP> SubPgm
%type <nodeP> ProcDecl
%type <nodeP> FuncDecl
%type <nodeP> FormParam
%type <nodeP> VarDecl
%type <nodeP> DclList 
%type <nodeP> Var
%type <nodeP> Decl
%type <nodeP> VarList
%type <nodeP> Type
%type <nodeP> AsignStmt
%type <nodeP> IfStmt
%type <nodeP> WhileStmt
%type <nodeP> Stmt
%type <nodeP> CallStmt
%type <nodeP> ForStmt
%type <nodeP> RetrnStmt
%type <nodeP> CompStmt
%type <nodeP> StmtList
%type <nodeP> Expr
%type <nodeP> Term
%type <nodeP> Fact
%type <nodeP> FuncCall
%type <nodeP> ParamList
%type <nodeP> ExprList
%type <nodeP> Rel
%type <nodeP> Cond
%type <nodeP> Name
%type <nodeP> Number
%%
Goal	: Program	{rootNode=$1;}
	;

Program	: TPROGRAM Name';' SubPgmList TMAIN VarDecl Stmt'.'	{$$=makeNode("MAIN",$4,$6); $6->bro=$7;}
	;

SubPgmList	: SubPgmList SubPgm	{Node* temp=$2;
					while(temp!=NULL){
						if(temp->bro==NULL){
							temp->bro=$1; break;
						}
						temp=temp->bro;
					}
					$$=$2;}
		|			{$$=NULL;}
		;

SubPgm	: ProcDecl	{$$=$1;}
	| FuncDecl	{$$=$1;}
	;

ProcDecl	:TPROC Name'('FormParam')' VarDecl Stmt	{$$=makeNode("PROC",NULL,$2);
						$2->bro=$4; $4->bro=$6; $6->bro=$7;}
	;

FuncDecl	: TFUNC Name'('FormParam')' TRETURNS '('Type')' VarDecl Stmt	{$$=makeNode("FUNC",NULL,$2);
								$2->bro=$4; $4->bro=$8; $8->bro=$10; $10->bro=$11;}
	;

StmtList	:StmtList';'Stmt	{Node* temp=$1;
			while(temp!=NULL){
				if(temp->bro==NULL){
					temp->bro=$3; break;
				}
				temp=temp->bro;
			}
			$$=$1;}
	|Stmt		{$$=$1;}
	;
Stmt	: AsignStmt	{$$=$1;}
	| IfStmt		{$$=$1;}
	| WhileStmt	{$$=$1;}
	| ForStmt		{$$=$1;}
	| CompStmt	{$$=$1;}
	| RetrnStmt	{$$=$1;}
	| CallStmt	{$$=$1;}
	;

AsignStmt: Var TASS Expr		{$$=makeNode("ASSIGN",NULL,$1); $1->bro=$3;}
	;

IfStmt	: TIF '(' Cond ')' TTHEN Stmt TELSE Stmt	{$$=makeNode("IF",NULL,$3); $3->bro=$6; $6->bro=$8;}
     	| TIF '(' Cond ')' TTHEN Stmt 		{$$=makeNode("IF",NULL,$3); $3->bro=$6;}
	;

WhileStmt: TWHILE '(' Cond ')' TDO Stmt	{$$=makeNode("WHILE",NULL,$3); $3->bro=$6;}
      	;

ForStmt	: TFOR '(' Var TASS Expr TTO Expr ')' Stmt	{$$=makeNode("FOR",NULL,$3); $3->bro=$5; $5->bro=$7; $7->bro=$9;}
      	;

CompStmt: TBEGIN StmtList TEND	{$$=makeNode("COMP",NULL,$2);}              
      	;

RetrnStmt	: TRETURN '('Expr')'	{$$=makeNode("RETURN",NULL,$3);}
	;

CallStmt	: TCALL Var '(' ParamList ')'	{$$=makeNode("PCALL",NULL,$2); $2->bro=$4;}
	;

Cond	: Cond TAND Rel		{$$=makeNode("AND",NULL,$1); $1->bro=$3;}
	| Cond TOR Rel		{$$=makeNode("OR",NULL,$1); $1->bro=$3;}
	| TNOT Rel		{$$=makeNode("NOT",NULL,$2);}
	| Rel			{$$=$1;}
	;

Rel	: Expr TLT Expr		{$$=makeNode("LT",NULL,$1); $1->bro=$3;}
      	| Expr TLE Expr            	{$$=makeNode("LE",NULL,$1); $1->bro=$3;}
      	| Expr TGT Expr                 	{$$=makeNode("GT",NULL,$1); $1->bro=$3;}
    	| Expr TGE Expr                 	{$$=makeNode("GE",NULL,$1); $1->bro=$3;}
    	| Expr TASS Expr               	{$$=makeNode("EQ",NULL,$1); $1->bro=$3;}
    	| Expr TNE Expr     		{$$=makeNode("NE",NULL,$1); $1->bro=$3;}
        ;

Expr 	: Expr TPLUS Term 		{$$=makeNode("PLUS", NULL, $1); $1->bro = $3;}
	| Expr TMINUS Term	{$$=makeNode("MINUS", NULL, $1); $1->bro = $3;}
	| Term	               	{$$ = $1;}
	;

Term 	: Term TMUL Fact		{$$=makeNode("TIMES", NULL, $1); $1->bro = $3;}
	| Term TDIV Fact		{$$=makeNode("DIV", NULL, $1); $1->bro = $3;}
	| Fact			{$$ = $1;}	
	;

Fact 	: Var			{$$=$1;}

	| Number			{$$=$1;}

	| FuncCall			{$$=$1;}	
	| TMINUS Fact		{$$=makeNode("NEG", NULL, $2);}
	| '('Expr')'			{$$=$2;}
	;

FuncCall : Name '('ParamList')' 	{$$=makeNode("FCALL",NULL,$3);}
	;

VarList	: VarList','Var		{$1->bro=$3; $$=$1;}
	| Var			{$$=$1;}
	;

Var	: Name			{$$=$1;}
	;

Type	: TINT			{$$=makeNode("INT",NULL,NULL); $$->value.sval=$1;}
	| TLONG			{$$=makeNode("LONG",NULL,NULL); $$->value.sval=$1;}
	;

FormParam	: DclList		{$$=makeNode("VARDECL",NULL,$1);}
		|		{$$=makeNode("VARDECL",NULL,NULL);}
		;

DclList	: DclList';'Decl		{Node* temp=$1;
				while(temp!=NULL){
					if(temp->bro==NULL){
						temp->bro=$3; break;
					}
					temp=temp->bro;
				}
				$$=$1;}
	| Decl			{$$=$1;}
	;

VarDecl	: TVAR DclList';'		{$$=makeNode("VARDECL",NULL,$2);}
	|			{$$=makeNode("VARDECL",NULL,NULL);}
	;

Decl	: VarList':'Type		{$$=makeNode("DECL",NULL,$1); $1->bro=$3;}
	;

ParamList: ExprList			{ $$=$1; }
	|			{ $$=NULL; }
	;

ExprList	: ExprList','Expr		{Node* temp=$1;
				while(temp!=NULL){
					if(temp->bro==NULL){
						temp->bro=$3; break;
					}
					temp=temp->bro;
				}
				$$=$1;}
	| Expr			{ $$=$1; }
	;

Name	: TNAME			{$$=makeNode("NAME",NULL,NULL); $$->value.sval=$1;}
	;

Number	: TNUMBER		{$$=makeNode("NUMBER",NULL,NULL); $$->value.dval=$1;}
	;
%%

Node* makeNode(char* arr, Node* bro, Node* son) {
	Node* temp;

	temp = (Node*)malloc(sizeof(Node));
	strcpy(temp->arr, arr);
	temp->bro = bro;
	temp->son = son;

	return temp;
}

void traverse(Node* nodeP);
void cond(Node* nodeP);

int main() {
	yyparse();
	traverse(rootNode);
	return(0);
}

void traverse(Node* nodeP) {
	while (nodeP != NULL) {
		if (strcmp(nodeP->arr, "MAIN") == 0) {
			printf("ssp2;");
			traverse(nodeP->son);
			printf("stp");
		}
		else if (strcmp(nodeP->arr, "COMP") == 0) {
			traverse(nodeP->son);
		}
		else if (strcmp(nodeP->arr, "ASSIGN") == 0) {
			if (nodeP->son != NULL) {
				if (strcmp(nodeP->son->arr, "NAME") == 0) {
					printf("ldc p(%s); ", nodeP->son->value.sval);
					traverse(nodeP->son->bro);
					printf("sto; ");
				}
			}
		}
		else if (strcmp(nodeP->arr, "PLUS") == 0) {
			traverse(nodeP->son);
			printf("add; ");
		}
		else if (strcmp(nodeP->arr, "MINUS") == 0) {
			traverse(nodeP->son);
			printf("sub; ");
		}
		else if (strcmp(nodeP->arr, "TIMES") == 0) {
			traverse(nodeP->son);
			printf("mul; ");
		}
		else if (strcmp(nodeP->arr, "DIV") == 0) {
			traverse(nodeP->son);
			printf("div; ");
		}
		else if (strcmp(nodeP->arr, "NEG") == 0) {
			traverse(nodeP->son);
			printf("neg; ");
		}
		else if (strcmp(nodeP->arr, "IF") == 0) {
			int tmp = p++;
			cond(nodeP->son);
			printf("fjp l%d; ", tmp);
			if (nodeP->son->bro!=NULL) {
				cond(nodeP->son->bro);
			}
			if (nodeP->son->bro->bro != NULL) {
				int tmpp = p++;
				printf("ujp l%d; ", tmpp);
				printf("l%d: ", tmp);
				cond(nodeP->son->bro->bro);
				printf("l%d: ", tmpp);
			}
			else {
				printf("l%d: ", tmp);
			}	
		}
		else if (strcmp(nodeP->arr, "NUMBER") == 0) {
			printf("ldc %.2lf; ", nodeP->value.dval);
		}
		else if (strcmp(nodeP->arr, "NAME") == 0) {
			printf("ldc p(%s); ind; ", nodeP->value.sval);
		}
		nodeP = nodeP->bro;
	}
}
void cond(Node* nodeP) {
	if (strcmp(nodeP->arr, "AND") == 0) {
		traverse(nodeP->son);
		printf("and; ");
	}
	else if (strcmp(nodeP->arr, "OR") == 0) {
		traverse(nodeP->son);
		printf("or; ");
	}
	else if (strcmp(nodeP->arr, "NOT") == 0) {
		traverse(nodeP->son);
		printf("not; ");
	}
	else if (strcmp(nodeP->arr, "LT") == 0) {
		traverse(nodeP->son);
		printf("les; ");
	}
	else if (strcmp(nodeP->arr, "LE") == 0) {
		traverse(nodeP->son);
		printf("leq; ");
	}
	else if (strcmp(nodeP->arr, "GT") == 0) {
		traverse(nodeP->son);
		printf("grt; ");
	}
	else if (strcmp(nodeP->arr, "GE") == 0) {
		traverse(nodeP->son);
		printf("grq; ");
	}
	else if (strcmp(nodeP->arr, "EQ") == 0) {
		traverse(nodeP->son);
		printf("equ; ");
	}
	else if (strcmp(nodeP->arr, "NE") == 0) {
		traverse(nodeP->son);
		printf("neq; ");
	}
	else if (strcmp(nodeP->arr, "ASSIGN") == 0) {
		if (nodeP->son != NULL) {
			if (strcmp(nodeP->son->arr, "NAME") == 0) {
				printf("ldc p(%s); ", nodeP->son->value.sval);
				traverse(nodeP->son->bro);
				printf("sto; ");
			}
		}
	}
	else if (strcmp(nodeP->arr, "PLUS") == 0) {
		traverse(nodeP->son);
		printf("add; ");
	}
	else if (strcmp(nodeP->arr, "MINUS") == 0) {
		traverse(nodeP->son);
		printf("sub; ");
	}
	else if (strcmp(nodeP->arr, "TIMES") == 0) {
		traverse(nodeP->son);
		printf("mul; ");
	}
	else if (strcmp(nodeP->arr, "DIV") == 0) {
		traverse(nodeP->son);
		printf("div; ");
	}
	else if (strcmp(nodeP->arr, "NEG") == 0) {
		traverse(nodeP->son);
		printf("neg; ");
	}
	else if (strcmp(nodeP->arr, "NUMBER") == 0) {
		printf("ldc %.2lf; ", nodeP->value.dval);
	}
	else if (strcmp(nodeP->arr, "NAME") == 0) {
		printf("ldc p(%s); ind; ", nodeP->value.sval);
	}
}
