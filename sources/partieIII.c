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


char *strConstruction(char mot[],...){
    va_list v;
    char buffer[256];
    char *resultat = (char *)calloc(strlen(mot)+2,sizeof(char)); strcpy(resultat,mot); strcat(resultat," ");

    va_start(v,mot);
    while (buffer[0] != '.'){
        strcpy(buffer,va_arg(v, char *));
        resultat = realloc(resultat,strlen(resultat)+strlen(buffer)+3);
        strcat(resultat,buffer);
        strcat(resultat," ");
    }
    va_end(v);
    return resultat;
}

void test(){
    char *resultat;
    resultat = strConstruction("Test","De","La","Fonction",".");
    printf("%s\n",resultat);
}

//Fonction testant les différentes fonctions de listes_chainees.c (Partie II du TP)
void testPartieIII()
{
    char menu1;
    char *resultat;
    char mot1[256]; char mot2[256]; char mot3[256]; char mot4[256];
    printf("Test de la partie III :\n\n");
    do
    {
        printf("=================================================\n\n");
        printf("< 1 > Creation d'une phrase avec 4 mots \n");
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
            printf("Test de la fonction permettant de créer une phrase a partir d'un nombre indéfini de mots\n\n");
            printf("Pour l'exemple nous allons utiliser 4 mots\n");
            printf("Entrez le premier mot : \n");
            scanf("%s",mot1);
            printf("Entrez le second mot : \n");
            scanf("%s",mot2);
            printf("Entrez le troisème mot : \n");
            scanf("%s",mot3);
            printf("Entrez le quatrième mot\n");
            scanf("%s",mot4);
            resultat = strConstruction(mot1,mot2,mot3,mot4,".");
            printf("Voici le resultat : \n");
            printf("%s\n",resultat);
            break;
        default:
            printf("erreur: commande inconnue (%d)\n", menu1);
            break;
        }
    } while (menu1 != '0');
}