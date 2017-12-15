# Compilateur LOGO

## Grammaire

FINAL : PROG
  
PROG : NAME NOM PROG | INST | PROG INST
  
INST : 
    FORWARD VALUE  
    LEFT VALUE  
    RIGHT VALUE  
    REPEAT VALUE '[' PROG ']'  
    (GOTOX|GOTOY) VALUE  
    COLOR COLORNAME VALUE  
    COLOR COLORNAME DELTA VALUE  
    SCALE VALUE  
    HIDE  
    SHOW  
    X VALUE | Y VALUE  
    RECT VALUE VALUE  
    POLYGON VALUE VALUE  
    CIRCLE VALUE  

VALUE : EXPR  
  
EXPR : EXPR '+' TERM | EXPR '-' TERM | TERM  
TERM : TERM '*' FACTOR | TERM '/' FACTOR | FACTOR  
FACTOR : ENTIER | '-'FACTOR | VARIABLE | '(' EXPR ')'  
  
VARIABLE : VAR | VARIABLE '=' VALUE  
  
VAR : [a-z]{1}  
ENTIER : [1-9][0-9]*|0  
NOM : [a-zA-Z][a-zA-Z0-9]{0,44}".svg"  
COLORNAME : "RED"|"GREEN"|"BLUE"  

## Extensions

Au programme initialement demandé ont été rajouté des instructions complémentaires.

### Expressions mathématiques
Les valeurs peuvent être exprimées sous la forme d'une expression mathématique utilisant des entiers signés ou non, des parenthèses et les opérateurs + , - , * et / 

### Variables
Des lettres minuscules peuvent être utilisées pour remplacer des valeurs. Il faut penser à initialiser la valeur de la variable.
ATTENTION : Une initialisation doit être contenue dans une instruction !  

Fonctionne :  
FORWARD i=100  
  
Ne fonctionne pas :  
i=100  
FORWARD i  
  
ATTENTION : Les variables sont interprétées à la lecture du programme par bison. Ainsi, une boucle REPEAT garde la variable constante.

### NAME
Au début du programme il est possible d'utiliser la commande "NAME [a-zA-Z][a-zA-Z0-9]{0,44}".svg"" pour choisir le nom du fichier .svg de destination.  
Le nom du fichier servira également à definir la balise <title> du fichier .svg.
Le nom utilisé est limité à 45 caractères alphanumériques, doit obligatoirement commencer par une lettre (minuscule ou majuscule) et terminer par l'extension ".svg".

### SCALE S
Après cette instruction, tous les déplacements effectués seront S (VALUE) fois plus grands.

### COLOR
Le mode RGB a été choisi pour définir les couleurs. Les couleurs Rouge, Vert et Bleu peuvent varier entre 0 et 255.  
Exemple pour attribuer la valeur 200 la couleur rouge : COLOR RED 200 ou RED 200  
Exemple pour faire augmenter la valeur de bleu de 120 : COLOR BLUE DELTA 120 ou BLUE DELTA 120  
Exemple pour faire diminuer la valeur de vert de 20 : COLOR GREEN DELTA -20 ou GREEN DELTA -20  

### HIDE / SHOW
On peut choisir de "lever le stylo" et de ne plus dessiner tout en continuant à avancer :  
Pour lever le stylo , commande "HIDE"  
Pour poser le stylo , commande "SHOW"  
Par défaut, le stylo est posé.

### GOTO 
On peut amener directement le stylo à des coordonnées déterminées sans laisser de traces en spécifiant sa coordonnée X et / ou Y  
Exemples :  
X 100  
X 50 Y 20  
Y -100  
  
Les coordonnées sont des coordonnées absolues.

### Aliases
Un alias est un terminal qui au sera interprété en une suite d'instructions à la lecture.

#### RECT L H 
Trace un rectangle de largeur L (VALUE) et de hauteur H (VALUE).

#### POLYGON N L
Trace un polygone régulier de N (VALUE) côtés de longueur L (VALUE).

#### CIRCLE S
Trace un cercle unité en se mettant à l'échelle S (VALUE).