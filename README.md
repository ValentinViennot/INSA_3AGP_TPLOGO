# Compilateur LOGO

## Grammaire

FINAL : PROG

PROG : NAME NOM PROG | INST | PROG INST

INST :   FORWARD VALUE  
         LEFT VALUE  
         RIGHT VALUE  
         REPEAT VALUE '[' PROG ']'
         (GOTOX|GOTOY) VALUE
         COLOR COLORNAME VALUE
         COLOR COLORNAME DELTA VALUE
         SCALE VALUE
         RECT VALUE VALUE
         POLYGON VALUE VALUE
         CIRCLE VALUE

VALUE : integer
NOM : [a-zA-Z][a-zA-Z0-9]{0,44}".svg"
DELTA : "+"|"-"
COLORNAME : "RED"|"GREEN"|"BLUE"

## Extensions

Au programme initialement demandé ont été rajouté des instructions complémentaires.

### Expressions mathématiques
// TODO 

### Variables
// TODO (attention ! une initialisation doit être contenue dans une instruction)
// Attention une boucle REPEAT garde la variable constante, utilisez une boucle for instead

FORWARD i=100
RIGHT 90
FORWARD i

### NAME
Au début du programme il est possible d'utiliser la commande "NAME [a-zA-Z][a-zA-Z0-9]{0,44}".svg"" pour choisir le nom du fichier .svg de destination.
Le nom du fichier servira également à definir la balise <title> du fichier .svg.
Le nom utilisé est limité à 45 caractères alphanumériques, doit obligatoirement commencer par une lettre (minuscule ou majuscule) et terminer par l'extension ".svg".

### SCALE S
Après cette instruction, tous les déplacements effectués seront S (VALUE) fois plus grands.

### COLOR
// TODO et TODO deltas

### HIDE / SHOW
// TODO

### GOTO 
// TODO

### Aliases
Un alias est un terminal qui au sera interprété en une suite d'instructions à la lecture.

#### RECT L H 
Trace un rectangle de largeur L (VALUE) et de hauteur H (VALUE).

#### POLYGON N L
Trace un polygone régulier de N (VALUE) côtés de longueur L (VALUE).

#### CIRCLE S
Trace un cercle en se mettant à l'échelle S (VALUE).