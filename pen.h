#ifndef PEN_TYPE
#define PEN_TYPE

#include <math.h>
#include <stdio.h>
#include "logo_type.h"

#define PI 3.14159265

typedef struct {
  double x;
  double y;
  // radius in radians
  double alpha;
} Pen;

/**
* \post pen->alpha += radians(dalpha)
* \param dalpha Delta radius in degrees (unsigned value)
* \param LEFT or RIGHT
*/
void rotatePen(Pen* pen, Instruction sig, int dalpha);

/**
* \brief Moves pen forward
*/
void movePen(Pen* pen, int value);

#endif
