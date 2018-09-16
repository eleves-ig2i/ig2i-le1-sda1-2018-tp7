#include "pile.h"

void init(T_Pile *pp)
{
pp->Sp=0;
}

int pilePleine(T_Pile *pp)
{
return (pp->Sp==TAILLE);
}

int empiler(T_Pile *pp,T_Elt e) //push
{
if (!(pilePleine(pp)))
{
//	pp->data[pp->Sp+1]=e;   
	ranger(&(pp->data[pp->Sp+1]),e);
	pp->Sp++;
	return 1;
}
else return 0;
}

int depiler(T_Pile *pp,T_Elt* pe) //pop
{
if (!pileVide(pp))
{
//*pe=pp->data[pp->Sp]; 
 ranger(pe,pp->data[pp->Sp]);
pp->Sp--;
return 1;
}
else return 0;
}

int pileVide(T_Pile *pp)
{
return (pp->Sp==0);
}

void afficher(T_Pile *pp)
{
T_Pile ptemp;
T_Elt E;
int i;
init(&ptemp);
for(i=pp->Sp;i>=1;i--) //on dépile la pile à afficher
	{
	depiler(pp,&E);
	afficherElt(E);//à écrire dans es.c
	empiler(&ptemp,E); //reconstitution d'une pile temporairement (inverse à la pile à afficher) 
	}
for(i=ptemp.Sp;i>=1;i--)//reconstruction de la pile initiale
	{
	depiler(&ptemp,&E);
	empiler(pp,E);
	}
}


T_Elt sommet(T_Pile *pp)
{
return (pp->data[pp->Sp]);

}




