#include "operations_image.h"

/* Calcule l'image "inverse" (négative) de l'image im1, et place le
   résultat dans l'image im2 */

void inverse_video(Image im1, Image *im2) {
  Pixel p, p_inverse;
  int l = largeur(im1);
  int h = hauteur(im1);
  int max = maxval(im1);
  /* Indices de parcours de boucles */
  int i,j;
  
  /* Initialisation de l'image résultat, de mêmes largeur, hauteur
     et valeur max que l'image donnée en paramètre */
  init_image(l, h, max, im2);

  /* Parcours de chaque pixel de chaque ligne */
  for(i=0; i<l; i++) {
    for(j=0; j<h; j++) {
      p=lepixel(&im1,i,j);
      p_inverse=max-p;
      affecter_pixel(im2,i,j,p_inverse);
    }
  }
}

void div_val_pix_by_2(Image im1, Image *im2) {
  Pixel p, p_inverse;
  int l = largeur(im1);
  int h = hauteur(im1);
  int max = maxval(im1);
  /* Indices de parcours de boucles */
  int i,j;
  
  /* Initialisation de l'image résultat, de mêmes largeur, hauteur
     et valeur max que l'image donnée en paramètre */
  init_image(l, h, max, im2);

  /* Parcours de chaque pixel de chaque ligne */
  for(i=0; i<l; i++) {
    for(j=0; j<h; j++) {
      p=lepixel(&im1,i,j);
      p_inverse=p/2;      
      affecter_pixel(im2,i,j,p_inverse);
    }
  }
}

void mult_val_pix_by_2(Image im1, Image *im2) {
  Pixel p, p_inverse;
  int l = largeur(im1);
  int h = hauteur(im1);
  int max = maxval(im1);
  /* Indices de parcours de boucles */
  int i,j;
  
  /* Initialisation de l'image résultat, de mêmes largeur, hauteur
     et valeur max que l'image donnée en paramètre */
  init_image(l, h, max, im2);

  /* Parcours de chaque pixel de chaque ligne */
  for(i=0; i<l; i++) {
    for(j=0; j<h; j++) {
      p=lepixel(&im1,i,j);
      p_inverse=p*2;
      if (p_inverse > max)
      {
        p_inverse=max;
      }
           
      affecter_pixel(im2,i,j,p_inverse);
    }
  }
}

void symetrie_horizontal(Image im1, Image *im2) {
  Pixel p, p_inverse;
  int l = largeur(im1);
  int h = hauteur(im1);
  int max = maxval(im1);
  /* Indices de parcours de boucles */
  int i,j,x,y;
  
  /* Initialisation de l'image résultat, de mêmes largeur, hauteur
     et valeur max que l'image donnée en paramètre */
  init_image(l, h, max, im2);

  /* Parcours de chaque pixel de chaque ligne */
  for(i=0; i<l; i++) {
    for(j=0; j<h; j++) {
      p=lepixel(&im1,i,j);
      y=h;
      y-=j;
      affecter_pixel(im2,i,y,p);
    }
  }
}

void symetrie_vertical(Image im1, Image *im2) {
  Pixel p, p_inverse;
  int l = largeur(im1);
  int h = hauteur(im1);
  int max = maxval(im1);
  /* Indices de parcours de boucles */
  int i,j,x,y;
  
  /* Initialisation de l'image résultat, de mêmes largeur, hauteur
     et valeur max que l'image donnée en paramètre */
  init_image(l, h, max, im2);

  /* Parcours de chaque pixel de chaque ligne */
  for(i=0; i<l; i++) {
    for(j=0; j<h; j++) {
      p=lepixel(&im1,i,j);
      x=l;
      x-=i;
      affecter_pixel(im2,x,j,p);
    }
  }
}

void rotation_90_r(Image im1, Image *im2) {
  Pixel p, p_inverse;
  int l = largeur(im1);
  int h = hauteur(im1);
  int max = maxval(im1);
  /* Indices de parcours de boucles */
  int i,j,x,y;
  
  /* Initialisation de l'image résultat, de mêmes largeur, hauteur
     et valeur max que l'image donnée en paramètre */
  init_image(h, l, max, im2);

  /* Parcours de chaque pixel de chaque ligne */
  for(i=0; i<l; i++) {
    for(j=0; j<h; j++) {
      p=lepixel(&im1,i,j);
      x=l;
      x-=i;
      affecter_pixel(im2,j,x,p);
    }
  }
}

void rotation_90_l(Image im1, Image *im2) {
  Pixel p, p_inverse;
  int l = largeur(im1);
  int h = hauteur(im1);
  int max = maxval(im1);
  /* Indices de parcours de boucles */
  int i,j,x,y;
  
  /* Initialisation de l'image résultat, de mêmes largeur, hauteur
     et valeur max que l'image donnée en paramètre */
  init_image(h, l, max, im2);

  /* Parcours de chaque pixel de chaque ligne */
  for(i=0; i<l; i++) {
    for(j=0; j<h; j++) {
      p=lepixel(&im1,i,j);
      x=l;
      y=h;
      x-=i;
      y-=j;
      affecter_pixel(im2,y,i,p);
    }
  }
}