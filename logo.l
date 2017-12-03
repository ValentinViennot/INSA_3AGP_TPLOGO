%{
  #include "logo.tab.h"
%}
%%

"FORWARD"         return FORWARD_;
"LEFT"            return LEFT_;
"RIGHT"           return RIGHT_;
"REPEAT"          return REPEAT_;
[1-9][0-9]*|0     {yylval.value = atoi(yytext); return VALUE;}
"["               return '[';
"]"               return ']';
[ \t]+              ;
\n                  ;

%%
