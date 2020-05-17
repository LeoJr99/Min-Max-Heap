// minMaxHeap.cpp

#include "minMaxHeap.h"
#include <iostream>
#include <cmath>
#include <utility>

void minMaxHeap::printHeap() const {

    std::cout << "heap = "; 
    for(int i = 0; i < heap.size(); i++) {
        if (i == heap.size() - 1) {
            std::cout << heap[i];
        }
        else {
            std::cout << heap[i] << " "; 
        }
    }
    std::cout << std::endl; 
}

void minMaxHeap::getMax() const {
    if (heap.empty()) {
        std::cerr << "Empty Heap" << std::endl; 
    }
    else if (heap.size() - 1 == 1) {
        std::cout << "max = " << heap[0] << std::endl; 
    }
    else if (heap.size() - 1 == 2) {
        std::cout << "max = " << heap[1] << std::endl; 
    }
    else {
        if (heap[1] > heap[2]) {
            std::cout << "max = " << heap[1] << std::endl; 
        }
        else {
            std::cout << "max = " << heap[2] << std::endl;
        }
    }
}

void minMaxHeap::getMin() const {
    if (heap.empty()) {
        std::cerr << "Empty Heap" << std::endl; 
    }
    std::cout << "min = " << heap[0] << std::endl;  
}

void minMaxHeap::insert(int value) {
    heap.push_back(value); 
    percolateUp(heap.size() - 1); 
}

void minMaxHeap::insertNew(int value) {
    heap.push_back(value); 
    percolateUp(heap.size() - 1);

    std::cout << "inserted " << value << std::endl; 
}


void minMaxHeap::deleteMin() {

    if(heap.empty()) {
        std::cerr << "Empty Heap" << std::endl; 
    }
    
    std::cout << "deleted " << heap[0] << std::endl; 

    heap[0] = heap[heap.size() - 1]; 
    heap.pop_back(); 
    if(!heap.empty()) {
        percolateDown(0); 
    }
}

void minMaxHeap::deleteMax() {

    if(heap.empty()) {
        std::cerr << "Empty Heap" << std::endl; 
    }

    int maxIndex; 
    
    if (heap.size() > 2) {
        if (heap[1] > heap[2]) {
            maxIndex = 1; 
        }
        else {
            maxIndex = 2; 
        }
    }

    else if(heap.size() == 2) {
        maxIndex = 1; 
    }

    else {
        maxIndex = 0; 
    }

    std::cout << "deleted " << heap[maxIndex] << std::endl; 

    heap[maxIndex] = heap[heap.size() - 1]; 
    heap.pop_back(); 

    if (!heap.empty()) {
        percolateDown(maxIndex); 
    }
}

// Helper Functions ------------------------

int minMaxHeap::getParent(int i) const {
    return (i - 1) / 2; 
}

int minMaxHeap::getGrandParent(int i) const {
    return getParent(getParent(i)); 
}

int minMaxHeap::getChildLeft(int i) const {
    return 2 * i + 1; 
}

int minMaxHeap::getChildRight(int i) const {
    return 2 * i + 2; 
}

int minMaxHeap::getMinGrandChild(int i) const {
    int leftmostGrandChild = getChildLeft(getChildLeft(i)); 
    int rightmostGrandChild = getChildRight(getChildRight(i)); 

    int min = leftmostGrandChild; 

    for(int j = leftmostGrandChild + 1; j <= rightmostGrandChild && j < heap.size(); j++) {
        if(heap[j] < heap[min]) {
            min = j; 
        }
    }
    return min; 
}

int minMaxHeap::getMaxGrandChild(int i) const {
    int leftmostGrandChild = getChildLeft(getChildLeft(i)); 
    int rightmostGrandChild = getChildRight(getChildRight(i)); 

    int max = leftmostGrandChild; 

    for(int j = leftmostGrandChild + 1; j <= rightmostGrandChild && j < heap.size(); j++) {
        if(heap[j] > heap[max]) {
            max = j; 
        }
    }
    return max;
}

bool minMaxHeap::isMinLevel(int i) const {

    int logResult = floor(log2(i + 1)); 
    if (logResult % 2 == 0) {
        return true; 
    }
    else   
        return false; 
}

