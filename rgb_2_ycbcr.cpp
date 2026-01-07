#include <cstdint>

#include "image_types.h"
#include "rgb_2_ycbcr.h"

YCbCr rgb_2_ycbcr(const RGB& p)
{
    int y  = (  77*p.r + 150*p.g +  29*p.b) >> 8;
    int cb = ((-43*p.r -  85*p.g + 128*p.b) >> 8) + 128;
    int cr = ((128*p.r - 107*p.g -  21*p.b) >> 8) + 128;

    // clamp to 8-bit
    if (y  < 0) y  = 0; if (y  > 255) y  = 255;
    if (cb < 0) cb = 0; if (cb > 255) cb = 255;
    if (cr < 0) cr = 0; if (cr > 255) cr = 255;

    return {
        (uint8_t)y,
        (uint8_t)cb,
        (uint8_t)cr
    };
}

inline uint8_t clamp_u8(int v) {
    if (v < 0)   return 0;
    if (v > 255) return 255;
    return (uint8_t)v;
}

RGB ycbcr_to_rgb(uint8_t y, uint8_t cb, uint8_t cr)
{
    int Cb = cb - 128;
    int Cr = cr - 128;

    int r = y + ((359 * Cr) >> 8);
    int g = y - (( 88 * Cb + 183 * Cr) >> 8);
    int b = y + ((454 * Cb) >> 8);

    return {
        clamp_u8(r),
        clamp_u8(g),
        clamp_u8(b)
    };
}