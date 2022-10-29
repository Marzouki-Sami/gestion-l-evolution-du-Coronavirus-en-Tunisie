#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include "ELTPRIM.h"
#include "LSTPRIM.h"


LISTE taux[24];
LISTE tgouv[24];
int tcaspos[24];
int tger[24];
int tdeces[24];
int tnbrvacc[24];
bool Choix_Valide(char ch[12])
{
    if(strlen(ch)>1 || (ch[0])<49 || (ch[0])>55 || !isdigit(ch[0]))
        return false;

    return true;
}

bool Choix_Valide_Tri(char ch[12])
{
    if(strlen(ch)>1 || (ch[0])<49 || (ch[0])>52 || !isdigit(ch[0]))
        return false;

    return true;
}

bool alphabetique(char ch[12])
{
    int i;
    bool b;
    i=0;
    b=true;
    while(i<strlen(ch) && b)
    {
        if((!isspace(ch[i]))  &&  (!isalpha(ch[i])))
            b=false;
        i++;
    }
    return b;
}

void GouvernoratValide(char ch[12])
{
    ch[0]=toupper(ch[0]);
    for(int i=1; i<strlen(ch); i++)
        ch[i]=tolower(ch[i]);
    if(strcmp(ch,"Ben arous")==0)
        ch[4]=toupper(ch[4]);
    if(strcmp(ch,"La manouba")==0)
        ch[3]=toupper(ch[3]);
    if(strcmp(ch,"Le kef")==0)
        ch[3]=toupper(ch[3]);
    if(strcmp(ch,"Sidi bouzid")==0)
        ch[5]=toupper(ch[5]);
}

ELEMENT ChaineToElement(char ch[256],char gouver[20])
{
    ELEMENT e1=elementCreer();
    char chh[20];
    e1->jour=atoi(strtok(ch," "));
    strcpy(e1->mois,strtok(NULL," "));
    e1->annee=atoi(strtok(NULL," "));
    strcpy(gouver,strtok(NULL," "));
    if((strcmp(gouver,"Ben")==0)||(strcmp(gouver,"La")==0)||(strcmp(gouver,"Le")==0)||(strcmp(gouver,"Sidi")==0))
    {
        strcpy(chh,strtok(NULL," "));
        strcat(gouver," ");
        strcat(gouver,chh);
    }
    e1->caspos=atoi(strtok(NULL," "));
    e1->casger=atoi(strtok(NULL," "));
    e1->deces=atoi(strtok(NULL," "));
    e1->nbrvacc=atoi(strtok(NULL," "));
    return e1;
}

