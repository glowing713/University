%{
    #include <stdlib.h>
    #include "indent.tab.h"
%}
%%
"while"     return(TWHILE);
"do"        return(TDO);
"end"       return(TEND);
"stmt"      return(TSTMT);
"if"        return(TIF);
"then"      return(TTHEN);
"c0"        return(TC0);
[ \t\n]           ;
%%
