#include <iostream>
#include <cstdint>


// stb (SIRF AIK FILE ME IMPLEMENTATION KRNI, STB KAHIN AUR USE NHI KARENGE)

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"


// Your project headers

#include "image_types.h"
#include "filters.h"
#include "conv2d.h"
#include "greyscale.h"
#include "rgb_2_ycbcr.h"

int main()
{

    // Load image.png (RGB)

    int width, height, channels;

    uint8_t* rgb = stbi_load(
        "image.png",
        &width,
        &height,
        &channels,
        3               // force RGB
    );

    if (!rgb) {
        std::cerr << "ERROR: Failed to load image.png\n";
        return -1;
    }

    std::cout << "Loaded image: "
              << width << " x " << height << "\n";

    int total = width * height;


    // Allocation of the buffers

    YCbCr* ycbcr = new YCbCr[total];

	uint8_t* Y			= new uint8_t[total];
	uint8_t* Cb 		= new uint8_t[total];
	uint8_t* Cr 		= new uint8_t[total];

    uint8_t* Y_blur    	= new uint8_t[total];
    uint8_t* Y_sharp   	= new uint8_t[total];

    uint8_t* Y_sobel_blur  = new uint8_t[total];
	uint8_t* Y_sobel_sharp = new uint8_t[total];

	uint8_t* rgb_blur  = new uint8_t[total * 3];
	uint8_t* rgb_sharp = new uint8_t[total * 3];


    // RGB → Grayscale (Y)

    const RGB* rgb_struct = reinterpret_cast<const RGB*>(rgb);

	rgb_image_to_ycbcr(
	    rgb_struct,
	    ycbcr,
	    width,
	    height);

	for (int i = 0; i < total; i++) {
    	Y[i]  = ycbcr[i].y;
    	Cb[i] = ycbcr[i].cb;
    	Cr[i] = ycbcr[i].cr;
	}


    // Save grayscale image

    stbi_write_png(
        "grayscale.png",
        width,
        height,
        1,          // 1 channel
        Y,
        width       // stride = width * 1
    );


    // Gaussian blur on Y

    conv2d(
        Y,
        Y_blur,
        width,
        height,
        GAUSSIAN,
        1,
        1);

    stbi_write_png(
        "blur.png",
        width,
        height,
        1,
        Y_blur,
        width
    );

    for (int i = 0; i < total; i++) {
	    RGB p = ycbcr_to_rgb(Y_blur[i], Cb[i], Cr[i]);

	    rgb_blur[3*i + 0] = p.r;
	    rgb_blur[3*i + 1] = p.g;
	    rgb_blur[3*i + 2] = p.b;
	}

	stbi_write_png(
	    "color_blur.png",
	    width,
	    height,
	    3,
	    rgb_blur,
	    width * 3
	);



    // Sharpen on Y

    conv2d(
        Y,
        Y_sharp,
        width,
        height,
        SHARPEN,1,1);

    stbi_write_png(
        "sharpen.png",
        width,
        height,
        1,
        Y_sharp,
        width);

    for (int i = 0; i < total; i++) {
	    RGB p = ycbcr_to_rgb(Y_sharp[i], Cb[i], Cr[i]);

	    rgb_sharp[3*i + 0] = p.r;
	    rgb_sharp[3*i + 1] = p.g;
	    rgb_sharp[3*i + 2] = p.b;
	}

    stbi_write_png(
	    "color_sharpen.png",
	    width,
	    height,
	    3,
	    rgb_sharp,
	    width * 3
	);

 
	// Sobel on blurred image

	conv2d(
	    Y_blur,
	    Y_sobel_blur,
	    width,
	    height,
	    SOBEL,
	    1,1);

	stbi_write_png(
	    "sobel_blur.png",
	    width,
	    height,
	    1,
	    Y_sobel_blur,
	    width);


	// Sobel on sharpened image

	conv2d(
	    Y_sharp,
	    Y_sobel_sharp,
	    width,
	    height,
	    SOBEL,
	    1,1);

	stbi_write_png(
	    "sobel_sharp.png",
	    width,
	    height,
	    1,
	    Y_sobel_sharp,
	    width
	);



    // Cleaning up buffers 

    stbi_image_free(rgb);

    delete[] Y;
	delete[] Cb;
	delete[] Cr;
	delete[] Y_blur;
	delete[] Y_sharp;
	delete[] rgb_blur;
	delete[] rgb_sharp;
	delete[] ycbcr;

    std::cout << "Pipeline complete:\n"
              << "  grayscale.png\n"
              << "  blur.png\n"
              << "  sharpen.png\n"
              << "	sobel_blur.png\n"
              << "	sobel_sharp.png";

    return 0;
}
