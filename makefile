
# Compiler and flags

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2


# Target executable

TARGET = pipeline


# Source files

SRCS = \
    pipeline.cpp \
    conv2d.cpp \
    filters.cpp \
    rgb_2_ycbcr.cpp \
    greyscale.cpp \




# Object files (auto-generated)

OBJS = $(SRCS:.cpp=.o)


# Default target

all: $(TARGET)


# Link

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)


# Compile

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Clean build artifacts

clean:
	rm -f $(OBJS) $(TARGET)
