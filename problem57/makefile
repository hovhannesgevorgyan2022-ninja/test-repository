# Define the compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall
# Define the source files and the executable name
SRCS = problem57_main.cpp problem57_matrixclass.cpp
TARGET = my_program
# Rule to build the target executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
# Clean rule to delete object files and the executable
clean:
	rm -f $(TARGET)
# Phony targets
.PHONY: clean