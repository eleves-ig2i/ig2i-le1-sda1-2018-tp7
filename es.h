#ifndef ES_H_INCLUDED
#define ES_H_INCLUDED
 

#include <stdio.h>
#include <string.h>

/*
//le TAD pourrait etre un T_Livre
typedef struct
{
char titre[20];
int annee;
} T_Livre;
typedef T_Livre  T_Elt;
*/



	typedef int  T_Elt; // TAD : type abstrait de données

void saisirElt(T_Elt*);
int ranger(T_Elt* ,T_Elt );
void afficherElt(T_Elt);

#endif
