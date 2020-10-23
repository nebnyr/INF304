#include "terrain.h"
#include <stdio.h>

int main(int argc, char **argv) {
  Terrain t;
  int x, y;

  if (argc < 2) {
    printf("Usage : %s <fichier>\n", argv[0]);
    return 1;
  }
  char *fichier = argv[1];
  while (lire_terrain(fichier, &t, &x, &y) == ERREUR_FICHIER){
    printf("Erreur fichier invalide\nVeuillez entrer un fichier valide : ");
    scanf("%s", fichier);
  }
  afficher_terrain(&t);
  printf("Position initiale du robot : (%d, %d)\n", x, y);

  return 0;
}
