/**************************************************************
Auteur : Valynseele Alexis
Date :  26/11/2019 - Seance 1
Titre : TP 4 - DA (9h)
Fichier C : Repertoire de fonctions sans rapport direct avec le probleme

**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include "../headers/tab_mots_dynamique.h"
#include "../headers/listes_chainees.h"

//Fonction affichant un menu permettant de lancer les différentes fonctions tests du programme
void menu()
{
    char menu1;
    printf("Valynseele Alexis - TP4\n\n");
    do
    {
        printf("=================================================\n\n");
        printf("< 1 > Partie I\n");
        printf("< 2 > Partie II\n");
        printf("< 3 > Partie III\n");
        printf("< 0 > Quitter le programme\n\n");
        printf("=================================================\n\n");
        printf("votre choix: \t");
        while ((menu1 = getchar()) == 10);
        printf("\n");
        switch (menu1)
        {
        case '0':
            printf("fin du programme\n");
            break;
        case '1':
            testPartieI();
            break;
        case '2':
            testPartieII();
            break;
        default:
            printf("erreur: commande inconnue\n");
            break;
        }
    } while (menu1 != '0');
}
