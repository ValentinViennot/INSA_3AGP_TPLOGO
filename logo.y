%{
  #include <stdlib.h>
  #include <stdio.h>
  #include "logo_type.h"
  #include "logo_functions.h"

  void yyerror(const char* str) {
    printf("Error : %s\n", str);
  }
  int yywrap() {
    return 1;
  }

%}

%token VALUE
%token FORWARD_ LEFT_ RIGHT_ REPEAT_ HIDE_ RED GREEN BLUE

//type de yylval
%union {
    struct model_step* node;
    int value;
 };

//type des  symboles
%type <value> VALUE // int
%type <node> INSTRUCTION PROGRAM // *Node

%%

FINAL: PROGRAM
  {
    printLogo($1,0);
    writeSVG($1,"yacc.svg");
    freeLogo(&$1);
  }

PROGRAM:
  INSTRUCTION
  {
    $$ = InitLogo();
    addNode(&$$,$1);
  }
  | PROGRAM INSTRUCTION
  {
    addNode(&$1,$2);
    $$=$1;
  }

INSTRUCTION:
  FORWARD_ VALUE
  {
    $$=createNode(FORWARD,$2,NULL);
  }
  | LEFT_ VALUE
  {
    $$=createNode(LEFT,$2,NULL);
  }
  | RIGHT_ VALUE
  {
    $$=createNode(RIGHT,$2,NULL);
  }
  | REPEAT_ VALUE '[' PROGRAM ']'
  {
    $$=createNode(REPEAT,$2,$4);
  }
  | HIDE_ VALUE
  {
    $$=createNode(HIDE,$2,NULL);
  }
  | RED VALUE
  {
    $$=createNode(COLORR,$2,NULL);
  }
  | GREEN VALUE
  {
    $$=createNode(COLORG,$2,NULL);
  }
  | BLUE VALUE
  {
    $$=createNode(COLORB,$2,NULL);
  }

%%

int main() {
  yyparse();
  return 0;
}
