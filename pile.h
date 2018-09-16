#include "es.h"

#define TAILLE 5

typedef struct
{
T_Elt data[TAILLE+1];//on empile rien en case 0
int Sp; //Stack Pointer
} T_Pile;

//PROTOtypes
void init(T_Pile *);

int empiler(T_Pile *,T_Elt);
int pilePleine(T_Pile *);

int depiler(T_Pile *,T_Elt*);
int pileVide(T_Pile *);

void afficher(T_Pile *);
T_Elt sommet(T_Pile *);






