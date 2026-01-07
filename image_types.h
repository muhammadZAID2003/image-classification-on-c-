#ifndef IMAGE_TYPES_H
#define IMAGE_TYPES_H

#include <cstdint>

struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};


struct YCbCr {
    uint8_t y;
    uint8_t cb;
    uint8_t cr;
};

struct Kernel {
    const int8_t* coeffs;   
    uint8_t size;     
    int norm;        
};

#endif 