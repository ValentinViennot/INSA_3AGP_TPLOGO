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

  char programName[50] = "out.svg"; 

%}

%token NAME_
%token VALUE DELTA
%token FORWARD_ LEFT_ RIGHT_ REPEAT_ HIDE_ COLOR_ SCALE_ NAME

//type de yylval
%union {
    char name[50];
    struct model_step* node;
    int value;
 };

//type des  symboles
%type <name> NAME_ // char*
%type <value> VALUE COLOR_ DELTA // int
%type <node> INSTRUCTION PROGRAM // Node*

%%

FINAL:
  PROGRAM {
    printLogo($1,0);
    writeSVG($1,programName);
    freeLogo(&$1);
  }

PROGRAM:
  NAME NAME_ PROGRAM
  {
    strcpy(programName,$2);
    $$ = $3;
  }
  | INSTRUCTION
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
  | SCALE_ VALUE
  {
    $$=createNode(SCALE,$2,NULL);
  }
  | REPEAT_ VALUE '[' PROGRAM ']'
  {
    $$=createNode(REPEAT,$2,$4);
  }
  | HIDE_ VALUE
  {
    $$=createNode(HIDE,$2,NULL);
  }
  | COLOR_ VALUE {
    while ($2>255) $2-=255;
    $$=createNode(COLOR,$2*10+$1,NULL);
  }
  | COLOR_ DELTA VALUE {
    $$=createNode(DCOLOR,$2*($3*10+$1),NULL);
  }

%%

int main() {
  yyparse();
  return 0;
}
