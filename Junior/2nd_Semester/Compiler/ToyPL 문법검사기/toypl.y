%{
	#include <stdio.h> 
	#include <string.h>
	int i = 0;
%}
%union {
	char * name;
	int num;
}
%token	TPROGRAM TMAIN TPROC TFUNC TRETURNS TCALL TRETURN 
%token	TBEGIN TEND 
%token	TVAR TLONG TINT
%token	TAND TOR TNOT
%token	TLT TGT TLE TGE TNE 
%token	TPLUS TMINUS TDIV TMUL 
%token	TASS 
%token	TWHILE 
%token	TFOR TTO
%token	TIF TTHEN TELSE TDO
%token 	<name>TWORD
%token 	<num>TNUMBER
%type   <name>Var Name
%type   <num>Number
%%  
Program 		: TPROGRAM Name ';'
                SubPgmList TMAIN  VarDecl CompStmt '.'
                ;
VarDecl 		: TVAR DclList ';'  
                |
                ;
DclList 		: DclList ';' Decl  						
                | Decl
                ;
Decl 	    	: VarList ':' Type
                ;
VarList 		: VarList ',' Var  				
                | Var
                ;
Type 	    	: TINT
                | TLONG
                ;
Var 	    	: Name	{$$=$1;;}
                ;
SubPgmList 	    : SubPgmList SubPgm
                |
                ;
SubPgm 	    	: ProcDecl
                | FuncDecl
                ;
ProcDecl 		: TPROC Name '(' FormParam ')' VarDecl CompStmt 			
                ;
FuncDecl    	: TFUNC Name '(' FormParam ')' TRETURNS '(' Type ')' VarDecl CompStmt
                ;
FormParam   	: DclList
                |
                ;
Stmt	    	: AsgnStmt
                | IfStmt
                | WhileStmt
                | ForStmt
                | CallStmt
                | RtnStmt
                | CompStmt
                ;
AsgnStmt 	:Var TASS Expr						
            ;
IfStmt 		: TIF '(' Cond ')' TTHEN Stmt
            TELSE Stmt
            | TIF '(' Cond ')' TTHEN Stmt
            ;
WhileStmt 	: TWHILE '(' Cond ')' TDO Stmt
            ;
ForStmt 		: TFOR '(' Var TASS Expr TTO Expr ')' Stmt	
            ;
CallStmt 		: TCALL Name '(' ParamList ')'	
            ;
RtnStmt 		: TRETURN '(' Expr ')'				
            ;
CompStmt 	: TBEGIN StmtList TEND					
            ;
StmtList 		: StmtList ';' Stmt  			
            | Stmt
            ;
Cond 		: Cond TAND  Rel  		
		| Cond TOR Rel 							
		| TNOT Rel 		
		| Rel 								
		;
Rel 		: Expr TLT Expr  							
		| Expr TLE Expr 							
		| Expr TGT Expr  							
		| Expr TGE Expr 							
		| Expr TASS Expr  							
		| Expr TNE Expr 							
		;
Expr 		: Expr TPLUS Term  						
		| Expr TMINUS Term 				
		| Term 			
		;
Term 		: Term TMUL Fact  	
		| Term TDIV Fact 	
		| Fact 				
		;
Fact 		: Var  							
		| Number			
          		| FuncCall 					
		| TMINUS Fact		
		| '('  Expr  ')'						
		;
FuncCall 	: Name '(' ParamList ')' 						
		;
ParamList 	: ExprList  							
		|								
		;
ExprList 	: ExprList ',' Expr  						
		| Expr 			
		;
Name 		: TWORD	{$$=$1;}	
		;
Number	: TNUMBER {$$=$1;}	
		;
%%
int main() {
	yyparse();
}
int yyerror(){
	printf("syntax error\n");
	return 0;
}
