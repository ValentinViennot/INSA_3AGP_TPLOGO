%{
  #include "logo.tab.h"
  #include <string.h>
%}
%%

"FORWARD"           return FORWARD_;
"LEFT"              return LEFT_;
"RIGHT"             return RIGHT_;
"REPEAT"            return REPEAT_;
("COLOR ")?"RED"    {yylval.value = 0; return COLOR_;}
("COLOR ")?"GREEN"  {yylval.value = 1; return COLOR_;}
("COLOR ")?"BLUE"   {yylval.value = 2; return COLOR_;}
"HIDE"              return HIDE_;
[1-9][0-9]*|0       {yylval.value = atoi(yytext); return VALUE;}
"["                 return '[';
"]"                 return ']';
"+"                 {yylval.value = 1; return SIGNED;}
"-"                 {yylval.value = -1; return SIGNED;}
[ \t]+              ;
\n                  ;
"NAME"              return NAME;
[a-zA-Z]+".svg"     {strcpy(yylval.name,yytext); return NAME_;}

%%
