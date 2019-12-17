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

//1) types

typedef struct Cell
{
    char *mot;
    struct Cell *suivant;
} Cellule_Chaine;

typedef Cellule_Chaine *Liste_Cellule_Chaine;

typedef Liste_Cellule_Chaine *tabListes;

tabListes initialisationTabListes()
{
    tabListes tab = (tabListes)malloc(26 * sizeof(Liste_Cellule_Chaine));

    Liste_Cellule_Chaine a = NULL;
    tab[0] = a;
    Liste_Cellule_Chaine b = NULL;
    tab[1] = b;
    Liste_Cellule_Chaine c = NULL;
    tab[2] = c;
    Liste_Cellule_Chaine d = NULL;
    tab[3] = d;
    Liste_Cellule_Chaine e = NULL;
    tab[4] = e;
    Liste_Cellule_Chaine f = NULL;
    tab[5] = f;
    Liste_Cellule_Chaine g = NULL;
    tab[6] = g;
    Liste_Cellule_Chaine h = NULL;
    tab[7] = h;
    Liste_Cellule_Chaine i = NULL;
    tab[8] = i;
    Liste_Cellule_Chaine j = NULL;
    tab[9] = j;
    Liste_Cellule_Chaine k = NULL;
    tab[10] = k;
    Liste_Cellule_Chaine l = NULL;
    tab[11] = l;
    Liste_Cellule_Chaine m = NULL;
    tab[12] = m;
    Liste_Cellule_Chaine n = NULL;
    tab[13] = n;
    Liste_Cellule_Chaine o = NULL;
    tab[14] = o;
    Liste_Cellule_Chaine p = NULL;
    tab[14] = p;
    Liste_Cellule_Chaine q = NULL;
    tab[15] = q;
    Liste_Cellule_Chaine r = NULL;
    tab[16] = r;
    Liste_Cellule_Chaine s = NULL;
    tab[17] = s;
    Liste_Cellule_Chaine t = NULL;
    tab[18] = t;
    Liste_Cellule_Chaine u = NULL;
    tab[19] = u;
    Liste_Cellule_Chaine v = NULL;
    tab[20] = v;
    Liste_Cellule_Chaine w = NULL;
    tab[21] = w;
    Liste_Cellule_Chaine x = NULL;
    tab[22] = x;
    Liste_Cellule_Chaine y = NULL;
    tab[23] = y;
    Liste_Cellule_Chaine z = NULL;
    tab[24] = z;

    return tab;
}

//2)
void creationTabListes(tabListes tab, char **tabMots, int nb)
{
    int i;
    Liste_Cellule_Chaine nouveau;
    for (i = nb - 1; i >= 0; i--)
    {
        if (tabMots[i][0] == 'A')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = (char *)calloc(strlen(tabMots[i])+1,sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[0];
            tab[0] = nouveau;
        }
        if (tabMots[i][0] == 'B')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = (char *)calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[1];
            tab[1] = nouveau;
        }
        if (tabMots[i][0] == 'C')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[2];
            tab[2] = nouveau;
        }
        if (tabMots[i][0] == 'D')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[3];
            tab[3] = nouveau;
        }
        if (tabMots[i][0] == 'E')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[4];
            tab[4] = nouveau;
        }
        if (tabMots[i][0] == 'F')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[5];
            tab[5] = nouveau;
        }
        if (tabMots[i][0] == 'G')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[6];
            tab[6] = nouveau;
        }
        if (tabMots[i][0] == 'H')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[7];
            tab[7] = nouveau;
        }
        if (tabMots[i][0] == 'I')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[8];
            tab[8] = nouveau;
        }
        if (tabMots[i][0] == 'J')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[9];
            tab[9] = nouveau;
        }
        if (tabMots[i][0] == 'K')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[10];
            tab[10] = nouveau;
        }
        if (tabMots[i][0] == 'L')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[11];
            tab[11] = nouveau;
        }
        if (tabMots[i][0] == 'M')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[12];
            tab[12] = nouveau;
        }
        if (tabMots[i][0] == 'N')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[13];
            tab[13] = nouveau;
        }
        if (tabMots[i][0] == 'O')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[14];
            tab[14] = nouveau;
        }
        if (tabMots[i][0] == 'P')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[15];
            tab[15] = nouveau;
        }
        if (tabMots[i][0] == 'Q')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[16];
            tab[16] = nouveau;
        }
        if (tabMots[i][0] == 'R')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[17];
            tab[17] = nouveau;
        }
        if (tabMots[i][0] == 'S')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[18];
            tab[18] = nouveau;
        }
        if (tabMots[i][0] == 'T')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[19];
            tab[19] = nouveau;
        }
        if (tabMots[i][0] == 'U')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[20];
            tab[20] = nouveau;
        }
        if (tabMots[i][0] == 'V')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[21];
            tab[21] = nouveau;
        }
        if (tabMots[i][0] == 'W')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[22];
            tab[22] = nouveau;
        }
        if (tabMots[i][0] == 'X')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[23];
            tab[23] = nouveau;
        }
        if (tabMots[i][0] == 'Y')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[24];
            tab[24] = nouveau;
        }
        if (tabMots[i][0] == 'Z')
        {
            nouveau = (Liste_Cellule_Chaine)malloc(sizeof(Cellule_Chaine));
            nouveau->suivant = NULL;
            nouveau->mot = calloc(strlen(tabMots[i]) + 1, sizeof(char));
            strcpy(nouveau->mot, tabMots[i]);

            nouveau->suivant = tab[25];
            tab[25] = nouveau;
        }
    }
}