void minMaxHeap::percolateUpMin(int i) {

    if (i == 0) 
        return;
         
    int parentOfi = getParent(i);
         
    if (heap[i] < heap[parentOfi]) {
        while (i != 0) {
            if (heap[i] < heap[getGrandParent(i)])
                std::swap(heap[i], heap[getGrandParent(i)]);
            i = getGrandParent(i);
        }
    }
         
    if (heap[i] > heap[parentOfi]) {
        std::swap(heap[i], heap[parentOfi]);
        i = getParent(i);
        while (i != 1 && i != 2) {
            if (heap[i] >= heap[getGrandParent(i)])
                std::swap(heap[i], heap[getGrandParent(i)]);
            i = getGrandParent(i);
        }
    }


    /*
    if (i > 2) {
        if (heap[i] < heap[getGrandParent(i)]) {
            std::swap(heap[i], heap[getGrandParent(i)]); 
            percolateUpMin(getGrandParent(i)); 
        }
    }
    */ 

}

void minMaxHeap::percolateDownMin(int i) {
    if (getChildLeft(i) < heap.size() || getChildRight(i) < heap.size()) {
        int minIndex = i; 
        if (heap.at(getChildLeft(i)) < heap.at(getChildRight(i))) {
            minIndex = getChildLeft(i); 
        }
        else {
            minIndex = getChildRight(i);
        }

        int grandChildMin = getMinGrandChild(i); 
        if (heap[grandChildMin] < heap[minIndex]) {
            minIndex = grandChildMin; 
        }

        if (minIndex < heap.size()) {
            if(heap[minIndex] < heap[i]) {
                std::swap(heap[i], heap[minIndex]); 
                if (heap[minIndex] > heap[getParent(minIndex)]) {
                    std::swap(heap[minIndex], heap[getParent(minIndex)]); 
                }
                percolateDownMin(minIndex); 
            }
            else if(minIndex == getChildRight(i) || minIndex == getChildLeft(i)) {
                if (heap[minIndex] < heap[i]) {
                    std::swap(heap[i], heap[minIndex]); 
                }
            }
        }
    }
} 

void minMaxHeap::percolateUpMax(int i) {

    if(i == 1 || i == 2) {
        if (heap[i] < heap[0]) {
            std::swap(heap[i], heap[0]); 
        }
        return; 
    }

    int parentOfI = getParent(i); 

    if (heap[i] > heap[parentOfI]) {
        while (i > 2) {
            if (heap[i] > heap[getGrandParent(i)]) {
                std::swap(heap[i], heap[getGrandParent(i)]);
            }
            i = getGrandParent(i); 
        }
    }

    if (heap[i] < heap[parentOfI]) {
        std::swap(heap[i], heap[parentOfI]);
        i = getParent(i); 
        while (i > 0) {
            if (heap[i] < heap[getGrandParent(i)]) {
                std::swap(heap[i], heap[getGrandParent(i)]); 
            }
            i = getGrandParent(i); 
        }
    }
} 

void minMaxHeap::percolateDownMax(int i){
    int maxIndex = i; 
    if(getChildLeft(i) < heap.size() - 1) {
        if (getChildRight(i) < heap.size() - 1) {
            if (heap[getChildLeft(i)] > heap[getChildRight(i)]) {
                maxIndex = getChildLeft(i); 
            }
            else 
                maxIndex = getChildRight(i);
        }
        maxIndex = getChildLeft(i); 
    }

    int grandChildMax = getMaxGrandChild(i); 
    if(heap[grandChildMax] > heap[maxIndex]) {
        maxIndex = grandChildMax; 
    }
    if (maxIndex == grandChildMax) {
        if (heap[maxIndex] > heap[i]) {
            std::swap(heap[maxIndex], heap[i]);  
            if (heap[maxIndex] < heap[getParent(maxIndex)]) {
                std::swap(heap[maxIndex], heap[getParent(maxIndex)]);
            }
            percolateDownMin(maxIndex); 
        }
        else if (maxIndex == getChildRight(i) || maxIndex == getChildLeft(i)) {
            if (heap[maxIndex] > heap[i]) {
                std::swap(heap[maxIndex], heap[i]);
            }
        }
    }

    maxIndex = i; 
    int childLeft = getChildLeft(maxIndex); 
    int childRight = getChildRight(maxIndex); 

    if (heap[maxIndex] < heap[childLeft]) {
        std::swap(heap[maxIndex], heap[childLeft]);  
    }

    else if (heap[maxIndex] < heap[childRight]) {
        std::swap(heap[maxIndex], heap[childRight]);
    }

}

void minMaxHeap::percolateDown(int i) {

    if (isMinLevel(i)) {
        percolateDownMin(i); 
    }

    else {
        percolateDownMax(i); 
    }
    
} 

void minMaxHeap::percolateUp(int i) {
    if(isMinLevel(i)) {
        percolateUpMin(i); 
    }

    else {
        percolateUpMax(i); 
    }
}