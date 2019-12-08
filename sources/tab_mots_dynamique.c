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
//Fonction retournant le nombre de mots dans le ficher passé en entrée
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

/*Fonctions permettant de créer le tableau dynamique de mots
 *Entrée : le nom de fichier contenant les mots et le nombre de mots
 *Sortie : un pointeur sur un tableau de chaînes de caractères
 *Fonctionnement : On parcourt le fichier,chaque mot est recupéré dans un buffer puis l'on copie le contenu du buffer dans un tableau de chaînes alloué dynamiquement
 * en fonction de la taille de chaque mot.
 */
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

//Fonction affichant chaque mot du tableau
void affichageTabMotsDynamique(char **tabMots, int nbMots)
{
    int i;
    for (i = 0; i < nbMots; i++)
    {
        printf("Mot n°%d : %s\n", i+1, tabMots[i]);
    }
}

//2
//Fonction affichant tout les mots du tableau de mots contenant la chaîne string[] passé en en entrée
void affichageRechercheString(char **tabMots, int nbMots, char string[])
{
    printf("Voici les mots contenant : %s\n\n",string);
    int i;
    for (i = 0; i < nbMots; i++)
    {
        if (strstr(tabMots[i], string) != NULL)
        {
            printf("Mot n°%d : %s\n", i + 1, tabMots[i]);
        }
    }
}

//3
//Fonction d'ajout d'un mot passé en entrée a la fin du fichier
void ajoutMotFindeFichier(char nom[], char string[])
{
    FILE *f; 
    assert(f = fopen(nom, "a"));
    fprintf(f,"\n%s",string);
    fclose(f);
}

//4
//Fonction d'ajout d'un mot à une ligne précise du fichier
/*Pour ce faire on recopie tout le contenu du fichier originel dans une nouveau fichier jusqu'a la postion d'ajout
 * où l'on ajoute le nouveau mot puis on recopie la fin du fichier originel a la suite.
 * Enfin on supprime le fichier originel et on renome le nouveau fichier avec le nom de l'ancien.    
 */
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
    for(i = pos;i<=nbMots;i++){
        fgets(buffer,256,f1);
        fprintf(f2,"%s", buffer);
    }
    fclose(f1);
    fclose(f2);
    remove(nom);
    rename(".\\files\\test.txt",nom);
}

//6(a)
//Test pour savoir si mot 1 est superieur ou non a un mot2 dans l'odre lexicographique
//Renvoit vrai si le mot 1 est situé avant dans l'ordre lexicographique
//Renvoit faux si le mot 2 est situé avant dans l'odre lexcicographique
bool testLexicographique(char *mot1,char *mot2){
    unsigned int i,max;
    if(strlen(mot1) >= strlen(mot2)){
        max = strlen(mot2);
    }else
    {
        max = strlen(mot1);
    }
    
    for(i = 0;i<max;i++){
        if(mot1[i] < mot2[i]){
            return true;
        }
        else if (mot1[i] > mot2[i]){
            return false;
        }
    }
    if(max == strlen(mot1)){
        return true;
    }else
    {
        return false;
    }
    
}
//Tri le tableau selon l'odre lexicographique à l'aide d'un tri a bulles et de la fonction testLexicographique
void triLexicographiqueABulles(char **tabMots, int nbMots,double *cpu_time_used)
{
    int i,j;
    char *temp;
    clock_t start, end; *cpu_time_used = 0;
    start = clock();
    for(i = nbMots;i>1;i--){
        for(j = 0;j<i-1;j++){
            if (testLexicographique(tabMots[j+1], tabMots[j])) /*Si le mot a l'emplacement j+1 doit apparaitre avant dans l'odre lexicographique alors il est décalé a gauche,a l'inverse le mot a l'emplacement j est décalé a droite. A la fin d'un tour le mot se situant a la fin est a sa place finale*/
            {
                temp = tabMots[j+1];
                tabMots[j+1] = tabMots[j];
                tabMots[j] = temp;
            }
        }
    }
    end = clock();
    *cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
}

//6(b)
//A FAIRE

//7
//Fonction d'ecriture d'un tableau de mots dans un Fichier (en supposant que le tableau soit trié préalablement)
void ecritureTabMotsFichier(char nom[], char **tabMots,int nbMots)
{
    FILE *f; int i;
    assert(f = fopen(nom, "w"));
    for(i = 0;i<nbMots;i++){
        fprintf(f,"%s",tabMots[i]);
    }
    fclose(f);
}

//8 calcul points avec le bareme du polycopié
void calculPoints(char **tabMots,int nbMots,int *scoreMax,int *nbScoreMax){
    int somme = 0;int i,j;
    *scoreMax = 0;
    *nbScoreMax = 0;
    int bareme[91];
    bareme[65] = 1;bareme[66] = 3;bareme[67] = 3;bareme[68] = 2;bareme[69] = 1;bareme[70] = 4;bareme[71] = 2;bareme[72] = 4;bareme[73] = 1;bareme[74] = 8;bareme[75] = 10;bareme[76] = 1;bareme[77] = 2;bareme[78] = 1;bareme[79] = 1; bareme[80] = 3;bareme[81] = 8; bareme[82] = 1; bareme[83] = 1; bareme[84] = 1; bareme[85] = 1; bareme[86] = 4; bareme[87] = 10; bareme[88] = 10; bareme[89] = 10; bareme[90] = 10;
    for(i = 0;i<nbMots;i++){
        for(j = 0;j<(int)strlen(tabMots[i])-1;j++){
            somme += bareme[(int)tabMots[i][j]];
        }
        if(somme > *scoreMax)
            *scoreMax = somme;
        somme = 0;
    }
    for (i = 0; i < nbMots; i++)
    {
        for (j = 0; j <(int)strlen(tabMots[i])-1; j++)
        {
            somme += bareme[(int)tabMots[i][j]];
        }
        if (somme == *scoreMax){
            *nbScoreMax = *nbScoreMax + 1;
            //printf("%s\n",tabMots[i]); //Pour voir les mots permettant d'obtenir le score max dans le tab mots entrée
        }
        somme = 0;
    }
}

