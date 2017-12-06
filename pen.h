#ifndef PEN_TYPE
#define PEN_TYPE

#include <math.h>
#include <stdio.h>
#include "logo_type.h"

#define PI 3.14159265

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef struct {
  // write or not to write ?
  int active;
  double x;
  double y;
  // radius in radians
  double alpha;
  // color
  int rgb[3];
  int red, green, blue;
} Pen;

void InitPen(Pen* pen);

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

void changePenColor(Pen* pen, int index, int value);

#endif
