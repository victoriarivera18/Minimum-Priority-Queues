// V. Rivera Casanova
// CSCE 221
// Leyk 199

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

# include <iostream>
# include <stdexcept>
# include <algorithm>  
# include <vector>
# include<bits/stdc++.h>

using namespace std;

struct CPU_Job
{
    int ID;
    int length;
    int prior;
    CPU_Job(int a=0, int b=0, int c=0):ID(a), length(b), prior(c){};

    bool operator<(const CPU_Job& job); // compares jobs priorities and/or IDs
};

struct EmptyTree : public std::runtime_error {
  explicit EmptyTree(char const* msg=nullptr): runtime_error(msg) {}
};

//binary heap implementation using a vector
template<typename T>
class BinaryHeap
{
    private:
        vector<T> heap; //vector can be of type CPU_Job
    public:
        BinaryHeap(int sz = 0): heap(sz){}
        T remove_min();
        bool is_empty(){ return heap.size() == 0;}
        void insert(T add);
};

template<typename T>
T BinaryHeap<T>::remove_min()
{
    // pop the top element
    // restructure the heap to have new min at the top
    // everything else also in mpq order
    if (heap.size() == 0){
        throw EmptyTree("Tree is empty!");
    }
    int min = heap.at(0);
    int size = heap.size();
    swap(heap.at(0), heap.at(size - 1)); // swapping first and last elements
    heap.pop_back(); //delete old min
    size = heap.size(); // new size of vector

    int index = 0;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    while((heap[index] > heap[leftChild] || heap[index] > heap[rightChild]) && (leftChild < size && rightChild < size)){
        if(heap[leftChild] < heap[rightChild]){
            swap(heap.at(index), heap.at(leftChild));
            index = leftChild;
        } else {
            swap(heap.at(index), heap.at(rightChild));
            index = rightChild;
        }
        leftChild = 2*index + 1;
        rightChild = 2*index + 2;
        size = heap.size();
    }
    return min;

}

template<typename T>
void BinaryHeap<T>::insert(T add) // like buildHeap()
{
    heap.push_back(add);
    int index = heap.size() - 1;
    while(index >= 1){
        if (heap.at(index) < heap.at((index - 1) / 2)){
            swap(heap.at(index), heap.at((index - 1)/ 2));
        }
        index = (index - 1)/ 2;
    }
    for(size_t i = 0; i < heap.size(); i++){
        cout << heap.at(i) << " ";
    }
}



#endif