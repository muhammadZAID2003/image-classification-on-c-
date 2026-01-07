#ifndef RGB_IMG_TO_YCBCR_H
#define RGB_IMG_TO_YCBCR_H

#include "image_types.h"

void rgb_image_to_ycbcr(

    const RGB* rgb_img,
    YCbCr* ycbcr_img,
    int width,
    int height );

#endif