void afficherTabListes(tabListes tab)
{
    Liste_Cellule_Chaine courant;
    int i;
    int compteur = 1;

    for (i = 0; i < 26; i++)
    {
        courant = tab[i];
        while (courant != NULL)
        {
            printf("Mot n°%d %s\n", compteur, courant->mot);
            compteur++;
            courant = courant->suivant;
        }
    }
}

//3)
bool rechercheMotTabMots(char **tabMots, int nb, char mot[], int *indice, double *cpu_time_used)
{
    int i = 0;
    clock_t start, end;
    *cpu_time_used = 0;

    start = clock();
    for( i = 0;i<nb;i++){
        if(strcmp(tabMots[i],mot) == 0){
            *indice = i;
            end = clock();
            *cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            return true;
        }
    }
    end = clock();
    *cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return false;
}

bool rechercheMotTabListes(tabListes tab, char mot[], int *indice, double *cpu_time_used)
{
    bool resultat = false;
    Liste_Cellule_Chaine courant;
    int i;
    int compteur = 1;

    clock_t start, end;
    *cpu_time_used = 0;
    start = clock();
    for (i = 0; i < 26; i++)
    {
        courant = tab[i];
        while (courant != NULL && resultat == false)
        {
            if (strcmp(courant->mot, mot) == 0){
                resultat = true;
                *indice = compteur-1;
                i = 27;
            }
            compteur++;
            courant = courant->suivant;
        }
    }
    end = clock();
    *cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return resultat;
}

//4)
void affichageRechercheStringTabListes(tabListes tab,char string[]){

    bool trouve = false; int i;
    int compteur = 0;
    Liste_Cellule_Chaine courant;

    printf("Voici les mots contenant : %s\n\n",string);
    for(i = 0; i <26 ; i++){
        courant = tab[i];
        while (courant != NULL){
            if(strstr(courant->mot,string) != NULL){
                trouve = true;
                printf("Mot n°%d : %s\n", compteur + 1,courant->mot);
            }
            compteur++;
            courant = courant->suivant;
        }
    }

    if(trouve == false){
        printf("Aucun mots ne contient : %s\n\n",string);
    }
}

//5)
void freeTabListes(tabListes tab)
{
    int i;
    Liste_Cellule_Chaine courant;
    Liste_Cellule_Chaine precedent;
    for(i = 0; i <26 ; i++){
        courant = tab[i];
        while (courant != NULL){

            precedent = courant;
            courant = courant->suivant;

            free(precedent->mot);
            precedent->suivant = NULL;
            free(precedent);
            precedent = NULL;
        }
        tab[i] = NULL;
    }
    free(tab);
    tab = NULL;
}


//Fonction testant les différentes fonctions de listes_chainees.c (Partie II du TP)
void testPartieII()
{
    char menu1;
    char **tabMots;
    double cpu_time_used;
    int nb,indice;
    tabListes tab;
    char string[256];

    printf("Test de la partie II :\n\n");
    do
    {
        printf("=================================================\n\n");
        printf("< 1 > Creation du tableau de listes \n");
        printf("< 2 > Affichage du tableau de listes \n");
        printf("< 3 > Recherche Mot via Tab Dynamique\n");
        printf("< 4 > Recherche Mot via Tab de Listes Chainees\n");
        printf("< 5 > Recherche des mots contenant une chaîne de caractères\n");
        printf("< 6 > Liberation de la memoire\n");
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
            tab = initialisationTabListes();
            nb = nbMots("./files//liste_dev.txt");
            tabMots = creationTabMotsDynamique("./files/liste_dev.txt", nb);
            triQsort(tabMots, nb, &cpu_time_used, compareLexicographique);
            creationTabListes(tab, tabMots, nb);
            printf("Tableau crée\n");
            break;
        case '2':
            afficherTabListes(tab);
            break;
        case '3':
                printf("Que voulez vous rechercher?\n");
                scanf("%s",string);
                strcat(string,"\n");
                if(rechercheMotTabMots(tabMots,nb,string,&indice,&cpu_time_used)){
                printf("Temps du CPU pour effectuer la recherche avec le TABLEAU DE MOTS: %lf secondes\n\n", cpu_time_used);
                printf("Le mot %s est present dans le tableau de mots à l'indice %d\n\n",string,indice);
                }else
                {
                    printf("Le mot %s n'est pas present dans le tableau de mot\n",string);
                }
            break;         
        case '4':
                printf("Que voulez vous rechercher?\n");
                scanf("%s",string);
                strcat(string,"\n");
                if (rechercheMotTabListes(tab, string, &indice,&cpu_time_used))
                {
                printf("Temps du CPU pour effectuer la recherche avec le TABLEAU DE LISTES: %lf secondes\n\n", cpu_time_used);
                printf("Le mot %s est present dans le tableau de listes,il s'agit du mot n°%d\n\n", string, indice);
                }else
                {
                    printf("Le mot %s n'est pas present dans le tableau de mot\n",string);
                }
            break;
        case '5':
            printf("Que voulez vous rechercher?\n");
            scanf("%s",string);
            affichageRechercheStringTabListes(tab,string);
            break;
        case '6':
            freeTabListes(tab);
            freeTabMotsDynamique(tabMots,nb);
            printf("Memoire liberée\n");
            break;
        default:
            printf("erreur: commande inconnue (%d)\n", menu1);
            break;
        }
    } while (menu1 != '0');
}