CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2

TARGET = sort_test
SRCS = main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	./$(TARGET)
	
clean:
	rm -f $(TARGET)

