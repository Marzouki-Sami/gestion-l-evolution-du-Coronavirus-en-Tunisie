#ifndef _LSTPRIM_H
#define  _LSTPRIM_H

#include "ELTPRIM.H"
#include "LSTSDD.H"

LISTE listeCreer(void);
void listeDetruire(LISTE);
int estVide(LISTE);
int estSaturee(LISTE);
int listeTaille(LISTE);
ELEMENT recuperer(LISTE, int);
int inserer(LISTE, ELEMENT,int);
int supprimer(LISTE, int);
void modifier(LISTE, int);
void listeAfficher(LISTE);
void listeAfficher0(LISTE);
LISTE listeCopier(LISTE);
int  listeComparer1(LISTE, LISTE);
int  listeComparer2(LISTE, LISTE);
int  listeComparer3(LISTE, LISTE);
int  listeComparer4(LISTE, LISTE);

#endif
