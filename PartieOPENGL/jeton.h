#ifndef JETON_H
#define JETON_H
//�num�ration des diff�rents types de lexems existants
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
	REEL,
	OPERATEUR,
	FONCTION,
	ERREUR,
	FIN,
	PAR_OUV,
	PAR_FERM,
	VARIABLE,
	ABSOLU
} typelexem;
//�num�ration des diff�rents types d'op�rateurs existants
typedef enum { PLUS, MOINS, FOIS, DIV, PUISS } typeoperateur;



//�num�ration des diff�rents types de fonctions �xistantes
typedef enum {
	ABS,
	SIN,
	SQRT,
	LOG,
	COS,
	TAN,
	EXP,
	ENTIER,
	VAL_NEG,
	SINC
} typefonction;
//�num�ration des diff�rents types d'erreurs �xistantes
typedef enum { AREMPLIR } typeerreur;
//�num�ration des diff�rents types de valeurs �xistantes
typedef union {
	float reel;
	typefonction fonction;
	typeoperateur operateur;
	typeerreur erreur;
} typevaleur;
//�num�ration des diff�rents types de jetons �xistants
typedef struct {
	typelexem lexem;
	typevaleur valeur;
} typejeton;
// d�claration de l'arbre
typedef struct Node {
	typejeton jeton;
	struct Node* pjeton_preced;
	struct Node* pjeton_suiv;
} Node;
typedef Node* Arbre;

#endif