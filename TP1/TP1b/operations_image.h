#ifndef _OPERATIONS_IMAGE_H_
#define _OPERATIONS_IMAGE_H_

#include "type_image.h"

/* Calcule l'image "inverse" (négative) de l'image im1, et place le
   résultat dans l'image im2 */

void inverse_video(Image im1, Image *im2);

void symetrie_horizontal(Image im1, Image *im2);

void symetrie_vertical(Image im1, Image *im2);

void rotation_90_r(Image im1, Image *im2);

void rotation_90_l(Image im1, Image *im2);

void div_val_pix_by_2(Image im1, Image *im2);

void mult_val_pix_by_2(Image im1, Image *im2)

#endif
