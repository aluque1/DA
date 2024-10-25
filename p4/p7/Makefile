CXX = g++
CXXFLAGS = -Wall -g

TARGET = sol
SRCS = sol.cpp
HEADERS = peaje.h graph.h

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)