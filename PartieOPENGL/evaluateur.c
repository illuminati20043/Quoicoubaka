#include "evaluateur.h"


float Evaluateur(Node* A, float X)
{

	switch (A->jeton.lexem) {

	case REEL:

		return A->jeton.valeur.reel;
		break;
	case VARIABLE:
		A->jeton.valeur.reel = X;
		return A->jeton.valeur.reel;

	case OPERATEUR:
			switch (A->jeton.valeur.operateur) {

			case PLUS:
				return Evaluateur(A->pjeton_preced, X) + Evaluateur(A->pjeton_suiv, X);
				break;
			case MOINS:
				return Evaluateur(A->pjeton_preced, X) - Evaluateur(A->pjeton_suiv, X);
				break;
			case FOIS:
				return Evaluateur(A->pjeton_preced, X) * Evaluateur(A->pjeton_suiv, X);
				break;
			case PUISS:
				return powf(Evaluateur(A->pjeton_preced, X), Evaluateur(A->pjeton_suiv, X));
				break;
			default:
				printf("non");
				return 0;
				break;




	}
	case FONCTION:
		switch (A->jeton.valeur.fonction) {
		case SIN:
			return sin(Evaluateur(A->pjeton_preced), X);
			break;
		case COS:
			return cosf(Evaluateur(A->pjeton_preced), X);
			break;
		case TAN:
			return tanf(Evaluateur(A->pjeton_preced), X);
			break;
		case EXP:
			return expf(Evaluateur(A->pjeton_preced), X);
			break;
		case LOG:
			return logf(Evaluateur(A->pjeton_preced), X);
			break;
		case ENTIER:
			return floor(Evaluateur(A->pjeton_preced), X);
			break;
		case VAL_NEG:
			return -abs(Evaluateur(A->pjeton_preced), X);
			break;
		case SINC:
			return sin(Evaluateur(A->pjeton_preced), X);
			break;
		default:
			printf("Bad function");
			return 0;

		}

	}




}


float* Eval_Arbre_Range_x(struct Node* Arbre, float x_min, float x_max, int n) {
	float step = (x_max - x_min) / (n - 1);
	float x_temp;
	float* resultsx = malloc(n * sizeof(float));

	for (int i = 0; i < n; i++) {
		x_temp = x_min + i * step;
		resultsx[i] = x_temp;
	}
	return resultsx;
}
float* Eval_Arbre_Range_y(struct Node* Arbre, float x_min, float x_max, int n) {
	float step = (x_max - x_min) / (n - 1);
	float x_temp;
	float y_temp;
	float* resultsy = malloc(n * sizeof(float));

	for (int i = 0; i < n; i++) {
		x_temp = x_min + i * step;
		y_temp = Parcourir(Arbre, x_temp);
		resultsy[i] = y_temp;
	}
	return resultsy;
}




Node Node8 = { {REEL,{.reel = 3}},NULL,NULL };
Node Node7 = { {VARIABLE,{.reel = 0}},NULL,NULL };
Node Node6 = { {OPERATEUR,{.operateur = PLUS}},&Node7,&Node8 };
Node Node5 = { {FONCTION,{.fonction = SIN}},&Node6,NULL };
Node Node4 = { {REEL,{.reel = 6}},NULL,NULL };
Node Node3 = { {OPERATEUR,{.operateur = FOIS}},&Node4,&Node5 };
Node Node2 = { {REEL,{.reel = 4}},NULL,NULL };
Node Node1 = { {OPERATEUR,{.operateur = PLUS}},&Node2,&Node3 };
