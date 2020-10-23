
#include <stdio.h>

#include "type_image.h"
#include "operations_image.h"
#include "image_io.h"

int main(int argc, char ** argv) {
  Image im_init;
  Image im_inv;

  if (argc != 3) {
    printf("Il faut 2 arguments : un fichier image en entree et un fichier image en sortie\n");
  } else {
    lecture_fichier(argv[1], &im_init);
    mult_val_pix_by_2(im_init, &im_inv);
    ecriture_fichier(argv[2], im_inv);
  }
}
