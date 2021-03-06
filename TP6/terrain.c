
#include "terrain.h"
#include "robot.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

erreur_terrain lire_terrain(char *nom_fichier, Terrain *t, int *x, int *y)
{
  FILE *f;
  char line[DIM_MAX + 2];

  // Ouverture du fichier en lecture
  f = fopen(nom_fichier, "r");
  if (f == NULL)
  {
    return ERREUR_FICHIER;
  }

  // Lecture de la hauteur
  // À compléter
  if (fscanf(f, "%d", &t->largeur) != 1)
  {
    return ERREUR_LECTURE_LARGEUR;
  }

  // Lecture de la largeur
  // À compléter
  if (fscanf(f, "%d", &t->hauteur) != 1)
  {
    return ERREUR_LECTURE_HAUTEUR;
  }

  if (t->hauteur > DIM_MAX || t->hauteur < 0)
  {
    return ERREUR_HAUTEUR_INCORRECTE;
  }
  if (t->largeur > DIM_MAX || t->largeur < 0)
  {
    return ERREUR_LARGEUR_INCORRECTE;
  }
  fscanf(f, "\n");
  int Position_initiale = 0;

  // Lecture du terrain
  // À compléter
  for (int i = 0; i < t->hauteur; i++)
  {
    if (fgets(line, sizeof(line), f) == NULL)
    {
      return ERREUR_LIGNE_MANQUANTE;
    }
    if (strlen(line)-1 > t->largeur)
    {
      return ERREUR_LIGNE_TROP_LONGUE;
    }

    for (int j = 0; j < t->largeur; j++)
    {
      Case c;

      switch (line[j])
      {
      case '.':
        c = LIBRE;
        break;
      case '~':
        c = EAU;
        break;
      case '#':
        c = ROCHER;
        break;
      case 'C':
        c = LIBRE;
        if (Position_initiale == 0)
        {
          *x = i;
          *y = j;
          Position_initiale = 1;
        }
        else
        {
          return ERREUR_POSITION_INITIALE_MULTIPLE;
        }
        break;
      default:
        return ERREUR_CARTACTERE_INCORRECT;
        break;
      }
      t->tab[i][j] = c;
    }
    if (strlen(line) < t->largeur)
    {
      return ERREUR_LIGNE_TROP_COURTE;
    }
  }
  if (!x || !y)
  {
    return ERREUR_POSITION_INITIALE_MANQUANTE;
  }
  // Fermeture du fichier
  fclose(f);
  return OK;
}

/* À compléter */
int largeur(Terrain t)
{
  return t.largeur;
}

int hauteur(Terrain t)
{
  return t.hauteur;
}

int est_case_libre(Terrain t, int x, int y)
{
  if (x > 0 && x < t.largeur)
  {
    if (y > 0 && y < t.hauteur)
    {
      if (t.tab[x][y] == LIBRE)
      {
        return 0;
      }
    }
  }
  return 1;
}

void afficher_terrain(Terrain *t)
{
  printf("%d ··· %d\n", t->hauteur, t->largeur);
  for (int i = 0; i < t->hauteur; i++)
  {
    for (int j = 0; j < t->largeur; j++)
    {
      printf("%c", t->tab[i][j]);
      switch (t->tab[i][j])
      {
      case LIBRE:
        printf(".");
        break;
      case EAU:
        printf("~");
        break;
      case ROCHER:
        printf("#");
        break;
      }
    }
    printf("\n");
  }
  printf("\n");
}