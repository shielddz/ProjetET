#ifndef LISTLIN_H_INCLUDED
#define LISTLIN_H_INCLUDED

#include "listeLin.c"

//1- la liste linéaire chainée
listeLin* creerListeLin();
int tailleListeLin(listeLin *tete);
int listeLinVide(listeLin *tete);
int listeLinPleine(listeLin *tete);
listeLin* supprimerFinListeLin(listeLin *tete);
listeLin* supprimerDebutListeLin(listeLin *tete);
listeLin* ajouterFinListeLin(listeLin *tete, texte *elem);
listeLin* ajouterDebutListeLin(listeLin *tete, texte *elem);
texte* retournerPosListeLin(listeLin *tete, int pos);
void afficherListeLin(listeLin *tete);
listeLin* ctrlzListeLin(listeLin *tete);

#endif // LISTLIN_H_INCLUDED
