#ifndef _ELTPRIM_H
#define _ELTPRIM_H
#include "ELTSDD.H"
#include <stdbool.h>
#include <windows.h>
bool datevalide(int ,int ,int ,SYSTEMTIME );
ELEMENT elementCreer(void) ;
void elementLire00(ELEMENT*);
void elementLire(ELEMENT*);
void elementDetruire (ELEMENT);
void elementAfficher(ELEMENT);
void elementAfficher0(ELEMENT);
void elementAffecter(ELEMENT*, ELEMENT);
void elementCopier(ELEMENT *, ELEMENT) ;
int elementComparer1(ELEMENT, ELEMENT);
int elementComparer2(ELEMENT, ELEMENT);
int elementComparer3(ELEMENT, ELEMENT);
int elementComparer4(ELEMENT, ELEMENT);
int elementComparer5(ELEMENT, ELEMENT);
#endif
