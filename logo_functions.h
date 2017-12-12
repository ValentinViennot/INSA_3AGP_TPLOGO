#ifndef LOGO_FN
#define LOGO_FN

#include <stdlib.h>
#include <stdio.h>

#include "logo_type.h"
#include "pen.h"

/**
* \brief Initialise un nouveau 'Program' Logo
*/
Program InitLogo();

/**
* \brief Libère la mémoire allouée via malloc pour les noeuds de program
* \pre program Un pointeur vers un programme valide
* \post *program vaut NULL et toute la mémoire précédemment occupée par les Node de de program a été free()
*/
void freeLogo(Program* program);

/**
* \brief Alloue l'espace mémoire nécessaire (malloc) pour un Node et le rempli avec les données passées
* \param instruction Instruction contenue dans ce noeud
* \param value Valeur entière associée au noeud
* \result Retourne un pointeur sur l'élément Node qui vient d'être créé
*/
Node* createNode(Instruction instruction, int value, Program subNode);

/**
* \brief Ajoute un nouveau noeud Node à la fin de program
* \param program un pointeur sur un Program valide
* \param node un pointeur sur un Node valide
*/
void addNode(Program* program, Node* node);

/*
* \brief Affiche les instructions d'un Program Logo ligne par ligne en console
* \param indent Niveau d'indendation des instructions à afficher
*/
void printLogo(Program program, int indent);

/**
* \brief Interpréte les instructions contenues dans Program pour écrire un fichier .svg nommé par name
* \param name Une chaîne de caractères contenant le nom du fichier 
* \pre name doit terminer par ".svg", ne contenir que des lettres (majuscules ou minuscules) et au moins une lettre
* \param program Le Program Logo à interpréter
*/
void writeSVG(Program program, char* name);


#endif
