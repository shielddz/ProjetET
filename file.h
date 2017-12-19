#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "file.c"
file initFile();
int fileVide(file *maFile);
texte *teteFile(file *maFile);
int filePleine(file *maFile);
texte *defile(file *maFile);
void enfiler(file *maFile, texte *elem);
void afficherFile(file maFile);
void ctrlzFile(file *maFile);

#endif // FILE_H_INCLUDED
