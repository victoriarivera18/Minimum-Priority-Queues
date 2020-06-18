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
    bool operator==(const CPU_Job& right);
    //bool operator<(const CPU_Job& job); // compares jobs priorities and/or IDs
};


struct EmptyTree : public std::runtime_error {
  explicit EmptyTree(char const* msg=nullptr): runtime_error(msg) {}
};


template<typename T>
class BinaryHeapObj //obj
{
    public:
        vector<T> vect;
        BinaryHeapObj(int sz = 0): vect(sz){}
        T remove_min();
        bool is_empty(){ return vect.size() == 0;}
        void insert(T add);
        int getSize(){return vect.size();}

};

template<typename T>
T BinaryHeapObj<T>::remove_min() // O(logn) (does walk downs)
{
    // pop the top element
    // restructure the heap to have new min at the top
    // everything else also in mpq order
    if (vect.size() == 0){
        throw EmptyTree("Queue is empty!");
    } else if (vect.size() == 1){
        T min = vect.at(0);
        vect.pop_back();
        return min;
    }

    T min = vect.at(0);
    int size = vect.size();
    swap(vect.at(0), vect.at(size - 1)); // swapping first and last elements
    vect.pop_back(); //delete old min
    size = vect.size(); // new size of vector
    

    int index = 0;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    //cout << leftChild << " " << rightChild << endl;
    if(size == 2 && vect.at(0) > vect.at(1)){
        swap(vect.at(0), vect.at(1));
    } else {
        while((leftChild < getSize() && rightChild < getSize()) && (vect[index] > vect[leftChild] || vect[index] > vect[rightChild])){
            //cout << " ---------------------" << endl;
            if(vect[leftChild] < vect[rightChild]){
                swap(vect.at(index), vect.at(leftChild));
                index = leftChild;
            } else {
                swap(vect.at(index), vect.at(rightChild));
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
void BinaryHeapObj<T>::insert(T add) // O(logn) (does walk ups)
{
    vect.push_back(add);
    int index = vect.size() - 1;
    if(vect.size() > 1){
        while(index >= 1){
            if (vect.at(index) < vect.at((index - 1) / 2)){
                swap(vect.at(index), vect.at((index - 1)/ 2));
            }
            index = (index - 1)/ 2;
        }
    }
}



//binary heap implementation using a vector
template<typename T>
class BinaryHeap // wrapper
{
    private:
        BinaryHeapObj<T> heap; //vector can be of type CPU_Job
    public:
        BinaryHeap(int size = 0): heap(size){}
        T remove_min() { return heap.remove_min(); }
        bool is_empty(){ return heap.getSize() == 0; }
        void insert(T add){ heap.insert(add); }
        int getSize(){ return heap.getSize(); }
        void printHeap();
};



bool CPU_Job::operator<(const CPU_Job& right) { // O(1)
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

bool CPU_Job::operator>(const CPU_Job& right) { // O(1)
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

bool CPU_Job::operator==(const CPU_Job& right) { // O(1)
    if(this->prior == right.prior) {
        if(this->ID == right.ID){
            if(this->length > right.length){
            return true;
            }
        }
    }
     return false;
}


ostream& operator << (ostream& os, const CPU_Job& r1) { // outputs certain records in stated format
    // O(1)
    os << "Job " << r1.ID << " with length " << r1.length << " and priority " << r1.prior << endl;
    return os;
}


template<typename T>
void BinaryHeap<T>::printHeap()
{
    for(size_t i = 0; i < heap.getSize(); i++){
        cout << heap.vect.at(i);
    }
}



#endif