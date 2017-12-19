#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

#include "myHeader.c"

texte creer();
void liberer(texte *t);
int taille(texte t);
int capacite(texte t);
char caractere(texte t, int pos);
void modifierCapacite(texte *t, int minimum);
void modifierCapacite2(texte *t, int minimum);
void ajouterCaractere(texte *t, char caractere);
void ajouterChaine(texte *t, char *str);
int position(texte t, char *str);
int dernierePosition(texte t, char *str);
void insererChaine(texte *t, char *str, int debut);

//fonctions reliées au menu
void cls();
int chooseStruct();
int chooseMethod();
int chooseMenu();
int chooseSubMenu2();
int chooseSubMenu3();
int chooseSubMenu4();
int chooseSubMenu7();

#endif // MYHEADER_H_INCLUDED
