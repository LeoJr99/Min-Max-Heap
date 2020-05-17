// minMaxHeap.h 

#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <vector> 

class minMaxHeap {
public: 

    // prints heap in order they appear in array 
    void printHeap() const;

    // returns max of heap 
    void getMax() const; 
    // returns min of heap
    void getMin() const; 
 
    // inserts value into heap
    void insert(int i); 

    void insertNew(int i); 

    // deletes min 
    void deleteMin();
    // delete Max  
    void deleteMax(); 


private: 

    // vector representation of heap 
    std::vector<int> heap; 

    // returns parent of 'node' at index i 
    int getParent(int i) const; 
    // returns grandparent of 'node' at index i
    int getGrandParent(int i) const; 
    // returns left child of index i 
    int getChildLeft(int i) const; 
    // returns right child of index i
    int getChildRight(int i) const;

    int getMinGrandChild(int i) const;
    int getMaxGrandChild(int i) const; 

    // returns true if value at index i is at a min level
    bool isMinLevel(int i) const; 

    void percolateUpMin(int i); 
    void percolateDownMin(int i); 

    void percolateUpMax(int i); 
    void percolateDownMax(int i);

    void percolateDown(int i); 
    void percolateUp(int i); 

}; 

#endif