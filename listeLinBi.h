#ifndef LISTLINBI_H_INCLUDED
#define LISTLINBI_H_INCLUDED

#include "listeLinBi.c"

//2- liste linéaire doublement chainée ( bi-directionnelles )
listeLinBi* creerListeLinBi();
int tailleListeLinBi(listeLinBi *tete);
int listeLinBiVide(listeLinBi *tete);
int listeLinBiPleine(listeLinBi *tete);
listeLinBi* supprimerFinListeLinBi(listeLinBi *tete);
listeLinBi* supprimerDebutListeLinBi(listeLinBi *tete);
listeLinBi* ajouterFinListeLinBi(listeLinBi *tete, texte *elem);
listeLinBi* ajouterDebutListeLinBi(listeLinBi *tete, texte *elem);
texte* retournerTexteListeLinBi(listeLinBi *tete, int pos);
void afficherListeLinBi(listeLinBi *tete);
listeLinBi* ctrlzListeLinBi(listeLinBi *tete);

#endif // LISTLINBI_H_INCLUDED
