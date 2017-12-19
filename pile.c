//4- la structure de la Pile ( Stack )

//la structure
typedef struct pile{
    texte tab[10];
    int sommet;
}pile;

//initialiser la pile
pile initPile(){
    pile maPile;
    int i;
    maPile.sommet = 0;
    for(i = 0; i<10; i++){
        maPile.tab[i] = creer();
    }
    return maPile;
}

//taille pile
int taillePile(pile *maPile){
    return maPile->sommet;
}

//retourne 1 si la pile est vide, 0 sinon
int pileVide(pile *maPile){
    if(!maPile->sommet){
        return 1;
    }
    return 0;
}

//retourne 1 si la taille de la pile est égale a 10, 0 sinon
int pilePleine(pile *maPile){
    if(maPile->sommet == 10){
        return 1;
    }
    return 0;
}

//retourne le texte qui se trouve au sommet de la pile
texte SommetPile(pile *maPile){
    texte output;
    if(!pileVide(maPile)){
        return maPile->tab[(maPile->sommet)-1];
    }else{
        output = creer();
        printf("Liste Vide");
        return output;
    }
}

//retourne le texte en sommet, et le supprime de la pile ( decrementer sommet );
texte depiler(pile *maPile){
    texte output;
    if(!pileVide(maPile)){
        output = SommetPile(maPile);
        maPile->sommet--;
        maPile->tab[maPile->sommet] = creer();
        return output;
    }else{
        output = creer();
        printf("Liste Vide");
        return output;
    }
}

//empile un element au sommet;
void empiler(pile *maPile, texte *elem){
    int i;
    texte temp[9];
    texte del;
    if(pilePleine(maPile)){
        for(i=0; i<9; i++){
            temp[i] = depiler(maPile);
        }
        del = depiler(maPile);
        for(i=0; i<9; i++){
            maPile->tab[8-i] = temp[i];
            maPile->sommet++;
        }
    }
    ajouterChaine(&(maPile->tab[maPile->sommet]), elem->chaine);
    maPile->sommet++;

}

//afficher toutes les versions du texte dans la pile
void afficherPile(pile maPile){
    int i;
    if(pileVide(&maPile)){
        printf("La liste est vide.\n");
    }else{
        for(i=0; i < maPile.sommet; i++){
            printf("Version %d: '%s'.\n", i+1, maPile.tab[i].chaine);
        }
    }
}

void ctrlzPile(pile *maPile){
    texte *del = NULL;
    if(pileVide(maPile)){
        printf("Il n'existe aucune ancienne version.\n");
    }else{
        del = &(maPile->tab[maPile->sommet-1]);
        maPile->sommet--;
        maPile->tab[maPile->sommet] = creer();
        free(del);
    }
}
