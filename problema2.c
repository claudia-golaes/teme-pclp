#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct 
{
    char *word;
    int priority;
}dictionary_entry;

//functie care afla ce tip de cuvant este cel introdus de utilizator
//cuvant(tip=0), cuvant*(tip=1) sau cuv(tip=2)
void aflare_tip(dictionary_entry dictionar[], char cuvant[], int *tip, 
int nr_cuvinte)
{
    int gasit=0, i; 
    if(cuvant[strlen(cuvant)-1]=='*') *tip=1;
    for(i=0; i<nr_cuvinte &&gasit==0; i++)
    {
        if(strstr(dictionar[i].word,cuvant)!=NULL)
        {
            gasit=1;
        }
    }
    if(gasit==0) *tip=0;
    if(gasit==1) *tip=2;
}

//functie care adauga un element in dictionar (tip 0)
void adaugare(dictionary_entry dictionar[], char cuvant[], int *lung_actuala)
{
    dictionar=realloc(dictionar, (*lung_actuala+1)*sizeof(dictionary_entry));
    strcpy(dictionar[*lung_actuala].word, cuvant);
    dictionar[*lung_actuala].priority=1;
    *lung_actuala=*lung_actuala+1;
}

//functie care verifica cu ce sa completeze cuvantul in functie de prioritati 
//si ordine lexicografica (tip 2)
void gasire_autocomplete(dictionary_entry dictionar[], char cuvant[], char 
autocomplete[], int nr_cuvinte)
{
    char gasire[nr_cuvinte][21], index=0;
    int i, prioritati[nr_cuvinte], prioritate;
    for(i=0; i<nr_cuvinte; i++)
    {
        if(strstr(dictionar[i].word,cuvant)!=NULL)
        {
            strcpy(gasire[index], dictionar[i].word);
            prioritati[index]=dictionar[i].priority;
            index++;
        }
    }
    strcpy(autocomplete, gasire[0]);
    prioritate=prioritati[0];
    for(i=1; i<index; i++)
    {
        if(prioritate<prioritati[i] || (prioritate==prioritati[i] &&
         gasire[i]<autocomplete))
        {
            strcpy(autocomplete, gasire[i]);
            prioritate=prioritati[i];
        }

    }
    for(i=0; i<nr_cuvinte; i++)
    {
        if(strcmp(dictionar[i].word,autocomplete)==0)
        {
            dictionar[i].priority++;
        }
    }
}


int main()
{
    int n, m, i, j;
    scanf("%d", &n);
    dictionary_entry *cuv_dictionar;
    int lung;
    char buffer[BUFFER_SIZE];
    cuv_dictionar=malloc(n*sizeof(dictionary_entry));
    while(getchar()!='\n');
    for(j=0; j<n; j++)
    {
        scanf("%s", buffer);
        lung=strlen(buffer);
        cuv_dictionar[j].word=malloc(lung*sizeof(char));
        strcpy(cuv_dictionar[j].word, buffer);
        cuv_dictionar[j].priority=0 ;
    }
    scanf("%d", &m);
    char cuv_introduse[3][21]=
    {
        {"i"},
        {"wa"},
        {"fuck"}
    };
    char text_rezultat[m];
    for(i=0; i<m; i++)
    {   
        if(strstr(",.:!?", cuv_introduse[i])!=NULL)
        {
            strcat(text_rezultat, cuv_introduse[i]);
        }
        else
        {
            int tip=0;
            aflare_tip(cuv_dictionar, cuv_introduse[i], &tip, n);
            if(tip==0)
            {
                adaugare(cuv_dictionar, cuv_introduse[i], &n);
                strcat(text_rezultat, cuv_introduse[i]);
            }
            if(tip==1)
            {
                char copie[21];
                int tip2=0;
                strcpy(copie, cuv_introduse[i]);
                copie[strlen(copie)-1]='\0';
                aflare_tip(cuv_dictionar, copie, &tip2, n);
                if(tip2==0)
                {
                    adaugare(cuv_dictionar, copie, &n);
                }
                strcat(text_rezultat, copie);

            }
            if(tip==2)
            {
                char autocomplete[21];
                gasire_autocomplete(cuv_dictionar, cuv_introduse[i], 
                autocomplete, n);
                strcat(text_rezultat, autocomplete);
            }
        }
    }
    printf("%s", text_rezultat);
    free(cuv_dictionar);
    return 0;
}