#include "terrain.h"
#include <stdio.h>

int main(int argc, char **argv) {
  Terrain t;
  int x, y;

  if (argc < 2) {
    printf("Usage : %s <fichier>\n", argv[0]);
    return 1;
  }
  char *fichier = &argv[1];
  while (lire_terrain(*fichier, &t, &x, &y) == ERREUR_FICHIER){
    printf("Erreur fichier invalide\nVeuillez entrer un nouveau fichier : ");
    scanf("%s", fichier);    
  }

  lire_terrain(argv[1], &t, &x, &y);
  afficher_terrain(&t);
  printf("Position initiale du robot : (%d, %d)\n", x, y);
}
