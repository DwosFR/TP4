/**************************************************************
Auteur : Valynseele Alexis
Date :  26/11/2019 - Seance 1
Titre : TP 4 - DA (9h)
Fichier .h : prototype des fonctions de tab_mots_dynamique.c

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

int nbMots(char nom[]);
char **creationTabMotsDynamique(char nom[], int nbMots);
void affichageTabMotsDynamique(char **tabMots, int nbMots);
void affichageRechercheString(char **tabMots, int nbMots, char string[]);
void ajoutMotFindeFichier(char nom[], char string[]);
void ajoutMotLigneIFichier(char nom[],char string[],int pos,int nbMots);
void freeTabMotsDynamique(char **tabMots, int nbMots);
void triLexicographiqueABulles(char **tabMots, int nbMots, double *cpu_time_used);
void ecritureTabMotsFichier(char nom[], char **tabMots, int nbMots);
void creationBareme(char nom[], int bareme[25]);
void calculPoints(char **tabMots, int nbMots, int *scoreMax, int *nbScoreMax);
void calculPointsBareme(char nomBareme[], char **tabMots, int nbMots, int *scoreMax, int *nbScoreMax);
int compareLongueur(const void *a, const void *b);
int compareLexicographique(const void *a, const void *b);
void triQsort(char **tabMots, int nbMots, double *cpu_time_used, int (*compare)(const void *,const void *));
char **ajoutMotTabIndiceI(char **tabMots, int *nbMots,int indice, char string[]);
void testPartieI();