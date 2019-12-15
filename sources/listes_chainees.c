/**************************************************************
Auteur : Valynseele Alexis
Date :  10/12/2019 - Seance 2
Titre : TP 4 - DA (9h)
Fichier C : Fichier contenant les fonctions en rapport avec la Partie II

**************************************************************/

//Pre-processeur

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include "../headers/tab_mots_dynamique.h"

//Fonction testant les différentes fonctions de listes_chainees.c (Partie II du TP)
void testPartieII()
{
    char menu1;
    int temp;
    char **tabMots;
    int nb = 0;

    printf("Test de la partie I :\n\n");
    do
    {
        printf("=================================================\n\n");
        printf("< 1 > Creation d'un tableau dynamique(liste_dev.txt)\n");
        printf("< 2 > Affichage du tableau (liste_dev.txt)\n");
        printf("< 0 > Quitter le programme\n\n");
        printf("=================================================\n\n");
        printf("votre choix: \t");
        while ((menu1 = getchar()) == 10)
            ;
        printf("\n");
        switch (menu1)
        {
        case '0':
            printf("fin du programme Test Partie I\n");
            break;
        case '1':
            nb = nbMots("./files/liste_dev.txt");
            tabMots = creationTabMotsDynamique("./files/liste_dev.txt", nb);
            break;
        case '2':
            printf("Combien de valeurs du tableau voulez vous afficher?(0 pour tout afficher)\n");
            scanf("%d", &temp);
            if (temp != 0)
                affichageTabMotsDynamique(tabMots, temp);
            if (temp == 0)
                affichageTabMotsDynamique(tabMots, nb);
            break;
        default:
            printf("erreur: commande inconnue (%d)\n", menu1);
            break;
        }
    } while (menu1 != '0');
}