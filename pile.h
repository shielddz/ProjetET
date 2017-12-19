#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#include "pile.c"
pile initPile();
int taillePile(pile *maPile);
int pileVide(pile *maPile);
int pilePleine(pile *maPile);
texte SommetPile(pile *maPile);
texte depiler(pile *maPile);
void empiler(pile *maPile, texte *elem);
void afficherPile(pile maPile);
void ctrlzPile(pile *maPile);

#endif // PILE_H_INCLUDED
