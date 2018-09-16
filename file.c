#include "file.h"

void initFile(T_File *pf)
{
pf->fl=0;
}

int filePleine(T_File *pf)
{
return (pf->fl==TAILLE);
}

int enfiler(T_File *pf,T_Elt e) 
{
if (!(filePleine(pf)))
{

	ranger(&(pf->data[pf->fl+1]),e);
	pf->fl++;
	return 1;
}
else return 0;
}

int defiler(T_File *pf,T_Elt* pe) 
{
int i;
if (!fileVide(pf))
{
 ranger(pe,pf->data[1]);
 for(i=1;i<pf->fl;i++) //tout le monde avance dans la file
	pf->data[i]=pf->data[i+1];
 pf->fl--;

return 1;
}
else return 0;
}

int fileVide(T_File *pf)
{
return (pf->fl==0);
}

void afficherFile(T_File *pf)
{int i;
for(i=1;i<=pf->fl;i++) 
	{
	afficherElt(pf->data[i]);//à écrire dans es.c
	}
}


T_Elt premier(T_File *pf)
{
return (pf->data[1]);	
}