int main()
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
    SYSTEMTIME Time;
    GetLocalTime(&Time);
    FILE *fich,*bd;
    int i,choix,r;
    char choi[10];
    char ch[12];
    LISTE gov[24];
    for(i=0; i<24; i++)
        gov[i]=listeCreer();

    strcpy(gov[0]->nom,"Ariana");
    strcpy(gov[1]->nom,"Beja");
    strcpy(gov[2]->nom,"Ben Arous");
    strcpy(gov[3]->nom,"Bizerte");
    strcpy(gov[4]->nom,"Gabes");
    strcpy(gov[5]->nom,"Gafsa");
    strcpy(gov[6]->nom,"Jebdouba");
    strcpy(gov[7]->nom,"Kairouan");
    strcpy(gov[8]->nom,"Kasserine");
    strcpy(gov[9]->nom,"Kebili");
    strcpy(gov[10]->nom,"La Manouba");
    strcpy(gov[11]->nom,"Le Kef");
    strcpy(gov[12]->nom,"Mahdia");
    strcpy(gov[13]->nom,"Medenine");
    strcpy(gov[14]->nom,"Monastir");
    strcpy(gov[15]->nom,"Nebeul");
    strcpy(gov[16]->nom,"Sfax");
    strcpy(gov[17]->nom,"Sidi Bouzid");
    strcpy(gov[18]->nom,"Siliana");
    strcpy(gov[19]->nom,"Sousse");
    strcpy(gov[20]->nom,"Tataouine");
    strcpy(gov[21]->nom,"Tozeur");
    strcpy(gov[22]->nom,"Tunis");
    strcpy(gov[23]->nom,"Zaghouan");

    do
    {
        printf("\n\n\t\t\t\t\t\t1-Ajouter des information\n\n");
        printf("\t\t\t\t\t\t2-Supprimer des information\n\n");
        printf("\t\t\t\t\t\t3-Modifier des information\n\n");
        printf("\t\t\t\t\t\t4-Afficher des information\n\n");
        printf("\t\t\t\t\t\t5-Tri des information\n\n");
        printf("\t\t\t\t\t\t6-Importer des information\n\n");
        printf("\t\t\t\t\t\t7-Quitter\n\n\n");
        do
        {
            printf("\nTapez votre choix : ");
            fflush(stdin);
            gets(choi);
        }
        while(!Choix_Valide(choi));
        choix=atoi(choi);
        switch (choix)
        {
        case 1:
        {
            system("cls");
            bool  b,test;
            int j,o,f;
            fich=fopen("BD.txt","a");
            ELEMENT e=elementCreer();
            do
            {
                do
                {
                    printf("tapez la gouvernorat : ");
                    fflush(stdin);
                    gets(ch);
                }
                while(!alphabetique(ch));
                GouvernoratValide(ch);
                i=0;
                b=false;
                while((i<24)&&(!b))
                {
                    if(strcmp(ch,gov[i]->nom)==0)
                        b=true;
                    else
                        i++;
                }
                if(!b)
                printf("gov introuvable\n\n");
            }
            while(!b);


                f=1;
                do
                {
                    if(f>1)
                        printf("Date existe d%cja\n",130);
                    r=0;
                    do
                    {
                        if(r>0)
                            printf("Date Invalide\n");
                        printf("tapez le jour : ");
                        scanf("%i",&(e)->jour);
                        do
                        {
                            printf("tapez le mois : ");
                            scanf("%s",(e)->mois);
                        }
                        while(!alphabetique(e->mois));
                        GouvernoratValide(e->mois);
                        printf("tapez l'ann%ce : ",130);
                        scanf("%i",&(e)->annee);
                        test=false;
                        o=1;
                        while((o<=12)&&(!test))
                        {
                            if(strcmp((e)->mois,m[o])==0)
                                test=true;
                            else
                                o++;
                        }
                        r++;
                    }
                    while(!datevalide((e)->jour,o,(e)->annee,Time));


                    j=1;
                    test=false;
                    if(!estVide(gov[i]))
                    {
                        while(j<=gov[i]->lg && !test)
                        {
                            if((recuperer(gov[i],j)->jour==e->jour)&&(recuperer(gov[i],j)->annee==e->annee)&&(strcmp(recuperer(gov[i],j)->mois,e->mois)==0))
                                test=true;
                            else
                                j++;
                        }
                    }
                    f++;
                }
                while(test);

                elementLire00(&e);
                fprintf(fich,"%s %i %s %i %i %i %i %i\n",ch,e->jour,e->mois,e->annee,e->caspos,e->casger,e->deces,e->nbrvacc);
                inserer(gov[i],e,listeTaille(gov[i])+1);

            fclose(fich);



            break;


        }
        case 2:
        {
            system("cls");
            bool b,test;
            int jour,annee,j,x;
            char mois[10];
            do
            {
                do
                {
                    printf("tapez le gouvernorat : ");
                    fflush(stdin);
                    gets(ch);
                }
                while(!alphabetique(ch));
                GouvernoratValide(ch);
                i=0;
                b=false;
                while((i<24)&&(!b))
                {
                    if(strcmp(ch,gov[i]->nom)==0)
                        b=true;
                    else
                        i++;
                }
                if(!b)
                    printf("gouvernorat introuvable\n");
            }
            while(!b);
            if(!estVide(gov[i]))
            {
                if(b)
                {
                    do
                    {
                        r=0;
                        do
                        {
                            if(r>0)
                                printf("Date Invalide\n");
                            printf("tapez la date de l'information a supprimer\n");
                            printf("tapez le jour : ");
                            scanf("%i",&jour);
                            do
                            {
                                printf("tapez le mois : ");
                                scanf("%s",mois);
                            }
                            while(!alphabetique(mois));
                            GouvernoratValide(mois);
                            printf("tapez l'ann%ce : ",130);
                            scanf("%i",&annee);
                            test=false;
                            x=1;
                            while((x<=12)&&(!test))
                            {
                                if(strcmp(mois,m[x])==0)
                                    test=true;
                                else
                                    x++;
                            }
                            r++;
                        }
                        while(!datevalide(jour,x,annee,Time));
                        j=1;
                        test=false;
                        while((j<=listeTaille(gov[i]))&&(!test))
                        {

                            if((recuperer(gov[i],j)->jour==jour)&&(recuperer(gov[i],j)->annee==annee)&&(strcmp(recuperer(gov[i],j)->mois,mois)==0))
                            {
                                test=true;
                                supprimer(gov[i],j);
                            }
                            else
                                j++;
                        }
                        if(!test)
                            printf("Date introuvable\n\n");
                        else
                            printf("\ninformation supprimer avec succes\n\n");
                    }
                    while(!test);
                }
            }
            else
                printf("liste vide\n");
            break;
        }
        case 3:
        {
            system("cls");
            bool b,test;
            int jour,annee,j,x;
            char mois[10];
            do
            {
                do
                {
                    printf("tapez le gouvernorat : ");
                    fflush(stdin);
                    gets(ch);
                }
                while(!alphabetique(ch));
                GouvernoratValide(ch);
                i=0;
                b=false;
                while((i<24)&&(!b))
                {
                    if(strcmp(ch,gov[i]->nom)==0)
                        b=true;
                    else
                        i++;
                }
                if(!b)
                    printf("gouvernorat introuvable\n");
            }
            while(!b);
            if(!estVide(gov[i]))
            {
                if(b)
                {

                    do
                    {
                        r=0;
                        do
                        {
                            if(r>0)
                                printf("Date Invalide\n");
                            printf("tapez la date de l'information a modifier\n");
                            printf("tapez le jour : ");
                            scanf("%i",&jour);
                            do
                            {
                                printf("tapez le mois : ");
                                scanf("%s",mois);
                            }
                            while(!alphabetique(mois));
                            GouvernoratValide(mois);
                            printf("tapez l'ann%ce : ",130);
                            scanf("%i",&annee);
                            test=false;
                            x=1;
                            while((x<=12)&&(!test))
                            {
                                if(strcmp(mois,m[x])==0)
                                    test=true;
                                else
                                    x++;
                            }
                            r++;
                        }
                        while(!datevalide(jour,x,annee,Time));
                        j=1;
                        test=false;
                        while((j<=listeTaille(gov[i]))&&(!test))
                        {

                            if((recuperer(gov[i],j)->jour==jour)&&(recuperer(gov[i],j)->annee==annee)&&(strcmp(recuperer(gov[i],j)->mois,mois)==0))
                            {
                                test=true;
                                modifier(gov[i],j);
                            }
                            else
                                j++;
                        }
                        if(!test)
                            printf("Date introuvable\n\n");
                        else
                            printf("\ninformation modifier avec succes\n\n");
                    }
                    while(!test);
                }
            }
            else
                printf("liste vide\n");
            break;
        }
        case 4:
        {
            system("cls");
            bool b;
            do
            {
                do
                {
                    printf("tapez le gouvernorat : ");
                    fflush(stdin);
                    gets(ch);
                }
                while(!alphabetique(ch));
                GouvernoratValide(ch);
                i=0;
                b=false;
                while((i<24)&&(!b))
                {
                    if(strcmp(ch,gov[i]->nom)==0)
                    {
                        if(estVide(gov[i]))
                        {
                            printf("liste vide\n");
                            b=true;
                        }
                        else
                        {
                            b=true;
                            printf("\n      Date\t  \t   Cas positifs\t    Gu%crisons\t      d%cc%cs\t    vaccin%cs\n",130,130,138,130);
                            listeAfficher0(gov[i]);
                        }
                    }
                    else
                        i++;
                }
                if(!b)
                    printf("gouvernorat introuvable\n");
            }
            while(!b);
            break;
        }
        case 5:
        {
            system("cls");
            int ordre;
            do
            {
                printf("Tapez l'ordre de tri\ntapez (1) : pour croissant\ntapez (2) : pour d%ccroissant\n",130);
                scanf("%i",&ordre);
                fflush(stdin);
            }while( ordre<1 || ordre>2);
            if(ordre==2)
            {

                char a[1],v[1],c[1],d[1];
                int l=0,cle[4];;
                do
                {

                    if(l>0)
                    {
                        printf("error\n");
                    }
                    printf("Donner le cle des cas positifs :");
                    gets(a);
                    l++;
                }
                while(!Choix_Valide_Tri(a));
                cle[0]=atoi(a);
                l=0;
                do
                {
                    l++;
                    if(l>1)
                    {
                        printf("error\n");
                    }
                    printf("Donner le cle des guerisions:");
                    gets(v);

                }
                while((!Choix_Valide_Tri(v))||(cle[0]==atoi(v)));
                cle[1]=atoi(v);

                l=0;
                do
                {
                    l++;
                    if(l>1)
                    {
                        printf("error\n");
                    }

                    printf("Donner le cle de nombre deces:");
                    gets(c);

                }
                while((cle[0]==atoi(c) || cle[1] ==atoi(c) )||(!Choix_Valide_Tri(c)));
                cle[2]=atoi(c);
                l=0;
                do
                {
                    l++;
                    if(l>1)
                    {
                        printf("error\n");
                    }
                    printf("Donner le cle de nombre de vaccines:");
                    gets(d);
                }
                while((cle[0]==atoi(d) || cle[1]==atoi(d) || cle[2]==atoi(d))||(!Choix_Valide_Tri(d)));
                cle[3]=atoi(d);
                printf("Table des cl%c de priorit%c: |",130,130);
                for(i=0; i<4; i++)
                    printf("%i|",cle[i]);
                i=0;
                printf("\n");

                int j=0;
                int k,x,t;

                bool b,test;
                int jour,annee;
                char mois[10];


                j=1;
                k=0;
                t=0;
                r=0;
                do
                {
                    if(r>0)
                        printf("Date Invalide\n");
                    printf("tapez la date de l'information a Triee\n");
                    printf("tapez le jour : ");
                    scanf("%i",&jour);
                    do
                    {
                        printf("tapez le mois : ");
                        scanf("%s",mois);
                    }
                    while(!alphabetique(mois));
                    GouvernoratValide(mois);
                    printf("tapez l'ann%ce : ",130);
                    scanf("%i",&annee);
                    test=false;
                    x=1;
                    while((x<=12)&&(!test))
                    {
                        if(strcmp(mois,m[x])==0)
                            test=true;
                        else
                            x++;
                    }
                    r++;
                }
                while(!datevalide(jour,x,annee,Time));

                for(k=0; k<24; k++)
                {
                    j=1;
                    b=false;
                    if(!estVide(gov[k]))
                    {
                        while(j<=listeTaille(gov[k]) && !b)
                        {

                            if((recuperer(gov[k],j)->jour==jour)&&(recuperer(gov[k],j)->annee==annee)&&(strcmp(recuperer(gov[k],j)->mois,mois)==0))
                            {
                                b=true;
                                tgouv[t] = listeCreer();
                                strcpy(tgouv[t]->nom,gov[k]->nom);
                                tcaspos[t]=recuperer(gov[k],j)->caspos;
                                tger[t]=recuperer(gov[k],j)->casger;
                                tdeces[t]=recuperer(gov[k],j)->deces;
                                tnbrvacc[t]=recuperer(gov[k],j)->nbrvacc;
                                t++;
                            }
                            else
                                j++;


                        }
                    }

                }
                if(t!=0)
                {
                    i=0;
                    x=1;
                    do
                    {

                        switch (x)
                        {

                        case 1:
                        {

                            if(cle[0]==1)
                            {
                                j=0;
                                i=0;
                                taux[1] = listeCreer();
                                for(j=0; j<t; j++)
                                {
                                    for(i=0; i<t; i++)
                                    {
                                        if(tcaspos[j]>tcaspos[i])
                                        {
                                            //permutation de nom de gouvernorat
                                            strcpy(taux[1]->nom,tgouv[j]->nom);
                                            strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                            strcpy(tgouv[i]->nom,taux[1]->nom);
                                            //permutation des cas positifs
                                            k=tcaspos[j];
                                            tcaspos[j]=tcaspos[i];
                                            tcaspos[i]=k;
                                            //permutation des guerisons
                                            k=tger[j];
                                            tger[j]=tger[i];
                                            tger[i]=k;
                                            //permutation des deces
                                            k=tdeces[j];
                                            tdeces[j]=tdeces[i];
                                            tdeces[i]=k;
                                            //permutation des nombres de vaccins
                                            k=tnbrvacc[j];
                                            tnbrvacc[j]=tnbrvacc[i];
                                            tnbrvacc[i]=k;


                                        }
                                    }
                                }



                            }
                            else if(cle[1]==1)
                            {
                                j=0;
                                i=0;
                                taux[1] = listeCreer();
                                for(j=0; j<t; j++)
                                {
                                    for(i=0; i<t; i++)
                                    {
                                        if(tger[j]>tger[i])
                                        {

                                            strcpy(taux[1]->nom,tgouv[j]->nom);
                                            strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                            strcpy(tgouv[i]->nom,taux[1]->nom);

                                            k=tcaspos[j];
                                            tcaspos[j]=tcaspos[i];
                                            tcaspos[i]=k;

                                            k=tger[j];
                                            tger[j]=tger[i];
                                            tger[i]=k;

                                            k=tdeces[j];
                                            tdeces[j]=tdeces[i];
                                            tdeces[i]=k;

                                            k=tnbrvacc[j];
                                            tnbrvacc[j]=tnbrvacc[i];
                                            tnbrvacc[i]=k;


                                        }
                                    }
                                }

                            }
                            else if(cle[2]==1)
                            {
                                j=0;
                                i=0;
                                taux[1] = listeCreer();
                                for(j=0; j<t; j++)
                                {
                                    for(i=0; i<t; i++)
                                    {
                                        if(tdeces[j]>tdeces[i])
                                        {
                                            strcpy(taux[1]->nom,tgouv[j]->nom);
                                            strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                            strcpy(tgouv[i]->nom,taux[1]->nom);

                                            k=tcaspos[j];
                                            tcaspos[j]=tcaspos[i];
                                            tcaspos[i]=k;

                                            k=tger[j];
                                            tger[j]=tger[i];
                                            tger[i]=k;

                                            k=tdeces[j];
                                            tdeces[j]=tdeces[i];
                                            tdeces[i]=k;

                                            k=tnbrvacc[j];
                                            tnbrvacc[j]=tnbrvacc[i];
                                            tnbrvacc[i]=k;


                                        }
                                    }
                                }

                            }
                            else if(cle[3]==1)
                            {
                                j=0;
                                i=0;
                                taux[1] = listeCreer();
                                for(j=0; j<t; j++)
                                {
                                    for(i=0; i<t; i++)
                                    {
                                        if(tnbrvacc[j]>tnbrvacc[i])
                                        {
                                            strcpy(taux[1]->nom,tgouv[j]->nom);
                                            strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                            strcpy(tgouv[i]->nom,taux[1]->nom);

                                            k=tcaspos[j];
                                            tcaspos[j]=tcaspos[i];
                                            tcaspos[i]=k;

                                            k=tger[j];
                                            tger[j]=tger[i];
                                            tger[i]=k;

                                            k=tdeces[j];
                                            tdeces[j]=tdeces[i];
                                            tdeces[i]=k;

                                            k=tnbrvacc[j];
                                            tnbrvacc[j]=tnbrvacc[i];
                                            tnbrvacc[i]=k;


                                        }
                                    }
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            if(cle[0]==1)
                            {
                                //<>
                                if(cle[1]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if((tcaspos[j]==tcaspos[i]) && (tger[j]>tger[i]))
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }
                                        }
                                    }

                                }
                                else if(cle[2]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tdeces[j]>tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }

                                        }
                                    }
                                }
                                else if(cle[3]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tnbrvacc[j]>tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }

                                        }
                                    }

                                    //</>
                                }
                                else if(cle[1]==1)
                                {
                                    //<>
                                    if(cle[0]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tger[j]==tger[i] && tcaspos[j]>tcaspos[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }

                                            }
                                        }
                                    }
                                    else if(cle[2]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tger[j]==tger[i] && tdeces[j]>tdeces[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }

                                            }
                                        }
                                    }
                                    else if(cle[3]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tger[j]==tger[i] && tnbrvacc[j]>tnbrvacc[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }

                                            }
                                        }
                                    }
                                    //</>
                                }
                                else if(cle[2]==1)
                                {
                                    //<>
                                    if(cle[0]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tdeces[j]==tdeces[i] && tcaspos[j]>tcaspos[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }
                                            }
                                        }
                                    }
                                    else if(cle[1]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tdeces[j]==tdeces[i] && tger[j]>tger[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }
                                            }
                                        }


                                    }
                                    else if(cle[3]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tdeces[j]==tdeces[i] && tnbrvacc[j]>tnbrvacc[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }
                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            if(cle[3]==1)
                            {
                                //<>
                                if(cle[0]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tcaspos[j]>tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }
                                        }
                                    }
                                }
                                else if(cle[1]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tger[j]>tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tdeces[j]>tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            break;
                        }
                        case 3 :
                        {
                            if(cle[0]==2)
                            {
                                //<>
                                if(cle[1]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tger[j]>tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tdeces[j]>tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tnbrvacc[j]>tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            else if(cle[1]==2)
                            {
                                //<>
                                if(cle[0]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tcaspos[j]>tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tdeces[j]>tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tnbrvacc[j]>tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            else if(cle[2]==2)
                            {
                                //<>
                                if(cle[0]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tcaspos[j]>tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[1]==3)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tger[j]>tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==3)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tnbrvacc[j]>tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            else if(cle[3]==2)
                            {
                                //<>
                                if(cle[0]==3)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tcaspos[j]>tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[1]==3)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tger[j]>tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==3)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tdeces[j]>tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            break;
                        }
                        case 4 :
                        {
                            if(cle[0]==3)
                            {
                                //<>
                                if(cle[1]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tger[j]>tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tdeces[j]>tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tnbrvacc[j]>tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }

                                }

                                //</>
                            }
                            else if(cle[1]==3)
                            {
                                //<>
                                if(cle[0]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tcaspos[j]>tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tdeces[j]>tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tnbrvacc[j]>tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            else if(cle[2]==3)
                            {
                                //<>
                                if(cle[0]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tcaspos[j]>tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[1]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tger[j]>tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tnbrvacc[j]>tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            else if(cle[3]==3)
                            {
                                //<>
                                if(cle[0]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tcaspos[j]>tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[1]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tger[j]>tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tdeces[j]>tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                //</>

                            }
                            break ;
                        }
                        }
                        x++;
                    }
                    while(x!=4);

                    for(int g=0; g<t; g++)
                    {
                        printf("%s            \t|        %i\t|         %i\t|          %i\t|           %i\n",tgouv[g]->nom,tcaspos[g],tger[g],tdeces[g],tnbrvacc[g]);
                    }
                }
                else
                    printf("\nDate introuvable\n\n");
            }
            if(ordre==1)
            {
                char a[1],v[1],c[1],d[1];
                int l=0,cle[4];
                do
                {
                    l++;
                    if(l>1)
                    {
                        printf("error\n");
                    }
                    printf("Donner le cle des cas positifs :");
                    gets(a);
                }
                while(!Choix_Valide_Tri(a));
                cle[0]=atoi(a);
                l=0;
                do
                {
                    l++;
                    if(l>1)
                    {
                        printf("error\n");
                    }
                    printf("Donner le cle des guerisions:");
                    gets(v);

                }
                while((!Choix_Valide_Tri(v))||(cle[0]==atoi(v)));
                cle[1]=atoi(v);

                l=0;
                do
                {
                    l++;
                    if(l>1)
                    {
                        printf("error\n");
                    }

                    printf("Donner le cle de nombre deces:");
                    gets(c);

                }
                while((cle[0]==atoi(c) || cle[1] ==atoi(c) )||(!Choix_Valide_Tri(c)));
                cle[2]=atoi(c);
                l=0;
                do
                {
                    l++;
                    if(l>1)
                    {
                        printf("error\n");
                    }
                    printf("Donner le cle de nombre de vaccines:");
                    gets(d);
                }
                while((cle[0]==atoi(d) || cle[1]==atoi(d) || cle[2]==atoi(d))||(!Choix_Valide_Tri(d)));
                cle[3]=atoi(d);
                printf("Table des cl%c de priorit%c: |",130,130);
                for(i=0; i<4; i++)
                    printf("%i|",cle[i]);
                i=0;
                printf("\n");

                int j=0;
                int k,x,t;

                bool b,test;
                int jour,annee;
                char mois[10];


                j=1;
                k=0;
                t=0;
                r=0;
                do
                {
                    if(r>0)
                        printf("Date Invalide\n");
                    printf("tapez la date de l'information a Triee\n");
                    printf("tapez le jour : ");
                    scanf("%i",&jour);
                    do
                    {
                        printf("tapez le mois : ");
                        scanf("%s",mois);
                    }
                    while(!alphabetique(mois));
                    GouvernoratValide(mois);
                    printf("tapez l'ann%ce : ",130);
                    scanf("%i",&annee);
                    test=false;
                    x=1;
                    while((x<=12)&&(!test))
                    {
                        if(strcmp(mois,m[x])==0)
                            test=true;
                        else
                            x++;
                    }
                    r++;
                }
                while(!datevalide(jour,x,annee,Time));

                for(k=0; k<24; k++)
                {
                    j=1;
                    b=false;
                    if(!estVide(gov[k]))
                    {
                        while(j<=listeTaille(gov[k]) && !b)
                        {

                            if((recuperer(gov[k],j)->jour==jour)&&(recuperer(gov[k],j)->annee==annee)&&(strcmp(recuperer(gov[k],j)->mois,mois)==0))
                            {
                                b=true;
                                tgouv[t] = listeCreer();
                                strcpy(tgouv[t]->nom,gov[k]->nom);
                                tcaspos[t]=recuperer(gov[k],j)->caspos;
                                tger[t]=recuperer(gov[k],j)->casger;
                                tdeces[t]=recuperer(gov[k],j)->deces;
                                tnbrvacc[t]=recuperer(gov[k],j)->nbrvacc;
                                t++;
                            }
                            else
                                j++;


                        }
                    }

                }
                if(t!=0)
                {
                    i=0;
                    x=1;
                    do
                    {

                        switch (x)
                        {

                        case 1:
                        {

                            if(cle[0]==1)
                            {
                                j=0;
                                i=0;
                                taux[1] = listeCreer();
                                for(j=0; j<t; j++)
                                {
                                    for(i=0; i<t; i++)
                                    {
                                        if(tcaspos[j]<tcaspos[i])
                                        {
                                            //permutation de nom de gouvernorat
                                            strcpy(taux[1]->nom,tgouv[j]->nom);
                                            strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                            strcpy(tgouv[i]->nom,taux[1]->nom);
                                            //permutation des cas positifs
                                            k=tcaspos[j];
                                            tcaspos[j]=tcaspos[i];
                                            tcaspos[i]=k;
                                            //permutation des guerisons
                                            k=tger[j];
                                            tger[j]=tger[i];
                                            tger[i]=k;
                                            //permutation des deces
                                            k=tdeces[j];
                                            tdeces[j]=tdeces[i];
                                            tdeces[i]=k;
                                            //permutation des nombres de vaccins
                                            k=tnbrvacc[j];
                                            tnbrvacc[j]=tnbrvacc[i];
                                            tnbrvacc[i]=k;


                                        }
                                    }
                                }



                            }
                            else if(cle[1]==1)
                            {
                                j=0;
                                i=0;
                                taux[1] = listeCreer();
                                for(j=0; j<t; j++)
                                {
                                    for(i=0; i<t; i++)
                                    {
                                        if(tger[j]<tger[i])
                                        {

                                            strcpy(taux[1]->nom,tgouv[j]->nom);
                                            strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                            strcpy(tgouv[i]->nom,taux[1]->nom);

                                            k=tcaspos[j];
                                            tcaspos[j]=tcaspos[i];
                                            tcaspos[i]=k;

                                            k=tger[j];
                                            tger[j]=tger[i];
                                            tger[i]=k;

                                            k=tdeces[j];
                                            tdeces[j]=tdeces[i];
                                            tdeces[i]=k;

                                            k=tnbrvacc[j];
                                            tnbrvacc[j]=tnbrvacc[i];
                                            tnbrvacc[i]=k;


                                        }
                                    }
                                }

                            }
                            else if(cle[2]==1)
                            {
                                j=0;
                                i=0;
                                taux[1] = listeCreer();
                                for(j=0; j<t; j++)
                                {
                                    for(i=0; i<t; i++)
                                    {
                                        if(tdeces[j]<tdeces[i])
                                        {
                                            strcpy(taux[1]->nom,tgouv[j]->nom);
                                            strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                            strcpy(tgouv[i]->nom,taux[1]->nom);

                                            k=tcaspos[j];
                                            tcaspos[j]=tcaspos[i];
                                            tcaspos[i]=k;

                                            k=tger[j];
                                            tger[j]=tger[i];
                                            tger[i]=k;

                                            k=tdeces[j];
                                            tdeces[j]=tdeces[i];
                                            tdeces[i]=k;

                                            k=tnbrvacc[j];
                                            tnbrvacc[j]=tnbrvacc[i];
                                            tnbrvacc[i]=k;


                                        }
                                    }
                                }

                            }
                            else if(cle[3]==1)
                            {
                                j=0;
                                i=0;
                                taux[1] = listeCreer();
                                for(j=0; j<t; j++)
                                {
                                    for(i=0; i<t; i++)
                                    {
                                        if(tnbrvacc[j]<tnbrvacc[i])
                                        {
                                            strcpy(taux[1]->nom,tgouv[j]->nom);
                                            strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                            strcpy(tgouv[i]->nom,taux[1]->nom);

                                            k=tcaspos[j];
                                            tcaspos[j]=tcaspos[i];
                                            tcaspos[i]=k;

                                            k=tger[j];
                                            tger[j]=tger[i];
                                            tger[i]=k;

                                            k=tdeces[j];
                                            tdeces[j]=tdeces[i];
                                            tdeces[i]=k;

                                            k=tnbrvacc[j];
                                            tnbrvacc[j]=tnbrvacc[i];
                                            tnbrvacc[i]=k;


                                        }
                                    }
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            if(cle[0]==1)
                            {
                                //<>
                                if(cle[1]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if((tcaspos[j]==tcaspos[i]) && (tger[j]<tger[i]))
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }
                                        }
                                    }

                                }
                                else if(cle[2]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tdeces[j]<tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }

                                        }
                                    }
                                }
                                else if(cle[3]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tnbrvacc[j]<tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }

                                        }
                                    }

                                    //</>
                                }
                                else if(cle[1]==1)
                                {
                                    //<>
                                    if(cle[0]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tger[j]==tger[i] && tcaspos[j]<tcaspos[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }

                                            }
                                        }
                                    }
                                    else if(cle[2]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tger[j]==tger[i] && tdeces[j]<tdeces[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }

                                            }
                                        }
                                    }
                                    else if(cle[3]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tger[j]==tger[i] && tnbrvacc[j]<tnbrvacc[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }

                                            }
                                        }
                                    }
                                    //</>
                                }
                                else if(cle[2]==1)
                                {
                                    //<>
                                    if(cle[0]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tdeces[j]==tdeces[i] && tcaspos[j]<tcaspos[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }
                                            }
                                        }
                                    }
                                    else if(cle[1]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tdeces[j]==tdeces[i] && tger[j]<tger[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }
                                            }
                                        }


                                    }
                                    else if(cle[3]==2)
                                    {
                                        j=0;
                                        i=0;
                                        taux[1] = listeCreer();
                                        for(j=0; j<t; j++)
                                        {
                                            for(i=0; i<t; i++)
                                            {
                                                if(tdeces[j]==tdeces[i] && tnbrvacc[j]<tnbrvacc[i])
                                                {
                                                    strcpy(taux[1]->nom,tgouv[j]->nom);
                                                    strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                    strcpy(tgouv[i]->nom,taux[1]->nom);

                                                    k=tcaspos[j];
                                                    tcaspos[j]=tcaspos[i];
                                                    tcaspos[i]=k;

                                                    k=tger[j];
                                                    tger[j]=tger[i];
                                                    tger[i]=k;

                                                    k=tdeces[j];
                                                    tdeces[j]=tdeces[i];
                                                    tdeces[i]=k;

                                                    k=tnbrvacc[j];
                                                    tnbrvacc[j]=tnbrvacc[i];
                                                    tnbrvacc[i]=k;


                                                }
                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            if(cle[3]==1)
                            {
                                //<>
                                if(cle[0]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tcaspos[j]<tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }
                                        }
                                    }
                                }
                                else if(cle[1]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tger[j]<tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==2)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tdeces[j]<tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;


                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            break;
                        }
                        case 3 :
                        {
                            if(cle[0]==2)
                            {
                                //<>
                                if(cle[1]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tger[j]<tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tdeces[j]<tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tnbrvacc[j]<tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            else if(cle[1]==2)
                            {
                                //<>
                                if(cle[0]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tcaspos[j]<tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tdeces[j]<tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tnbrvacc[j]<tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;
                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            else if(cle[2]==2)
                            {
                                //<>
                                if(cle[0]==3)
                                {
                                    j=0;
                                    i=0;
                                    taux[1] = listeCreer();
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tcaspos[j]<tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[1]==3)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tger[j]<tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==3)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tnbrvacc[j]<tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            else if(cle[3]==2)
                            {
                                //<>
                                if(cle[0]==3)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tcaspos[j]<tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[1]==3)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tger[j]<tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==3)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tdeces[j]<tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            break;
                        }
                        case 4 :
                        {
                            if(cle[0]==3)
                            {
                                //<>
                                if(cle[1]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tger[j]<tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tdeces[j]<tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tcaspos[j]==tcaspos[i] && tnbrvacc[j]<tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }

                                }

                                //</>
                            }
                            else if(cle[1]==3)
                            {
                                //<>
                                if(cle[0]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tcaspos[j]<tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tdeces[j]<tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tger[j]==tger[i] && tnbrvacc[j]<tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            else if(cle[2]==3)
                            {
                                //<>
                                if(cle[0]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tcaspos[j]<tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[1]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tger[j]<tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[3]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tdeces[j]==tdeces[i] && tnbrvacc[j]<tnbrvacc[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                //</>
                            }
                            else if(cle[3]==3)
                            {
                                //<>
                                if(cle[0]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tcaspos[j]<tcaspos[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[1]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tger[j]<tger[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                else if(cle[2]==4)
                                {
                                    for(j=0; j<t; j++)
                                    {
                                        for(i=0; i<t; i++)
                                        {
                                            if(tnbrvacc[j]==tnbrvacc[i] && tdeces[j]<tdeces[i])
                                            {
                                                strcpy(taux[1]->nom,tgouv[j]->nom);
                                                strcpy(tgouv[j]->nom,tgouv[i]->nom);
                                                strcpy(tgouv[i]->nom,taux[1]->nom);

                                                k=tcaspos[j];
                                                tcaspos[j]=tcaspos[i];
                                                tcaspos[i]=k;

                                                k=tger[j];
                                                tger[j]=tger[i];
                                                tger[i]=k;

                                                k=tdeces[j];
                                                tdeces[j]=tdeces[i];
                                                tdeces[i]=k;

                                                k=tnbrvacc[j];
                                                tnbrvacc[j]=tnbrvacc[i];
                                                tnbrvacc[i]=k;

                                            }
                                        }
                                    }
                                }
                                //</>

                            }
                            break ;
                        }
                        }
                        x++;
                    }
                    while(x!=4);

                    for(int g=0; g<t; g++)
                    {
                        printf("%s            \t|        %i\t|         %i\t|          %i\t|           %i\n",tgouv[g]->nom,tcaspos[g],tger[g],tdeces[g],tnbrvacc[g]);
                    }
                }
                else
                    printf("\nDate introuvable\n\n");
            }

            break;
        }
        case 6:
        {
            system("cls");
            int i;
            bool b;
            char gouvernorat[24],ch[255];
            bd=fopen("fich.txt","r");
            if(fgets(ch,1,bd)==NULL)
            {
                printf("fichier vide\n");
            }
            else
            {
                ELEMENT e1=elementCreer();
                fseek(bd,114,SEEK_SET);
                while(fgets(ch,106,bd)!=NULL)
                {
                    e1=ChaineToElement(ch,gouvernorat);
                    i=0;
                    b=false;
                    while((i<=23)&&(!b))
                    {
                        if(strcmp(gouvernorat,gov[i]->nom)==0)
                        {
                            b=true;
                            inserer(gov[i],e1,listeTaille(gov[i])+1);
                        }
                        else
                            i++;
                    }

                }
                printf("\ninformations importer avec succ%cs\n\n",138);
            }
            fclose(bd);

            break;
        }
        case 7:
        {
            system("cls");
             printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tMerci\n");
            break;
        }

        }
    }
    while(choix!=7);
    return 0;
}
