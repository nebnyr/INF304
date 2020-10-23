#include "terrain.h"
#include <stdio.h>

int main(int argc, char **argv) {
  Terrain t;
  int x, y;

  if (argc < 2) {
    printf("Usage : %s <fichier>\n", argv[0]);
    return 1;
  }

  lire_terrain(argv[1], &t, &x, &y);
  afficher_terrain(&t);
  printf("Position initiale du robot : (%d, %d)\n", x, y);
}
