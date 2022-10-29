#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LSTPRIM.H"

NOEUD noeudCreer (ELEMENT e)
{
    NOEUD n;
    n =(NOEUD)malloc(sizeof(structNoeud));
    if(!n)
        printf ("nPlus d'espace");
    else
    {
        elementAffecter(&n->info,e);
        n->suivant =NULL;
        n->precedent =NULL;
    }
    return n;
}
void
noeudDetruire (NOEUD n)
{
    elementDetruire(n->info);
    free(n);
}
LISTE listeCreer (void)
{
    LISTE L=(LISTE)malloc(sizeof(laStruct));
    if (! L)
        printf("Problème de mémoire\n");
    else
    {
        strcpy(L->nom,"");
        L->lg = 0;
        L->tete = NULL;
    }
    return(L);
}

void listeDetruire (LISTE L)
{
    int i;
    NOEUD p, q;
    q= L->tete;
    for(i = 1; i <= L->lg; i++)
    {
        p=q;
        q=q->suivant;
        noeudDetruire(p);
    }
    free(L);
}

int estVide(LISTE L)
{
    return (L->lg == 0);
}


int estSaturee(LISTE L)
{
    NOEUD temp;
    int saturee = 1;
    temp = (NOEUD) malloc ( sizeof ( structNoeud ) );
    if(temp != NULL)
    {
        saturee = 0;
        free(temp);
    }
    return saturee;
}


int listeTaille(LISTE L)
{
    return (L->lg);
}


int inserer (LISTE L, ELEMENT e, int pos)
{
    int i,succee=1;

    NOEUD n, p, q;
    if (estSaturee(L))
    {
        printf ("Liste saturée\n");
        succee=0;
    }
    else
    {
        if ((pos < 1) || (pos > L->lg + 1))
        {
            printf ("Position invalide\n");
            succee=0;
        }
        else
        {
            n=noeudCreer (e);
            if (L->lg == 0)
            {
                L->tete =n;
                L->queue =n;
            }
            else
            {
                if (pos == 1)
                {
                    L->tete->precedent =n;
                    n->suivant=L ->tete;
                    L->tete = n;
                }
                else
                {
                    if (pos == (L->lg +1))
                    {
                        L->queue->suivant =n;
                        n->precedent = L ->queue;
                        L->queue =n;
                    }
                    else
                    {
                        q= L->tete;
                        for (i=1; i<pos; i++)
                        {
                            p = q;
                            q = q->suivant;
                        }
                        p->suivant=n;
                        n->precedent =p;
                        n->suivant=q;
                        q->precedent =n;
                    }
                }
            }
            (L->lg)++;
        }
    }
    return succee;
}

int supprimer (LISTE L, int pos )
{
    int i,succee=1;
    NOEUD p, q;
    if (estVide(L))
    {
        printf ("Liste vide\n");
        succee=0;
    }
    else
    {
        if ((pos < 1) || (pos > L->lg))
        {
            printf ("Position invalide\n");
            succee=0;
        }
        else
        {
            if (L->lg ==1)
            {
                q=L->tete;
                L->tete =NULL;
                L->queue =NULL;
            }
            else
            {
                if (pos == 1)
                {
                    q=L->tete;
                    L->tete=L->tete->suivant;
                    L->tete->precedent =NULL;
                }
                else
                {
                    if (pos == L->lg)
                    {
                        q=L->queue;
                        L->queue = L->queue->precedent;
                        L->queue->suivant =NULL;
                    }
                    else
                    {
                        q= L->tete;
                        for (i=1; i<pos; i++)
                        {
                            p = q;
                            q = q->suivant;
                        }
                        q->suivant->precedent =p;
                        p->suivant=q->suivant;
                    }
                }
            }
            noeudDetruire(q);
            (L->lg)--;
        }
    }
    return succee;
}

