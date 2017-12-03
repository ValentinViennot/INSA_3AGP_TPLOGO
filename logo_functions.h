#ifndef LOGO_FN
#define LOGO_FN

#include <stdlib.h>
#include <stdio.h>
#include "logo_type.h"

/**
* \brief Init a new Logo Program structure
*/
Program InitLogo();

/**
* \brief Malloc and populate a new Node
* \param instruction Type of Instruction
* \result Return a pointer to the newly created Node
*/
Node* createNode(Instruction instruction, int value, Program* subNode);

/**
* \brief Append a new Node at the end of the Program
*/
void addNode(Program* program, Node* node);

/*
* \brief Displays a Logo Program line / line
* \param indent Spacing
*/
void printLogo(Program program, int indent);


#endif
