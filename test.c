#include <stdlib.h>

#include "logo_type.h"
#include "logo_functions.h"

int main(int argc, char const *argv[]) {

  Program myLogo = InitLogo();
  Program loop1 = InitLogo();
  Program loop2 = InitLogo();

  addNode(&loop2,createNode(LEFT,45,NULL));

  addNode(&loop1,createNode(FORWARD,50,NULL));
  addNode(&loop1,createNode(REPEAT,2,loop2));

  addNode(&myLogo,createNode(FORWARD,100,NULL));
  addNode(&myLogo,createNode(REPEAT,4,loop1));
  addNode(&myLogo,createNode(FORWARD,100,NULL));

  printLogo(myLogo,0);

  writeSVG(myLogo,"svg.svg");

  freeLogo(&myLogo);

  return 0;
}
