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
}

template<typename T>
void BinaryHeap<T>::insert(T add)
{

}



#endif