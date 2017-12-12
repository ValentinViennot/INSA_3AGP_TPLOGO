#ifndef LOGO_TYPE
#define LOGO_TYPE

typedef enum {
  FORWARD,
  LEFT,
  RIGHT,
  REPEAT,
  HIDE,
  SCALE,
  DCOLOR, COLOR
} Instruction;

typedef struct model_step {
  Instruction instruction;
  int value;
  struct model_step* next;
  struct model_step* subNode;
} Node;

typedef Node* Program;

#endif
