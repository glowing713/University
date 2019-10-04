%{
%}

%x MOVE

%%

"/*"                        BEGIN MOVE;

<MOVE>.                     ;

<MOVE>\n                    ;

<MOVE>"*/"                  BEGIN 0;

[\t\n ]                     ECHO;

"program"                   printf("TPROGRAM");
"proc"                      printf("TPROC");
"returns"                   printf("TRETURNS");
"int"                       printf("TINT");
"if"                        printf("TIF");
"else"                      printf("TELSE");
"for"                       printf("TFOR");
"call"                      printf("TCALL");
"begin"                     printf("TBEGIN");

"main"                      printf("TMAIN");
"func"                      printf("TFUNC");
"var"                       printf("TVAR");
"long"                      printf("TLONG");
"then"                      printf("TTHEN");
"while"                     printf("TWHILE");
"to"                        printf("TTO");
"return"                    printf("TRETURN");
"end"                       printf("TEND");

"="                         printf("TASS");
"&"                         printf("TAND");
"|"                         printf("TOR");
"!"                         printf("TNOT");
"<"                         printf("TLT");
"<="                        printf("TLE");
">"                         printf("TGT");
">="                        printf("TGE");
"!="                        printf("TNE");
"+"                         printf("TPLUS");
"-"                         printf("TMINUS");
"*"                         printf("TMUL");
"/"                         printf("TDIV");

";"|":"|"("|")"|","|"."     ECHO;

[a-z,A-Z][a-z,A-Z,0-9]*     printf("TWORD");

[1-9]*[0-9]+                printf("TNUMBER");




%%
int main(){
    yylex();
    printf("end\n");
}
