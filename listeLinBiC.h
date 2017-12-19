#ifndef LISTELINBIC_H_INCLUDED
#define LISTELINBIC_H_INCLUDED

#include "listeLinBiC.c"

//3- liste linéaire circulaire doublement chainée( bi-directionnelle circulaires)
int tailleLisetLinBiC(listeLinBi *tete);
int listeLinBiCPleine(listeLinBi *tete);
listeLinBi* supprimerDebutListeLinBiC(listeLinBi *tete);
listeLinBi* supprimerFinListeLinBiC(listeLinBi *tete);
listeLinBi* ajouterDebutListeLinBiC(listeLinBi *tete, texte *elem);
listeLinBi* ajouterFinListeLinBiC(listeLinBi *tete, texte *elem);
texte* retournerTexteListeLinBiC(listeLinBi *tete, int pos);
void afficherListeLinBiC(listeLinBi *tete);
listeLinBi* ctrlzListeLinBiC(listeLinBi *tete);

#endif // LISTELINBIC_H_INCLUDED
