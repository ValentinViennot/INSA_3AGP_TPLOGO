#ifndef PEN_TYPE
#define PEN_TYPE

#include "logo_type.h"

typedef struct {
  double x;
  double y;
  float alpha;
} Pen;

/**
* \post pen->alpha += radians(dalpha)
* \param dalpha Delta angle in degrees (unsigned value)
* \param LEFT or RIGHT
*/
void rotatePen(Pen* pen, Instruction sig, int dalpha);

/**
* \brief Moves pen forward
*/
void movePen(Pen* pen, int value);

#endif
