#include <iostream>
#include <cstdint>
#include <algorithm>

#include "conv2d.h"


int conv2d(
	uint8_t* img_in,
	uint8_t* img_out,
	uint8_t img_w,
	uint8_t img_h,
    Kernel krnl,
	uint8_t stride,
	uint8_t border){
    
    int k_half = krnl.size / 2;

    for (int ir = 0; ir < img_h; ir += stride) {
        for (int ic = 0; ic < img_w; ic += stride) {

            int32_t accum = 0;

            for (int khr = -k_half; khr <= k_half; khr++) {
                for (int kch = -k_half; kch <= k_half; kch++) {

                    int jr = ir + khr;
                    int jc = ic + kch;

                    uint8_t pixel = 0;

                    // Border handling
                    if (jr < 0 || jr >= img_h || jc < 0 || jc >= img_w) {
                        if (border) { // replicate
                            jr = (jr < 0) ? 0 : (jr >= img_h ? img_h - 1 : jr);
                            jc = (jc < 0) ? 0 : (jc >= img_w ? img_w - 1 : jc);
                            pixel = img_in[jr * img_w + jc];
                        }
                    } else {
                        pixel = img_in[jr * img_w + jc];
                    }

                    int kr = khr + k_half;
                    int kc = kch + k_half;

                    accum += pixel * krnl.coeffs[kr * krnl.size + kc];
                }
            }
            if (krnl.norm != 0) {
    			accum = accum / krnl.norm;
			}

            if (accum < 0) accum = 0;
            if (accum > 255) accum = 255;

            img_out[ir * img_w + ic] = (uint8_t)accum;
        }
    }

    return 0;
}
