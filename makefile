# Makefile

#CXX = g++
CXX = clang++ 

CXXFLAGS = -std=c++11 -Wall -g

all: prog2.out

prog2.out: minMaxHeap.o prog2.o
	${CXX} ${CXXFLAGS} $^ -o $@