void modifier(LISTE l,int pos)
{
    ELEMENT e=elementCreer();
    e->jour=recuperer(l,pos)->jour;
    strcpy(e->mois,recuperer(l,pos)->mois);
    e->annee=recuperer(l,pos)->annee;
    int choice;
    do
    {
        printf("1-modifier les cas positifs\n");
        printf("2-modifier les Gu%crisons\n",130);
        printf("3-Modifier les d%cc%cs\n",130,138);
        printf("4-modifier les vaccin%cs\n",130);
        printf("5-confirmer la modification\n");
        printf("Tapez votre choix : ");
        fflush(stdin);
        scanf("%i",&choice);
        printf("\n");
        switch (choice)
        {
        case 1:
        {
            do
            {
                printf("tapez le nombre des cas positifs : ");
                fflush(stdin);
                scanf("%i",&e->caspos);
                printf("\n");
            }
            while(e->caspos<0);
            e->casger=recuperer(l,pos)->casger;
            e->deces=recuperer(l,pos)->deces;
            e->nbrvacc=recuperer(l,pos)->nbrvacc;
            supprimer(l,pos);
            inserer(l,e,pos);
            break;
        }
        case 2:
        {
            do
            {
                printf("tapez le nombre des Gu%crisons : ",130);
                fflush(stdin);
                scanf("%i",&e->casger);
                printf("\n");
            }
            while(e->casger<0);
            e->caspos=recuperer(l,pos)->caspos;
            e->deces=recuperer(l,pos)->deces;
            e->nbrvacc=recuperer(l,pos)->nbrvacc;
            supprimer(l,pos);
            inserer(l,e,pos);
            break;
        }
        case 3:
        {
            do
            {
                printf("tapez le nombre de d%cc%cs : ",130,138);
                fflush(stdin);
                scanf("%i",&e->deces);
                printf("\n");
            }
            while(e->deces<0);
            e->casger=recuperer(l,pos)->casger;
            e->caspos=recuperer(l,pos)->caspos;
            e->nbrvacc=recuperer(l,pos)->nbrvacc;
            supprimer(l,pos);
            inserer(l,e,pos);
            break;
        }
        case 4:
        {
            do
            {
                printf("tapez le nombre de vaccin%cs : ",130);
                fflush(stdin);
                scanf("%i",&e->nbrvacc);
                printf("\n");
            }
            while(e->nbrvacc<0);
            e->casger=recuperer(l,pos)->casger;
            e->deces=recuperer(l,pos)->deces;
            e->caspos=recuperer(l,pos)->caspos;
            supprimer(l,pos);
            inserer(l,e,pos);
            break;
        }
        }
    }
    while(choice<=4 && choice>=1);
}

ELEMENT recuperer(LISTE L, int pos)
{

    ELEMENT elt= elementCreer();
    int i;
    NOEUD p;
    if (estVide(L))
        printf ("\nListe vide");
    else if ((pos < 1) || (pos > L->lg))
        printf ("nPosition invalide");
    else
    {
        p= L->tete;
        for (i=1; i<pos; i++)
            p = p->suivant;

        elementAffecter(&elt,p->info);
    }
    return(elt);
}


void listeAfficher(LISTE L)
{
    int i;
    NOEUD p;
    p= L->tete;
    for(i = 1; i <= L->lg; i++)
    {
        elementAfficher(p->info);
        p= p->suivant;
    }

}

void listeAfficher0(LISTE L)
{
    int i;
    NOEUD p;
    p= L->tete;
    for(i = 1; i <= L->lg; i++)
    {
        elementAfficher0(p->info);
        p= p->suivant;
    }

}

LISTE listeCopier (LISTE L)
{
    LISTE LR = listeCreer();
    int i;
    ELEMENT elt;
    for(i = 1; i <= L->lg; i++)
    {
        elt=elementCreer();
        elementCopier(&elt, recuperer(L,i));
        inserer(LR,elt, i);
    }
    return LR;
}


int  listeComparer1 (LISTE L1,LISTE L2 )
{
    int test= 1;
    int i=1;

    if (listeTaille(L1) != listeTaille(L2)) test= 0;

    while ((i<=listeTaille(L1)) && (test))
    {
        if (elementComparer1(recuperer(L1,i),recuperer(L2,i))!=0)
            test=0;
        i++;
    }

    return test;
}
int  listeComparer2 (LISTE L1,LISTE L2 )
{
    int test= 1;
    int i=1;

    if (listeTaille(L1) != listeTaille(L2)) test= 0;

    while ((i<=listeTaille(L1)) && (test))
    {
        if (elementComparer2(recuperer(L1,i),recuperer(L2,i))!=0)
            test=0;
        i++;
    }

    return test;
}
int  listeComparer3 (LISTE L1,LISTE L2 )
{
    int test= 1;
    int i=1;

    if (listeTaille(L1) != listeTaille(L2)) test= 0;

    while ((i<=listeTaille(L1)) && (test))
    {
        if (elementComparer3(recuperer(L1,i),recuperer(L2,i))!=0)
            test=0;
        i++;
    }

    return test;
}
int  listeComparer4 (LISTE L1,LISTE L2 )
{
    int test= 1;
    int i=1;

    if (listeTaille(L1) != listeTaille(L2))
        test= 0;

    while ((i<=listeTaille(L1)) && (test))
    {
        if (elementComparer4(recuperer(L1,i),recuperer(L2,i))!=0)
            test=0;
        i++;
    }

    return test;
}


