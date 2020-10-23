#ifndef _TERRAIN_H_
#define _TERRAIN_H_

typedef enum { LIBRE, EAU, ROCHER } Case;;

#define DIM_MAX 256

// indexation utilisée :
//  1er  indice : abscisse = colonne (colonne de gauche : abscisse = 0)
//  2ème indice : ordonnée = ligne   (ligne du haut     : ordonnée = 0)

typedef struct {
  int largeur, hauteur;
  Case tab[DIM_MAX][DIM_MAX];
} Terrain;

typedef enum { 
  OK, 
  ERREUR_FICHIER,
  ERREUR_LECTURE_LARGEUR,
  ERREUR_LARGEUR_INCORRECTE,
  ERREUR_LECTURE_HAUTEUR,
  ERREUR_HAUTEUR_INCORRECTE,
  ERREUR_LIGNE_MANQUANTE,
  ERREUR_LIGNE_TROP_COURTE,
  ERREUR_LIGNE_TROP_LONGUE,
  ERREUR_CARTACTERE_INCORRECT,
  ERREUR_POSITION_INITIALE_MANQUANTE,
  ERREUR_POSITION_INITIALE_MULTIPLE,
} erreur_terrain;
 
/* Lecture d'un terrain dans un fichier de nom nom_f
   Résultats :
   t le terrain lu
   x, y position initiale du robot lue dans le fichier terrain
   Renvoie :
   OK si la lecture s'est déroulée correctement
   ERREUR_FICHIER si le fichier n'a pas pu être ouvert
   ... (à compléter)
 */
erreur_terrain lire_terrain(char *nom_fichier, Terrain *t, int *x, int *y);

/* Largeur d'un terrain */
int largeur(Terrain t);

/* Hauteur d'un terrain */
int hauteur(Terrain t);

/* Indique si la case de coordonnées (x,y) est libre
   Renvoie vrai ssi les 3 conditions suivantes sont vraies :
    - 0 <= x < largeur
    - 0 <= y < hauteur
    - t.tab[x][y] = LIBRE
 */
int est_case_libre(Terrain t, int x, int y);

void afficher_terrain(Terrain *t);

#endif
