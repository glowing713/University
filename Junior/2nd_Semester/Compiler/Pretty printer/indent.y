%{
    #include <stdio.h>
    #include <string.h>
    int i=0;
%}
%token    TIF TTHEN TWHILE TDO TEND TC0 TSTMT
%%
S         : If
| While
| TSTMT  {printf("\n"); for(int k=0; k<i; k++) printf(" ");
    printf("stmt ");}
;
If          : TIF
{printf("\n"); for(int k=0; k<i; k++) printf(" ");
    printf("if ");}
Cond TTHEN {printf("then "); i=i+4;} S {i=i-4;}
;
While       : TWHILE
{printf("\n"); for(int k=0; k<i; k++) printf(" ");
    printf("while ");}
Cond TDO {printf("do "); i=i+4;} S {i=i-4;}
TEND
{printf("\n"); for(int k=0; k<i; k++) printf(" ");
    printf("end ");}
;
Cond        : TC0 {printf("c0 ");}
;
%%
int main() {
    yyparse();
}
int yyerror(){
    printf("syntax error\n");
    return 0;
}
