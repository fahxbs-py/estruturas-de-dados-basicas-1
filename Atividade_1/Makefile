# Makefile 
CXX      := g++
CXXFLAGS := -Iinclude_cpp -std=c++17 -Wall

# Make expande os arquivos .c e .cpp
SRCS_CPP := $(wildcard src_cpp/*.cpp)

.PHONY: all clean test_cpp

all: test_cpp


test_cpp:
	$(CXX) $(CXXFLAGS) $(SRCS_CPP) test_cpp/test_algorithms.cpp -o test_cpp_exec
	./test_cpp_exec

clean:
	rm -f test_cpp_exec
