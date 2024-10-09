# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = sol

# Source files
SRCS = sol.cpp

# Header files
HEADERS = TreeSet_AVL.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean