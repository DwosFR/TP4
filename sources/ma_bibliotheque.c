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
#include "..\headers\tab_mots_dynamique.h"

//Fonction testant les différentes fonctions de tab_mots_dynamique.c (Partie I du TP)
void testPartieI()
{
    int nb = nbMots(".\\files\\liste_dev.txt");
    double cpu_time_used = 0;
    int scoreMax;
    int nbScoreMax;
 
    char **tabMots = creationTabMotsDynamique(".\\files\\liste_dev.txt", nb);
    triLexicographiqueABulles(tabMots,nb,&cpu_time_used);
    affichageTabMotsDynamique(tabMots,nb);
    printf("Temps du CPU pour effectuer le tri : %lf secondes\n",cpu_time_used);
    affichageRechercheString(tabMots, nb, "TEND");
    ajoutMotFindeFichier(".\\files\\liste_dev_perso.txt","TEST");
    ajoutMotLigneIFichier(".\\files\\liste_dev.txt","CHOUCROUTE",15,nb);
    ecritureTabMotsFichier(".\\files\\liste_dev_triée.txt",tabMots,nb);
    calculPointsBareme(".\\files\\lettres_pts.txt", tabMots, nb, &scoreMax, &nbScoreMax);
    printf("Le score maximum pour le dictionnaire est de %d points\n",scoreMax);
    printf("Le nombre de mots permettant d'obtenir ce score est %d mots\n",nbScoreMax);
    freeTabMotsDynamique(tabMots,nb);
}

//Fonction affichant un menu permettant de lancer les différentes fonctions tests du programme
void menu()
{
    char menu1;
    printf("Valynseele Alexis\n\n");
    do
    {
        printf("=================================================\n\n");
        printf("< 1 > Programme Test Exo 1\n");
        printf("< 0 > Quitter le programme\n\n");
        printf("=================================================\n\n");
        printf("votre choix: \t");
        scanf("%s", &menu1);
        printf("\n");
        switch (menu1)
        {
        case '0':
            printf("fin du programme\n");
            break;
        case '1':
            testPartieI();
            break;
        default:
            printf("erreur: commande inconnue\n");
            break;
        }
    } while (menu1 != '0');
}
