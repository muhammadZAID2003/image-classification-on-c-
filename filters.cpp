
#include "filters.h"

// structure of kernel
// kernel.coeff = coefficients matrix of 9 values,
// kernel.size = size of kernel (N)
// kernel.norm = sum of kernel weights for normalization

static const int8_t sobel_x_coeffs[9] = {
    -1,  0,  1,
    -2,  0,  2,
    -1,  0,  1
};

const Kernel SOBEL = {
    sobel_x_coeffs,
    3,
    0
};

static const int8_t gaussian_3x3_coeffs[9] = {
     1, 2, 1,
     2, 4, 2,
     1, 2, 1
};

const Kernel GAUSSIAN = {
    gaussian_3x3_coeffs,
    3,
    16
};

static const int8_t sharpen_3x3_coeffs[9] = {
     0, -1,  0,
    -1,  5, -1,
     0, -1,  0
};

const Kernel SHARPEN = {
    sharpen_3x3_coeffs,
    3,
    1
};



