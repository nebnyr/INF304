#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "es_tableau.h"
#include "tri.h"
#define RAND_MAX 256

void test_tri_insertion(int argc, char ** argv) {
  tableau_entiers t;
  FILE *ftab;
  char nom_fichier[256];

  lire_tableau(argv[1], &t);
  tri_insertion(&t);
  strcpy(nom_fichier, argv[1]);
  strcat(nom_fichier, ".out");
  ecrire_tableau(nom_fichier, &t);
}

void test_tri_insertion_alea(int argc, char ** argv) {
  /* À compléter */
  tableau_entiers t;
  FILE *ftab;
  char nom_fichier[256];

  int total=rand();
  lire_tableau(argv[1], &t);
  tab[0]=total;
  for(int i=1, i < t->taille, i++){
    tab[i]=rand();
  }
  tri_insertion(&t);
  strcpy(nom_fichier, argv[1]);
  strcat(nom_fichier, ".out");
  ecrire_tableau(nom_fichier, &t);
}
