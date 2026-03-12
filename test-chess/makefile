# Define the compiler and flags
CXX = g++ -g
CXXFLAGS = -std=c++20 -Wall -Wextra
# Define the source files and the executable name
SRCS = main.cpp chessboard.cpp figure.cpp
TARGET = chess
# Rule to build the target executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
# Clean rule to delete object files and the executable
clean:
	rm -f $(TARGET)
# Phony targets
.PHONY: clean