#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//functie care inlocuieste 0-urile ori cu ' ' sau '_'
void zero(char highlightf[])
{
    int i, ok=0;
    for(i=1; i<strlen(highlightf); i++)
    {
        if(highlightf[i-1]=='_' && highlightf[i]=='0')
        {
            ok=1;
        }else if(highlightf[i-1]==' ' && highlightf[i]=='0')
        {
            ok=2;
        }else
        {
            ok=0;
        }
        if(ok==1)
        {
            highlightf[i]='_';
        }
        if(ok==2)
        {
            highlightf[i]=' ';    
        }
    }
}

//functie care afla pozitia inceputului unui string in alt string
void aflare_poz(char randnou[], char string[], int *poz)
{
    int gasit=0, i=0, index=0;
    while(i<strlen(randnou))
    {
        if(randnou[i]==string[index])
        {
            gasit=1;
            *poz=i;
            while(gasit==1)
            {
                i++;
                index++;
                if(randnou[i]!=string[i])
                {
                    gasit=0;
                    index=0;
                }
            }
            if(gasit==1)
            {
                i=strlen(randnou);
            }
        }else{
            i++;
        }
        
    }
}

//functie pentru a transforma un rand din text cu un singur spatiu intre cuvinte
void transformare(char rand[], char randnou[], char highlightf[])
{
    int i, index=0;
    for(i=0; i<strlen(rand); i++)
    {
        highlightf[i]=' ';
        while(rand[i]==' ' && rand[i+1]==' ')
        {
            i++;
            highlightf[i]='0';
        }
        randnou[index]=rand[i];
        index++;
    }
    randnou[index]='\0';
}

//functia pentru a gasi daca o secventa din randul din textul introdus este 
//keyword si va fi evidentiat in vectorul highlight
void cautare_cuvant(char matrice[], char randnou[], char highlightp[])
{
    int cntr=0, lung_init=strlen(randnou), poz, j;
    char randnou_copie[lung_init];
    strcpy(randnou_copie, randnou);
    if(strstr(randnou_copie, matrice)!=NULL)
    {
        while(strstr(randnou_copie, matrice)!=NULL)
            {
                char keyword[strlen(strstr(randnou_copie, matrice))];
                strcpy(keyword, strstr(randnou_copie, matrice));
                poz=-1;
                aflare_poz(randnou_copie,keyword, &poz);
                for(j=poz+cntr; j<poz+cntr+strlen(matrice) && j<lung_init; j++)
                {
                    highlightp[j]='_';
                }
                strcpy(randnou_copie +strlen(randnou_copie)-strlen(keyword), 
                keyword +strlen(matrice));
                cntr=cntr+strlen(matrice);
            }
        highlightp[lung_init]='\0';
    }
    
}

//functie care adauga vectorul cu highlighturi in vectorul in care am inlocuit spatiile
//in plus cu 0-uri
void adaugare1(char highlightf[], char highlightp[], int lungime)
{
    int index=0, i;
    for(i=0; i<strlen(highlightf); i++)
    {
        if(highlightf[i]!='_'&& highlightf[i]!='0')
        {
            highlightf[i]=highlightp[index];
            index++;
        }
    }
    highlightf[lungime]='\0';
}

int main()
{
    char keywords[15][9]={
        {"first of"},
        {"for"},
        {"for each"},
        {"from"},
        {"in"},
        {"is"},
        {"is a"},
        {"list of"},
        {"unit"},
        {"or"},
        {"while"},
        {"int"},
        {"float"},
        {"double"},
        {"string"}
    };
    int n, i, j;
    scanf("%d\n", &n);
    char text[n][100];
    /*text=malloc(n*sizeof(char *));
    for (int i = 0; i < n; i++) 
    {
        text[i] = malloc(n* sizeof(char)); 
    }*/
    for(i=0; i<n; i++)
    {
        //while(getchar() !='\n');
        fgets(text[i],100, stdin);
        //text[i]=realloc(text[i],strlen(text[i])*sizeof(char));
        char high[strlen(text[i])], highf[strlen(text[i])], textnou[strlen(text[i])];
        //highf=malloc(strlen(text[i])*sizeof(char));
        //high=malloc(strlen(text[i])*sizeof(char));
        //textnou=malloc(strlen(text[i])*sizeof(char));
        memset(highf, ' ',strlen(text[i]));
        transformare(text[i], textnou, highf);
        memset(high, ' ', strlen(textnou));
        for(j=0; j<15; j++)
        {
            cautare_cuvant(keywords[j], textnou, high);
            printf("%s", high);
            printf("\n");
        }
        adaugare1(highf, high, strlen(text[i]));
        zero(highf); 
        printf("%s", text[i]);
        printf("%s", highf);
        if(i!=n-1)
        {
            printf("\n");
        }
    }
    /*for (int i = 0; i < n; i++) 
    {
        free(text[i]);
    }
    free(text);*/
    return 0;
}
