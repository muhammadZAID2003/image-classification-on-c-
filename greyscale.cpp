#include <iostream>
#include <cstdint>

#include "image_types.h"
#include "rgb_2_ycbcr.h"

#include "greyscale.h"

void rgb_image_to_ycbcr(

    const RGB* rgb_img,
    YCbCr* ycbcr_img,
    int width,
    int height ){

    int total = width * height;

    for (int i = 0; i < total; i++) {
        ycbcr_img[i] = rgb_2_ycbcr(rgb_img[i]);
    }
}
