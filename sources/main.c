/**************************************************************
Auteur : Valynseele Alexis
Date :  26/11/2019 - Seance 1
Titre : TP 4 - DA (9h)
Fichier C : Main

**************************************************************/

//Pre-processeur

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include "..\\headers\\tab_mots_dynamique.h"
#include "..\\headers\\listes_chainees.h"
#include "..\\headers\\partieIII.h"
#include "..\\headers\\ma_bibliotheque.h"

//Fonction principale du programme,permet de lancer le menu ou de directement plusieurs fonction du TP à l'aide d'arguments
int main(int argc, char *argv[])
{
    char **tabMots;
    tabListes tab;
    int nb = 0; 
    double cpu_time_used = 0;
    int scoreMax = 0;
    int nbScoreMax = 0;

    if(argc == 1){

        menu(); //Sans arguments
    }
    else
    {
        //argv[1] == nom physique du fichier
        //argv[2] == entier 1 ou 2 
        if(strcmp(argv[2],"1") == 0){ //Gestion par tableau

            printf("Gestion par tableau dynamique\n");

            //argv[3] == string recherchée
            //argv[4] == mot a ajouter
            //argv[5] == indice d'ajout dans le tableau
            //argv[6] == nom physique du fichier de sauvegarde
            //argv[7] == nom physique du fichier bareme

            //Création du tableau dynamique
            nb = nbMots(argv[1]);
            tabMots = creationTabMotsDynamique(argv[1],nb);
            printf("Tableau crée\n");

            //Recherche String
            affichageRechercheString(tabMots, nb,argv[3]);

            //Ajout du mot a l'index i du tableau dynamique
            tabMots = ajoutMotTabIndiceI(tabMots, &nb,atoi(argv[5]),argv[4]);
            printf("Le mot %s a été ajouté dans le tableau dynamique à l'indice %d (donc mot n°%d)\n", argv[4], atoi(argv[5]), atoi(argv[5])+1);
            printf("Voici le tableau jusqu'a cet indice: \n");
            affichageTabMotsDynamique(tabMots,atoi(argv[5])+1);

            //Tri lexicographique Qsort
            triQsort(tabMots, nb, &cpu_time_used, compareLexicographique);
            printf("Tableau trié\n");
            printf("Temps du CPU pour effectuer le tri : %lf secondes\n\n", cpu_time_used);

            //Ecriture du tableau dans un nouveau fichier
            ecritureTabMotsFichier(argv[6], tabMots, nb);
            printf("Ecriture du tableau dans %s effectué\n",argv[6]);

            //Calcul des points au scrabble
            calculPointsBareme(argv[7], tabMots, nb, &scoreMax, &nbScoreMax);
            printf("Le score maximum pour le dictionnaire est de %d points\n", scoreMax);
            printf("Le nombre de mots permettant d'obtenir ce score est %d mots\n", nbScoreMax);

            //Libération de la mémoire 
            freeTabMotsDynamique(tabMots,nb);
            printf("Memoire liberée\n");

            //Commande exemple : ./TP4 ./files/liste_eval.txt  1 TEND TEST 5 ./files/liste_eval_triée.txt ./files/lettres_pts.txt


        }else if (strcmp(argv[2],"2") == 0) //Gestion par listes
        {
            printf("Gestion par tableau de listes\n");

            //argv[3] string recherchée

            //Initialisation du tableau de listes a NULL
            tab = initialisationTabListes();
            printf("Tableau de listes initialisé\n");

            //Creation du tableau de listes à l'aide d'un tableau dynamique de mots
            nb = nbMots(argv[1]);
            tabMots = creationTabMotsDynamique(argv[1], nb);
            triQsort(tabMots, nb, &cpu_time_used, compareLexicographique);
            creationTabListes(tab, tabMots, nb);
            printf("Tableau de listes rempli et trié dans l'ordre lexicographique\n");

            //Recherche String
            affichageRechercheStringTabListes(tab,argv[3]);

            //Libération de la mémoire
            freeTabListes(tab);
            freeTabMotsDynamique(tabMots,nb);
            printf("Memoire liberée\n");

            //Commande exemple : ./TP4 ./files/liste_eval.txt  2 TEND
        }
    }  
    return 0;
}
