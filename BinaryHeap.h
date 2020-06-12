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
        int remove_min();
        bool is_empty(){ return heap.size() == 0;}
        void insert(int i, int len, int p);
};

#endif