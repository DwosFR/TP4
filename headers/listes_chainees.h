/**************************************************************
Auteur : Valynseele Alexis
Date :  10/12/2019 - Seance 2
Titre : TP 4 - DA (9h)
Fichier .h : prototype des fonctions de listes_chainees.c

**************************************************************/

//Pre-processeur

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

//Prototypes

typedef struct Cell
{
    char *mot;
    struct Cell *suivant;
} Cellule_Chaine;

typedef Cellule_Chaine *Liste_Cellule_Chaine;

typedef Liste_Cellule_Chaine *tabListes;


tabListes initialisationTabListes();
void creationTabListes(tabListes tab, char **tabMots, int nb);
void afficherTabListes(tabListes tab);
bool rechercheMotTabMots(char **tabMots, int nb, char mot[], int *indice, double *cpu_time_used);
bool rechercheMotTabListes(tabListes tab, char mot[], int *indice, double *cpu_time_used);
void affichageRechercheStringTabListes(tabListes tab,char string[]);
void freeTabListes(tabListes tab);
void testPartieII();