//9
void creationBareme(char nom[],int bareme[91]){
    FILE *f; char buffer[256], temp[1];
    assert(f = fopen(nom,"r"));

    while (fgets(buffer, 256, f) != NULL){

        if(buffer[0] == 'a'){
            temp[0] = buffer[2]; 
            bareme[65] = atoi(temp); //65 correspond au chiffre correspondant a 'A' en ascii
        }
        else if (buffer[0] == 'b')
        {
            temp[0] = buffer[2];
            bareme[66] = atoi(temp);
        }
        else if (buffer[0] == 'c')
        {
            temp[0] = buffer[2];
            bareme[67] = atoi(temp);
        }
        else if (buffer[0] == 'd')
        {
            temp[0] = buffer[2];
            bareme[68] = atoi(temp);
        }
        else if (buffer[0] == 'e')
        {
            temp[0] = buffer[2];
            bareme[69] = atoi(temp);
        }
        else if (buffer[0] == 'f')
        {
            temp[0] = buffer[2];
            bareme[70] = atoi(temp);
        }
        else if (buffer[0] == 'g')
        {
            temp[0] = buffer[2];
            bareme[71] = atoi(temp);
        }
        else if (buffer[0] == 'h')
        {
            temp[0] = buffer[2];
            bareme[72] = atoi(temp);
        }
        else if (buffer[0] == 'i')
        {
            temp[0] = buffer[2];
            bareme[73] = atoi(temp);
        }
        else if (buffer[0] == 'j')
        {
            temp[0] = buffer[2];
            bareme[74] = atoi(temp);
        }
        else if (buffer[0] == 'k')
        {
            temp[0] = buffer[2];
            bareme[75] = atoi(temp);
        }
        else if (buffer[0] == 'l')
        {
            temp[0] = buffer[2];
            bareme[76] = atoi(temp);
        }
        else if (buffer[0] == 'm')
        {
            temp[0] = buffer[2];
            bareme[77] = atoi(temp);
        }
        else if (buffer[0] == 'n')
        {
            temp[0] = buffer[2];
            bareme[78] = atoi(temp);
        }
        else if (buffer[0] == 'o')
        {
            temp[0] = buffer[2];
            bareme[79] = atoi(temp);
        }
        else if (buffer[0] == 'p')
        {
            temp[0] = buffer[2];
            bareme[80] = atoi(temp);
        }
        else if (buffer[0] == 'q')
        {
            temp[0] = buffer[2];
            bareme[81] = atoi(temp);
        }
        else if (buffer[0] == 'r')
        {
            temp[0] = buffer[2];
            bareme[82] = atoi(temp);
        }
        else if (buffer[0] == 's')
        {
            temp[0] = buffer[2];
            bareme[83] = atoi(temp);
        }
        else if (buffer[0] == 't')
        {
            temp[0] = buffer[2];
            bareme[84] = atoi(temp);
        }
        else if (buffer[0] == 'u')
        {
            temp[0] = buffer[2];
            bareme[85] = atoi(temp);
        }
        else if (buffer[0] == 'v')
        {
            temp[0] = buffer[2];
            bareme[86] = atoi(temp);
        }
        else if (buffer[0] == 'w')
        {
            temp[0] = buffer[2];
            bareme[87] = atoi(temp);
        }
        else if (buffer[0] == 'x')
        {
            temp[0] = buffer[2];
            bareme[88] = atoi(temp);
        }
        else if (buffer[0] == 'y')
        {
            temp[0] = buffer[2];
            bareme[89] = atoi(temp);
        }
        else if (buffer[0] == 'z')
        {
            temp[0] = buffer[2];
            bareme[90] = atoi(temp);
        }
    }
}

void calculPointsBareme(char nomBareme[],char **tabMots, int nbMots, int *scoreMax, int *nbScoreMax)
{
    int somme = 0;
    int i, j;
    *scoreMax = 0;
    *nbScoreMax = 0;
    int bareme[91];
    creationBareme(nomBareme,bareme);

    for (i = 0; i < nbMots; i++)
    {
        for (j = 0; j < (int)strlen(tabMots[i]) - 1; j++)
        {
            somme += bareme[(int)tabMots[i][j]];
        }
        if (somme > *scoreMax)
            *scoreMax = somme;
        somme = 0;
    }
    for (i = 0; i < nbMots; i++)
    {
        for (j = 0; j < (int)strlen(tabMots[i]) - 1; j++)
        {
            somme += bareme[(int)tabMots[i][j]];
        }
        if (somme == *scoreMax)
        {
            *nbScoreMax = *nbScoreMax + 1;
            //printf("%s\n",tabMots[i]); //Pour voir les mots permettant d'obtenir le score max dans le tab mots entrée
        }
        somme = 0;
    }
}

//10
//Fonction libérant la mémoire de chaque chaînes de caractères du tableau de mots puis libérant le tableau de mots lui même
void freeTabMotsDynamique(char **tabMots, int nbMots)
{
    int i;
    for(i = 0;i<nbMots;i++){
        free(tabMots[i]);
        tabMots[i] = NULL;
    }
    free(tabMots);
    tabMots = NULL;
}

