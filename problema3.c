#include <stdio.h>
#include <stdlib.h>
//functie care transforma partitiile vectorului mare
void init_vector(int baza2[], int final, int rezultat[])
{
    int i;
    for(i=3; i>=0; i--)
    {
        rezultat[i]=baza2[final];
        final--;
    }
}


//functie care converteste numarul din baza 10 in baza 2 si il pune 
//intr-un vector
void convertor2(unsigned int numar, int baza2[], int *index, int n)
{
    int aux, cnumar=numar, lung=0;
    while(cnumar!=0)
    {
        lung++;
        cnumar=cnumar/2;
    }
    if(lung>=(n*6+4))
    {
        lung=n*6+4;
    }
    while(numar!=0&&lung>0)
    {
        aux=numar%2;
        numar=numar/2;
        baza2[lung-1]=aux;
        lung--;
        *index=*index+1;
    }
}

//functie care transforma partitii din vectorul cu numarul in baza 10
//din baza 2

int convertor10(int baza2[], int start, int final)
{
    int i,rezultat=0, doi_putere=1;
    for(i=final; i>=start; i--)
    {
        rezultat=rezultat+baza2[i]*doi_putere;
        doi_putere=doi_putere*2;
    }
    return rezultat;
}

//functia de adunare
void adunare(int rezultat[], int vector2[])
{
    int i, minte=0;
    for(i=3; i>=0; i--)
    {   
        if(rezultat[i]+vector2[i]+minte>1)
        {
            rezultat[i]=0;
            minte=1;
        }
        else
        {
            rezultat[i]=rezultat[i]+vector2[i]+minte;
            minte=0;
        }
    }
}

//functia interschimbare
void interschimbare(int rezultat[], int vector2[])
{
    int vect_p1[2]={vector2[0], vector2[1]}, vect_p2[2]={vector2[2], vector2[3]}, aux;
    int p1, p2;
    p1=convertor10(vect_p1, 0, 1);
    p2=convertor10(vect_p2, 0, 1);
    aux=rezultat[p1];
    rezultat[p1]=rezultat[p2];
    rezultat[p2]=aux;
}

//functie rotatie la stanga
void rotatie(int rezultat[], int vector2[])
{
    int i, nr_rotatii=convertor10(vector2, 0, 3), aux;
    while(nr_rotatii>=4)
    {
        nr_rotatii=nr_rotatii-4;
    }
    while(nr_rotatii>0)
    {
        aux=rezultat[0];
        for(i=0; i<=2; i++)
        {
            rezultat[i]=rezultat[i+1];
        }
        rezultat[3]=aux;
        nr_rotatii--;
    }
}

//functie xor
void xor(int rezultat[], int vector2[])
{
    int i, copie[4];
    init_vector(rezultat, 3, copie);
    for(i=0; i<=3; i++)
    {
        if(copie[i]==vector2[i])
        {
            rezultat[i]=0;
        }
        else
        {
            rezultat[i]=1;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    unsigned int m;
    scanf("%u", &m);
    int v[28], rezultat[4], vector2[4], index=0, alegere, f2=9, fadaug=5, 
    sadaug=4, cntr=10, rez_final;
    void (*functii[4])(int rezultat[], int vector2[])={adunare, interschimbare,
    rotatie, xor};
    convertor2(m, v, &index, n); //trasnform numarul m in baza 2 prin vectorul v
                                    // si aflu lungimea lui prin index;
    if(n!=0)
    {
        init_vector(v, 3, rezultat);
        while(index!=0)
        {
            init_vector(v, f2, vector2);
            alegere=convertor10(v, sadaug, fadaug);
            functii[alegere](rezultat, vector2);
            index=index-cntr;
            cntr=6;
            f2+=6;
            sadaug+=6;
            fadaug+=6;
        }
        rez_final=convertor10(rezultat, 0, 3);
    }
    else
    {
        rez_final=convertor10(v, 0, index-1);
    }
    printf("%d", rez_final);

    return 0;
}