#ifndef RGB_2_YCBCR_H
#define RGB_2_YCBCR_H

#include "image_types.h"

YCbCr rgb_2_ycbcr(const RGB& p);

inline uint8_t clamp_u8(int v);

RGB ycbcr_to_rgb(uint8_t y, uint8_t cb, uint8_t cr);

#endif