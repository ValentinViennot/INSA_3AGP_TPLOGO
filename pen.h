#ifndef PEN_TYPE
#define PEN_TYPE

#include <math.h>
#include <stdio.h>
#include "logo_type.h"

#define PI 3.14159265

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef struct {
  int active; // Stylo posé ? ou levé (false)
  double x, y; // Coordonnées du stylo
  double x0, y0; // Coordonnées initiales
  double width, height; // Taille du dessin
  int scale; // Mise à l'échelle (facteur du FORWARD)
  double alpha; // Orientation d'écriture du stylo dans le plan 2D de la feuille
  int rgb[3]; // Couleur du stylo au format RGB : int[3] {RED,GREEN,BLUE}
} Pen;

/**
* \brief Initialise un nouveau stylo
* \post Les coordonnées sont à 0, le stylo se dirige vers la droite et sa couleur est le Noir, les conditions initiales sont à 0.
*/
void InitPen(Pen* pen);
/**
* \brief Remet à zéro un stylo, excepté ses conditions initiales
* \post Les coordonnées sont à 0, le stylo se dirige vers la droite et sa couleur est le Noir.
*/
void resetPen(Pen* pen);

/**
* \post Le stylo a pivoté de dalpha degrés dans le sens défini par sig
* \param dalpha Delta d'angle en degrés
* \param sig Instruction de valeur LEFT ou RIGHT, défini le sens de rotation du stylo (LEFT : sens trigonométrique)
*/
void rotatePen(Pen* pen, Instruction sig, int dalpha);

/**
* \brief Avance le stylo de la valeur value dans sa direction actuelle
*/
void movePen(Pen* pen, int value);

/**
* \brief Modifie la couleur du stylo
* \param index Couleur à modifier (0: Rouge, 1: Vert, 2: Bleu)
* \param value Valeur à attribuer à la couleur modifiée
* \post La couleur index vaut value sauf si value est <0 (dans ce cas vaut 0) ou >255 (discontinuité, modulo 255)
*/
void changePenColor(Pen* pen, int index, int value);

#endif
