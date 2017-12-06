#include "pen.h"

void InitPen(Pen* pen) {
  pen->active = 1;
  pen->x = 0.0;
  pen->y = 0.0;
  pen->alpha = 0.0;
  pen->red = 0;
  pen->green = 0;
  pen->blue = 0;
}

double getInRadians(int a) {
  return (double)(a * PI / 180.0);
}

void rotatePen(Pen* pen, Instruction sig, int dalpha) {
  double da = getInRadians(dalpha);
  switch (sig) {
    case LEFT:
      pen->alpha -= da;
      break;
    case RIGHT:
      pen->alpha += da;
      break;
    default:
      perror("Bad usage of rotatePen !");
  }
}

void movePen(Pen* pen, int value) {
  pen->x += (double)(value*cos(pen->alpha));
  pen->y += (double)(value*sin(pen->alpha));
}
