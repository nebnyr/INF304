#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "type_tableau.h"
#include "es_tableau.h"
#include "test_tri.h"
#include "tri.h"

int main(int argc, char ** argv) {

  tableau_entiers t;
  FILE *ftab;
  char nom_fichier[256];

  if (argc < 2) {
    printf("Usage: %s <fichier d'entree>\n", argv[0]);
  } else {
    /* À modifier pour les exercices 3 à 6 */
    lire_tableau(argv[1], &t);
    tri_insertion(&t);
    strcpy(nom_fichier, argv[1]);
    strcat(nom_fichier, ".out");
    ecrire_tableau(nom_fichier, &t);
    /* test_tri_insertion(argc, argv); */
    /* test_tri_insertion_alea(argc, argv); */
  }
}
