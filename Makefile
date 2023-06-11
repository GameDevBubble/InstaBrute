CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
TARGET = InstaBrute

# Set the output directory outside of the root directory
OUTPUT_DIR = InstaBrute/build

# SDL2 flags and libraries
SDL2_FLAGS = $(shell sdl2-config --cflags)
SDL2_LIBS = $(shell sdl2-config --libs)

# Additional libraries
LIBS = -lpthread -lSDL2_image -lSDL2_ttf

SRCS = src/main.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@if [ ! -d "$(OUTPUT_DIR)" ]; then mkdir -p $(OUTPUT_DIR); fi
	$(CXX) $(CXXFLAGS) $(SDL2_FLAGS) -o $(OUTPUT_DIR)/$@ $^ $(SDL2_LIBS) $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(SDL2_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUTPUT_DIR)/$(TARGET)
