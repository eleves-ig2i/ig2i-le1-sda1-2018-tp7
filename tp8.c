#include "pile.h"
//#include "file.h"

//Ligne ci dessous à décommenter si jamais il y a un probleme
//#define __MODE_DEBUG__

//MACRO FONCTION 
#define  remonterAuPere(pp,pe)  depiler(pp,pe)

#define passerAuPremierFils(pp) empiler(pp,1)

#define passerAuFrereSuivant(pp,pe) depiler(pp,pe),empiler(pp,*pe+1)

#define noeudTerminal(pp,chaine) pp->Sp==strlen(chaine)

#define rechercheTerminee(pp) pp->Sp==0

#define naPlusDeFrere(pp,chaine) pp->data[pp->Sp]==strlen(chaine)

#define TRUE 1
#define FALSE 0
#define MAXCAR 20
#define MAXCARPARLIGNE 80


int permut(T_Pile *, char *);
int noeudValide(T_Pile );
void afficherSolution(T_Pile, int,char *,int*);


int main()  // 4 : pour la recherche des permutations
{
	//declarations 
	T_Pile p;
	int R;
	char machaine[MAXCAR];

	init(&p);

	printf("\n saisir votre chaine à permuter : ");
	scanf("%s",machaine);
	
	R=permut(&p,machaine);
	printf("\n il y a %d solutions ",R);
	return 0;
}//main


int permut(T_Pile *pPile, char *maChaine) {
	int position;
	int noeudterminal;
	int nombreDeSolutions = 0;
	int nbMotsParLigne = MAXCARPARLIGNE/(strlen(maChaine)+1)-1;	//le +1 c'est pour l'espace, le -1 c'est pour \n
	int nbMotsRestantDansLigne = nbMotsParLigne;
#ifdef __MODE_DEBUG__
	printf("\n Nombre de mots par lignes = %d",nbMotsParLigne);
#endif

	do {
		// 1) Tant que le noeud courant est valide
		noeudterminal=FALSE;
		while( noeudValide(*pPile) && noeudterminal == FALSE ) {
			// si c'est un noeud terminal
			if (noeudTerminal(pPile, maChaine)) {
#ifdef __MODE_DEBUG__
				printf("\nNoeud terminal : 1\n");
				afficher(pPile);
				printf("\n");
#endif
                afficherSolution(*pPile,strlen(maChaine),maChaine,&nbMotsRestantDansLigne);
				//Si jamais on a sauté une ligne
				if(nbMotsRestantDansLigne == -1) nbMotsRestantDansLigne=nbMotsParLigne-1;
				nombreDeSolutions++;
				noeudterminal = TRUE;
			}
				//si c'est pas un noeud terminal
			else {
#ifdef __MODE_DEBUG__
				printf("\nOn passe au fils avec une taille de %d",pPile->Sp);
#endif
				passerAuPremierFils(pPile);
			}
		}
		// 2) Tant que la recherche n'est pas terminée et noeud courant n'a plus de freres
		while( rechercheTerminee(pPile) == 0 && naPlusDeFrere(pPile,maChaine) ) {
#ifdef __MODE_DEBUG__
			printf("\nOn remonte au père avec une taille de %d",pPile->Sp);
#endif
			remonterAuPere(pPile,&position);
		}

		//3) Si la recherche n'est pas terminée
		if ( rechercheTerminee(pPile) == 0 ) {
#ifdef __MODE_DEBUG__
			printf("\nOn passe au frère suivant avec une taille de %d", pPile->Sp);
#endif
			passerAuFrereSuivant(pPile,&position);
		}
	}while( !rechercheTerminee(pPile) );
	return nombreDeSolutions;
}



int noeudValide(T_Pile Pile) {
	T_Elt lastValue;
#ifdef __MODE_DEBUG__
	printf("\nNoeud à tester");
	afficher(&Pile);
#endif

	depiler(&Pile, &lastValue);

	while (!pileVide(&Pile)) {
		T_Elt auxValue;
		depiler(&Pile, &auxValue);
		if (auxValue == lastValue) {
			return FALSE;
		}
	}
	return TRUE;
}


void afficherSolution(T_Pile pileAAfficher,int taillemot,char* mot,int *placeRestanteDansLigne ) {
	char solution[MAXCAR];
	int pilePos;
	int position = taillemot-1;	//On commence à taillemot-1
	solution[taillemot]='\0';

	//On forme la chaîne de caractères solution
	while( depiler(&pileAAfficher,&pilePos) ) {
#ifdef __MODE_DEBUG__
		printf("\n mot[%d] == %c",pilePos-1,mot[pilePos-1]);
#endif
		solution[position]=mot[pilePos-1];
		position--;
	}

	if( *placeRestanteDansLigne == 0) {
		printf("\n%s", solution);
	}
	else {
		printf(" %s",solution);
	}
	(*placeRestanteDansLigne)--;
#ifdef __MODE_DEBUG__
	printf("\n placeRestanteDansLigne == %d",*placeRestanteDansLigne);
#endif

}











