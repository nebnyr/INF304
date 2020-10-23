#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recherche.h"

#define LMAX 10000

int main(int argc, char * argv[]) {

  /* Fichier d'entrée */
  FILE * fentree;
  /* Chaîne d'entrée */
  char chaine[LMAX];
  /* Sous-chaîne à rechercher */
  char souschaine[LMAX];
  int res;
  
  if (argc < 2) {
    fprintf(stderr, "Erreur : pas assez d'arguments\n");
    fprintf(stderr, "Usage: %s <fichier>\n", argv[0]);
    exit(1);
  }
  
  /* Ouverture du fichier d'entree en lecture */
  fentree = fopen(argv[1], "r");
  /* Lecture de la chaîne d'entrée */
  fgets(chaine, LMAX, fentree);
  /* Lecture de la sous-chaîne */
  fgets(souschaine, LMAX, fentree);
  /* Retrait du retour chariot de la chaine et de la sous-chaîne */
  chaine[strlen(chaine)-1] = '\0';
  souschaine[strlen(souschaine)-1] = '\0';
  
  /* Recherche de la sous-chaîne */
  res = recherche(chaine, souschaine);
  printf("%d\n", res);
}
