/**************************************************************
Auteur : Valynseele Alexis
Date :  26/11/2019 - Seance 1
Titre : TP 4 - DA (9h)
Fichier .h : prototype des fonctions de ma_bibliotheque

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