/**************************************************************
Auteur : Valynseele Alexis
Date :  10/12/2019 - Seance 3
Titre : TP 4 - DA (9h)
Fichier C : Fichier contenant les fonctions en rapport avec la Partie III
**************************************************************/

//Pre-processeur

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

//Fonction testant les différentes fonctions de listes_chainees.c (Partie II du TP)
void testPartieIII()
{
    char menu1;
    printf("Test de la partie III :\n\n");
    do
    {
        printf("=================================================\n\n");
        printf("< 1 > Test \n");
        printf("< 0 > Quitter le programme\n\n");
        printf("=================================================\n\n");
        printf("votre choix: \t");
        while((menu1=getchar()) == 10);
        printf("\n");
        switch (menu1)
        {
        case '0':
            printf("fin du programme Test Partie II\n");
            break;
        case '1':
            printf("Test\n");
            break;
        default:
            printf("erreur: commande inconnue (%d)\n", menu1);
            break;
        }
    } while (menu1 != '0');
}