#ifndef _LSTREL_H
#define  _LSTREL_H

#include "ELTPRIM.H"

typedef struct structNoeud
{
    ELEMENT info;
    struct structNoeud * precedent;
    struct structNoeud * suivant;
} structNoeud, * NOEUD;

typedef struct
{
    char nom[12];
    NOEUD tete;
    NOEUD queue;
    int lg;
}
laStruct,*LISTE;
#endif
