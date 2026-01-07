# FPGA-Based Image Processing Pipeline Simulator
(C++ Hardware Accelerator Model)
# Project Overview

This project simulates a simplified FPGA/SoC-style image processing pipeline using C++, modeling how hardware accelerator teams at Xilinx, Intel, and NVIDIA Embedded Vision design and verify image-processing pipelines before RTL implementation.

The design follows a hardware-oriented mindset, focusing on data flow, memory buffers, pipeline stages, and modular processing blocks, rather than purely software-style image manipulation.

# Project Goal

Simulate a hardware image-processing pipeline in C++

Model FPGA/ASIC-style modules such as buffers, filters, and convolution engines

Practice hardware-software co-design concepts

Prepare a foundation for future RTL / HLS / FPGA implementations

Pipeline Architecture
Load Image
   ↓
Color Conversion (RGB → Grayscale)
   ↓
Smoothing Filter (3×3 Average)
   ↓
Convolution Engine (Sharpen / Sobel / Gaussian)
   ↓
Edge Detection
   ↓
Save Output Image


Each stage mimics a hardware processing block, operating on frame buffers and passing data to the next stage.

# Key Features
Feature	Description
Image Frame Buffer	Implemented using pointers and dynamic memory
Modular Design	Pipeline stages modeled as structs/classes
Custom Data Types	struct Pixel { uint8_t r, g, b; };
Memory Management	new/delete or malloc/free
Compile-Time Modes	#ifdef USE_FIXED_POINT, #ifdef DEBUG
Multi-File Design	main.cpp, pipeline.cpp, filters.cpp, etc.
OOP Concepts	Polymorphism for filter modules
Hardware Modeling	Registers, FIFOs, processing cores simulated
Makefile	Builds all modules into a single executable

#  Modules (Header-Based Design)
Module	Function
Frame Reader	Loads input image into pixel buffer
Color Converter	Converts RGB → Grayscale
Smoothing Filter	3×3 average filter
Convolution Engine	Sharpen, Gaussian, Sobel edge detection
Memory Buffer / FIFO	Simulates hardware buffers
Output Writer	Saves final processed image
Debug Logger	Displays internal registers when DEBUG enabled
# Concepts Used
Concept	Application
struct	Pixel, buffers, and module definitions
Pointers	Frame buffers and memory blocks
#ifdef / #endif	Debug mode, FPGA mode, fixed-point mode
Function Pointers	Dynamically plug filters
Dynamic Memory	Input and output image buffers
OOP & Inheritance	Base Filter class → derived filters
Namespaces	hardware::pipeline
Templates	Kernel size and pixel type
Makefile	Multi-file compilation and linking
# Project Structure
.
├── include/
│   ├── pixel.h
│   ├── buffer.h
│   ├── filter.h
│   └── pipeline.h
├── src/
│   ├── main.cpp
│   ├── pipeline.cpp
│   ├── filters.cpp
│   └── utils.cpp
├── Makefile
└── README.md

# Build & Run
Build the Project
make

Run the Simulator
./image_pipeline input_image.bmp output_image.bmp

# Debug Mode

Enable internal register and buffer visibility:

#define DEBUG
or via compiler flag:
make DEBUG=1

# Possible Extensions
Extension	Description
DMA Simulation	Hardware-style data streaming
Multi-threading	Multi-core processing model
Fixed-Point Math	Hardware-accurate data types
OpenCV Integration	Output verification
CLI Control	Runtime pipeline configuration
HLS Mapping	Prepare for FPGA synthesis
🎓 Learning Outcomes

Hardware-oriented C++ design

Image processing pipeline modeling

Memory & buffer management

Modular accelerator-style architecture

Foundation for FPGA, HLS, and RTL design

# Conclusion

This project bridges the gap between software image processing and hardware accelerator design, making it ideal for students and engineers targeting FPGA, ASIC, embedded vision, and IC design roles.

