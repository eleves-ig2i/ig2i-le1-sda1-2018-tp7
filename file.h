#include "es.h"

#define TAILLE 5

typedef struct
{
T_Elt data[TAILLE+1];//on emfile rien en case 0
int fl; //File Lenght
} T_File;

//PROTOtypes
void initFile(T_File *);

int enfiler(T_File *,T_Elt);
int filePleine(T_File *);

int defiler(T_File *,T_Elt*);
int fileVide(T_File *);

void afficherFile(T_File *);

T_Elt premier(T_File *);






