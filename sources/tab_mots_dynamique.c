/**************************************************************
Auteur : Valynseele Alexis
Date :  26/11/2019 - Seance 1
Titre : TP 4 - DA (9h)
Fichier C : Fichier contenant les fonctions en rapport avec la Partie I 

**************************************************************/

//Pre-processeur

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

//1
int nbMots(char nom[])
{
    FILE *f;
    assert(f = fopen(nom, "r"));
    int i = 0;
    char buffer[256];

    while (fgets(buffer, 256, f) != NULL)
    {
        i++;
    }
    fclose(f);
    return i;
}

char **creationTabMotsDynamique(char nom[], int nbMots)
{
    FILE *f;
    assert(f = fopen(nom, "r"));

    char buffer[256];
    int i = 0;
    char **tabMots;
    tabMots = (char **)calloc(nbMots, sizeof(char *));

    while (fgets(buffer, 256, f) != NULL)
    {
        tabMots[i] = (char *)calloc(strlen(buffer) + 1, sizeof(char));
        assert(tabMots[i] != NULL);
        strcpy(tabMots[i], buffer);
        i++;
    }
    fclose(f);
    return tabMots;
}

void affichageTabMotsDynamique(char **tabMots, int nbMots)
{
    int i;
    for (i = 0; i < nbMots; i++)
    {
        printf("Mot n°%d : %s", i, tabMots[i]);
    }
}

//2
void affichageRechercheString(char **tabMots, int nbMots, char string[])
{
    int i;
    for (i = 0; i < nbMots; i++)
    {
        if (strstr(tabMots[i], string) != NULL)
        {
            printf("%s\n", tabMots[i]);
        }
    }
}

//3
void ajoutMotFindeFichier(char nom[], char string[])
{
    FILE *f; 
    assert(f = fopen(nom, "a"));
    fprintf(f,"\n%s",string);
    fclose(f);
}

//4
void ajoutMotLigneIFichier(char nom[],char string[],int pos,int nbMots){
    FILE *f1, *f2;
    int i;
    char buffer[256];

    assert(f1 = fopen(nom,"r"));
    assert(f2 = fopen(".\\files\\test.txt", "w"));

    for(i = 0;i<pos-1;i++){
        fgets(buffer,256,f1);
        fprintf(f2,"%s",buffer);
    }
    fprintf(f2,"%s\n",string);
    for(i = pos;i<nbMots;i++){
        fgets(buffer,256,f1);
        fprintf(f2,"%s", buffer);
    }
    fclose(f1);
    fclose(f2);
    remove(nom);
    rename(".\\files\\test.txt",nom);
}