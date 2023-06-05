CXX = g++
CXXFLAGS = -std=c++17
TARGET = InstaBrute

# Set the output directory outside of the root directory
OUTPUT_DIR = InstaBrute/build

SRCS = src/main.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@if [ ! -d "$(OUTPUT_DIR)" ]; then mkdir -p $(OUTPUT_DIR); fi
	$(CXX) $(CXXFLAGS) -o $(OUTPUT_DIR)/$@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUTPUT_DIR)/$(TARGET)
