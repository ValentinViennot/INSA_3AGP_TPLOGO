#include "logo_functions.h"

Program InitLogo() {
  return NULL;
}

Node* createNode(Instruction instruction, int value, Program subNode) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->instruction = instruction;
  node->value = value;
  node->next = NULL;
  node->subNode = subNode;
  return node;
}

void freeLogo(Program* program) {
  if (*program == NULL)
    return;
  freeLogo(&((*program)->subNode));
  freeLogo(&((*program)->next));
  free(*program);
}

void addNode(Program* program, Node* node) {
  if (*program == NULL) {
    *program = node;
  } else {
    return addNode(&((*program)->next),node);
  }
}

void printLogo(Program program, int indent) {
  if (program == NULL)
    return;
  int i;
  for (i=0;i<indent;++i)
    printf("\t");
  switch (program->instruction) {
    case FORWARD:
      printf("FORWARD %d", program->value);
      break;
    case LEFT:
      printf("LEFT %d", program->value);
      break;
    case RIGHT:
      printf("RIGHT %d", program->value);
      break;
    case REPEAT:
      printf("REPEAT %d [\n", program->value);
      printLogo(program->subNode, indent+1);
      for (i=0;i<indent;++i)
        printf("\t");
      printf("]");
      break;
    default:
      printf("UNKNOWN %d", program->value);
  }
  printf("\n");
  printLogo(program->next, indent);
}

void writeSVGLine(FILE* svg, double x, double y, Pen pen) {
  fprintf(
    svg,
    "<line x1=\"%.3f\" y1=\"%.3f\" x2=\"%.3f\" y2=\"%.3f\" stroke=\"black\" />\n",
    x,y,
    pen.x,pen.y
  );
}

void writeSVGInstruction(FILE* svg, Program program, Pen* pen) {
  if (program == NULL)
    return;
  double xOld, yOld;
  int i;
  switch (program->instruction) {
    case FORWARD:
      xOld = pen->x;
      yOld = pen->y;
      movePen(pen,program->value);
      writeSVGLine(svg,xOld,yOld,*pen);
      break;
    case LEFT:
    case RIGHT:
      rotatePen(pen,program->instruction,program->value);
      break;
    case REPEAT:
      for (i=0;i<program->value;++i) {
        writeSVGInstruction(svg,program->subNode,pen);
      }
      break;
    default:
      perror("Instruction non identifiée !");
  }
  writeSVGInstruction(svg,program->next,pen);
}

void writeSVG(Program program, char* name) {
    FILE* svg = fopen(name,"w+");
    // write svg headers
    fprintf(svg,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
    // TODO Calculer la taille du dessin ! (et centrer le Pen ?)
    fprintf(svg,"<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"300\" height=\"200\">\n");
    fprintf(svg,"<title>%s</title>\n",name);
    Pen pen;
    pen.x = 50.0;
    pen.y = 50.0;
    pen.alpha = 0.0;
    writeSVGInstruction(svg,program,&pen);
    fprintf(svg,"</svg>\n");
    fclose(svg);
}
