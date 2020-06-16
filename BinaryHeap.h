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
    CPU_Job(int a=0, int b=0, int c=0):ID(a), length(b), prior(c){}
    bool operator<(const CPU_Job& right);
    bool operator>(const CPU_Job& right);
    //bool operator<(const CPU_Job& job); // compares jobs priorities and/or IDs
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
        int getSize(){return heap.size();}
        void printHeap();
};
// overload the () or the < operator for 2  CPU_Jobs
bool CPU_Job::operator<(const CPU_Job& right) {
    if(this->prior < right.prior) { // higher priority
        return true;
    }else if(this->prior== right.prior){ // high priority id ID is less
        if(this->ID < right.ID){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool CPU_Job::operator>(const CPU_Job& right) {
    if(this->prior > right.prior) {
        return true;
    } else if(this->prior == right.prior){
        if(this->ID > right.ID){
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }
}
ostream& operator << (ostream& os, const CPU_Job& r1) { // outputs certain records in stated format
    // O(1)
    os << "Job " << r1.ID << " with length " << r1.length << " and priority " << r1.prior << endl;
    return os;
}


template<typename T>
T BinaryHeap<T>::remove_min()
{
    // pop the top element
    // restructure the heap to have new min at the top
    // everything else also in mpq order
    if (heap.size() == 0){
        throw EmptyTree("Queue is empty!");
    } else if (heap.size() == 1){
        T min = heap.at(0);
        heap.pop_back();
        return min;
    }

    T min = heap.at(0);
    //cout << "Min now: "<< heap.at(0); // check to see what new end is
    int size = heap.size();
    //cout << "End element after before swap: " <<  heap.at(size - 1) << endl; // check to see what new end is
    swap(heap.at(0), heap.at(size - 1)); // swapping first and last elements
    //cout << "End element after swap now: " <<  heap.at(size - 1)<< endl; // check to see what new end is
    heap.pop_back(); //delete old min
    size = heap.size(); // new size of vector
    //cout << "Min after swap: "<< heap.at(0)<< endl;
    //cout << "Last element after pop_back:" << heap.at(size - 1)<< endl; // check to see what new end is

    int index = 0;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    //cout << leftChild << " " << rightChild << endl;
    if(size == 2 && heap.at(0) > heap.at(1)){
        swap(heap.at(0), heap.at(1));
    } else {
        while((leftChild < getSize() && rightChild < getSize()) && (heap[index] > heap[leftChild] || heap[index] > heap[rightChild])){
            //cout << " ---------------------" << endl;
            if(heap[leftChild] < heap[rightChild]){
                swap(heap.at(index), heap.at(leftChild));
                index = leftChild;
            } else {
                swap(heap.at(index), heap.at(rightChild));
                index = rightChild;
            }
            leftChild = 2*index + 1;
            rightChild = 2*index + 2;
            //cout << leftChild << " " << rightChild <<  " "<<getSize() << endl;
        } 
    }
    return min;

}
template<typename T>
void BinaryHeap<T>::printHeap()
{
    for(size_t i = 0; i < heap.size(); i++){
        cout << heap.at(i);
    }
    //cout << endl;
}

template<typename T>
void BinaryHeap<T>::insert(T add) // like buildHeap()
{
    heap.push_back(add);
    int index = heap.size() - 1;
    if(heap.size() > 1){
        while(index >= 1){
            if (heap.at(index) < heap.at((index - 1) / 2)){
                swap(heap.at(index), heap.at((index - 1)/ 2));
            }
            index = (index - 1)/ 2;
        }
    }
}



#endif