%{
  #include "logo.tab.h"
  #include <string.h>
%}
%%

"FORWARD"           return FORWARD_;
"LEFT"              return LEFT_;
"RIGHT"             return RIGHT_;
"REPEAT"            return REPEAT_;
"FOR"				return FOR;
"TO"				return TO;
"SCALE"            	return SCALE_;
"RECT"            	return RECT;
"POLYGON"			return POLYGON;
"CIRCLE"			return CIRCLE;
"X"					return GTX;
"Y"					return GTY;
("COLOR ")?"RED"    {yylval.value = 0; return COLOR_;}
("COLOR ")?"GREEN"  {yylval.value = 1; return COLOR_;}
("COLOR ")?"BLUE"   {yylval.value = 2; return COLOR_;}
"HIDE"              return HIDE_;
"SHOW"              return SHOW;

"["                 return '[';
"]"                 return ']';
"+"                 {yylval.value = 1; return DELTA;}
"-"                 {yylval.value = -1; return DELTA;}
"/"                 return DIV;
"*"                 return MULT;
"("     			return '(';
")"     			return ')';
"="					return '=';

[ \t]+              ;
\n                  ;
"NAME"              return NAME;
[a-zA-Z][a-zA-Z0-9]{0,44}".svg" {strcpy(yylval.name,yytext); return NAME_;}

[a-z]{1}			{yylval.vname = yytext[0]; return VAR;}
[1-9][0-9]*|0     	{yylval.value = atoi(yytext); return ENTIER;}

%%
