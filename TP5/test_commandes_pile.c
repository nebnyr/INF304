#include <stdio.h>
#include "commandes_pile.h"


int main (int argc, char** argv) 
{
  FILE * fichier = NULL;
  if (argc != 2 ) 
    {
      printf("mauvaise utilisation : donnez un nom de fichier en argument\n") ;
      return 0;
    } 

	
  fichier = ouvrir_commandes (argv [1] );
  commande command;


  int value;

  while (!fin_commandes (fichier))
    {
      command = commande_suivante(fichier);
      print_commandes ( command ) ;		
    }
  fermer_commandes (fichier);
  return 0;
}
