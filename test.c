#include <stdlib.h>

#include "logo_type.h"
#include "logo_functions.h"

#define PSIZE 6

int main(int argc, char const *argv[]) {

  Program myLogo = InitLogo();
  Program loop1 = InitLogo();
  Program loop2 = InitLogo();
  Node* node[PSIZE];

  node[0] = createNode(FORWARD,100,NULL);
  node[1] = createNode(REPEAT,4,&loop1);
  node[2] = createNode(FORWARD,50,NULL);
  node[3] = createNode(REPEAT,2,&loop2);
  node[4] = createNode(LEFT,45,NULL);
  node[5] = createNode(FORWARD,100,NULL);

  addNode(&myLogo,node[0]);
  addNode(&myLogo,node[1]);
  addNode(&loop1,node[2]);
  addNode(&loop1,node[3]);
  addNode(&loop2,node[4]);
  addNode(&myLogo,node[5]);

  printLogo(myLogo,0);

  int i;
  for (i=0;i<PSIZE;++i)
    free(node[i]);

  return 0;
}
