%{
#include <stdio.h>
#include <string.h>
#include "node.h"
Node * rootNode;
%}
%union {
	double dval;
	char * sval;
	struct _node * nodeP;
}
%token <dval> TNUMBER 
%token <sval> TNAME

%type <nodeP> Fact
%type <nodeP> Term
%type <nodeP> Exp
%type <nodeP> FuncCall
%type <nodeP> ParamList
%type <nodeP> ExprList
%%
Goal	: Exp			{
				  	rootNode = $1;
				}  
	| Rel
	;
Rel	: Exp '<' Exp
	;
Exp 	: Exp '+' Term 		{
					$$=makeNode("PLUS", NULL, $1);
					$1->bro = $3;
				}
	| Exp '-' Term		{
					$$=makeNode("MINUS", NULL, $1);
					$1->bro = $3;
				}
	| Term	               	{	$$ = $1;  }
	;
 
Term 	: Term '*' Fact		{
					$$=makeNode("TIMES", NULL, $1);
					$1->bro = $3;
				}
	| Term '/' Fact		{
					$$=makeNode("DIV", NULL, $1);
					$1->bro = $3;
				}
	| Fact			{ 	$$ = $1; }	
	;

Fact 	: TNAME			{ 
					printf("Name:%s\n", $1); 
					$$=makeNode("NAME", NULL, NULL);
					$$->value.sv = $1;
				}
	| TNUMBER		{ 
					printf("Number:%f\n", $1); 
					$$=makeNode("NUMBER", NULL, NULL);
					$$->value.dv = $1;
				}
	| FuncCall		{ $$=$1;}	
	| '-'Fact		{ 
					$$=makeNode("NEG", NULL, $2);
				}
	| '('Exp')'		{ $$=$2;}
	;
FuncCall : TNAME'('ParamList')' {$$=NULL;}
	;
ParamList: ExprList		{ $$=NULL; }
	|			{ $$=NULL; }
	;
ExprList: ExprList','Exp	{ $$=NULL; }
	| Exp			{ $$=NULL; }
	;
%%

void traverse(Node * nodeP); 

void main() {
	yyparse();

//  code to print AST
	traverse(rootNode);
}

void traverse(Node * nodeP) {
	while (nodeP!=NULL) {
		printf("%s\n", nodeP->kind);
		traverse(nodeP->son);
		nodeP=nodeP->bro;
	}
}
