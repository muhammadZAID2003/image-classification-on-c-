#ifndef CONV_H
#define CONV_H

#include <cstdint>

#include "image_types.h"

int conv2d(
	uint8_t* img_in,
	uint8_t* img_out,
	uint8_t img_w,
	uint8_t img_h,
	Kernel krnl,
	uint8_t stride,
	uint8_t border);


#endif
