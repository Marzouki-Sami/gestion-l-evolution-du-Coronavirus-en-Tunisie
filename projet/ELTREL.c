#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <malloc.h>
#include <string.h>
#include "ELTPRIM.H"

bool datevalide(int day,int month,int year,SYSTEMTIME Time)
{
    bool b=false;

    if ((year<=Time.wYear)&&(year>=2019))
    {
        if( (month>=1)&&(month<=12) )
        {
            if(((day>=1)&&(day <= 31))&&((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12)))
                b=true;

            else if(((day>=1)&&(day<=30))&&((month==4)||(month==6)||(month==9)||(month==11)))
                b=true;

            else if(((day>=1)&&(day<=28))&&(month==2))
                b=true;

            else if(((day==29)&&(month==2))&&((year%400==0)||((year%4==0)&&(year%100!=0))))
                b=true;
        }
    }

    if(b)
    {
        if(year>Time.wYear)
            b=false;

        else if(year==Time.wYear)
        {
            if(month>Time.wMonth)
                b=false;

            else if(month==Time.wMonth)
                     if(day>Time.wDay)
                         b=false;
        }
    }

return b;
}


ELEMENT elementCreer()
{
    ELEMENT e=(ELEMENT)malloc(sizeof(covid));
    e->jour=0;
    strcpy(e->mois,"");
    e->annee=0;
    e->caspos=0;
    e->casger=0;
    e->deces=0;
    e->nbrvacc=0;
    return e;
}

void elementLire(ELEMENT* e)
{
    char m[13][10]= {"",
                     "Janvier",
                     "Fevrier",
                     "Mars",
                     "Avril",
                     "Mai",
                     "Juin",
                     "Juillet",
                     "Août",
                     "Septembre",
                     "Octobre",
                     "Novembre",
                     "Décembre"
                    };
    bool test;
    int i;
    SYSTEMTIME Time;
    GetLocalTime(&Time);
    do
    {
        printf("tapez le jour : ");
        fflush(stdin);
        scanf("%i",&(*e)->jour);
        printf("tapez le mois : ");
        fflush(stdin);
        scanf("%s",(*e)->mois);
        printf("tapez l'ann%ce : ",130);
        fflush(stdin);
        scanf("%i",&(*e)->annee);
        test=false;
        i=1;
        while((i<=12)&&(!test))
        {
            if(strcmp((*e)->mois,m[i])==0)
                test=true;
            else
                i++;
        }
    }
    while(!datevalide((*e)->jour,i,(*e)->annee,Time));

    do
    {
        printf("tapez le nombre des cas positifs : ");
        fflush(stdin);
        scanf("%i",&(*e)->caspos);
    }
    while((*e)->caspos<0);
    do
    {
        printf("tapez le nombre des Gu%crisons : ",130);
        fflush(stdin);
        scanf("%i",&(*e)->casger);
    }
    while((*e)->casger<0);
    do
    {
        printf("tapez le nombre de d%cc%cs : ",130,138);
        fflush(stdin);
        scanf("%i",&(*e)->deces);
    }
    while((*e)->deces<0);
    do
    {
        printf("tapez le nombre de vaccin%cs : ",130);
        fflush(stdin);
        scanf("%i",&(*e)->nbrvacc);
    }
    while((*e)->nbrvacc<0);
    printf("\n");
}



void elementLire00(ELEMENT* e)
{

    do
    {
        printf("tapez le nombre des cas positifs : ");
        fflush(stdin);
        scanf("%i",&(*e)->caspos);
    }
    while((*e)->caspos<0);
    do
    {
        printf("tapez le nombre des Gu%crisons : ",130);
        fflush(stdin);
        scanf("%i",&(*e)->casger);
    }
    while((*e)->casger<0);
    do
    {
        printf("tapez le nombre de d%cc%cs : ",130,138);
        fflush(stdin);
        scanf("%i",&(*e)->deces);
    }
    while((*e)->deces<0);
    do
    {
        printf("tapez le nombre de vaccin%cs : ",130);
        fflush(stdin);
        scanf("%i",&(*e)->nbrvacc);
    }
    while((*e)->nbrvacc<0);
    printf("\n");
}

void elementAfficher(ELEMENT e)
{
    printf("%i %s %i \ncas positifs:%i \nnombre des Gu%crisons:%i \nle nombre de d%cc%cs:%i \nle nombre de vaccin%cs:%i\n",e->jour,e->mois,e->annee,e->caspos,130,e->casger,130,138,e->deces,130,e->nbrvacc);
}

void elementAfficher0(ELEMENT e)
{
    printf("%i %s %i      \t|\t%i\t|\t%i\t|\t%i\t|\t%i\n",e->jour,e->mois,e->annee,e->caspos,e->casger,e->deces,e->nbrvacc);
}

void elementDetruire(ELEMENT e)
{
    free(e);
}

void elementAffecter(ELEMENT* e1, ELEMENT e2)
{
    *e1=e2;
}

void elementCopier(ELEMENT * e1, ELEMENT e2)
{
    memcpy(*e1,e2,sizeof(covid));
}

int elementComparer1(ELEMENT e1, ELEMENT e2)
{
    return((e1->caspos)-(e2->caspos));
}
int elementComparer2(ELEMENT e1, ELEMENT e2)
{
    return((e1->casger)-(e2->casger));
}
int elementComparer3(ELEMENT e1, ELEMENT e2)
{
    return((e1->deces)-(e2->deces));
}
int elementComparer4(ELEMENT e1, ELEMENT e2)
{
    return((e1->nbrvacc)-(e2->nbrvacc));
}
int elementComparer5(ELEMENT e1, ELEMENT e2)
{
    return(((e1->jour)==(e2->jour))&&((e1->annee)==(e2->annee))&&(strcmp(e1->mois,e2->mois)));
}
