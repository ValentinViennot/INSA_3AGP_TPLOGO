#include "pen.h"

void InitPen(Pen* pen) {
  resetPen(pen);
  pen->x0 = 0.0;
  pen->y0 = 0.0;
  pen->width = 0.0;
  pen->height = 0.0;
}

void resetPen(Pen* pen) {
  pen->active = 1;
  pen->x = 0.0;
  pen->y = 0.0;
  pen->scale = 1;
  pen->alpha = 0.0;
  pen->rgb[0] = 0;
  pen->rgb[1] = 0;
  pen->rgb[2] = 0;
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
  value *= pen->scale;
  pen->x += (double)(value*cos(pen->alpha));
  pen->y += (double)(value*sin(pen->alpha));
}

void changePenColor(Pen* pen, int index, int value) {
  while (value<0) value += 255;
  pen->rgb[index] = value%256;  
}
