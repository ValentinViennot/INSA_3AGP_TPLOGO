# Compilateur LOGO simple

## Grammaire

FINAL : NAME NOM PROG | PROG

PROG : INST | PROG INST

INST :   FORWARD VALUE  
         LEFT VALUE  
         RIGHT VALUE  
         REPEAT VALUE '[' PROG ']'

VALUE : integer
NOM : [a-zA-Z][a-zA-Z0-9]{0,44}".svg"

## Extensions

Au programme initialement demandé ont été rajouté des instructions complémentaires.

### NAME
Au début du programme il est possible d'utiliser la commande "NAME [a-zA-Z][a-zA-Z0-9]{0,44}".svg"" pour choisir le nom du fichier .svg de destination.
Le nom du fichier servira également à definir la balise <title> du fichier .svg.
Le nom utilisé est limité à 45 caractères alphanumériques, doit obligatoirement commencer par une lettre (minuscule ou majuscule) et terminer par l'extension ".svg".

### SCALE S
Après cette instruction, tous les déplacements effectués seront S (VALUE) fois plus grands.

### Aliases
Un alias est un terminal qui au sera interprété en une suite d'instructions à la lecture.

#### RECT L H 
Trace un rectangle de largeur L (VALUE) et de hauteur H (VALUE).

### CIRCLE S
Trace un cercle en se mettant à l'échelle S (VALUE).