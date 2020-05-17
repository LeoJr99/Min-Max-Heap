# Makefile

#CXX = g++
CXX = clang++ 

CXXFLAGS = -std=c++11 -Wall

all: prog2.out

prog2: minMaxHeap.o prog2.o
	${CXX} ${CXXFLAGS} $^ -o $@