// V. Rivera Casanova
// CSCE 221
// Leyk 199

#ifndef VECTORIMP_H
#define VECTORIMP_H

# include <iostream>
# include <stdexcept>
# include <algorithm>  
# include <vector>
# include<bits/stdc++.h>
# include "BinaryHeap.h"

using namespace std;


template<typename T, typename U>
struct Pair
{   
    T key;
    U element;

    Pair(T j = T(), U e = U()):key(j), element(e){} 
    void setKey(T k){key = k;}
    void setElement(U e){element = e;}
    int get_key(){return key;}
    T get_element(){return element;}
};


template<typename T>
class MinPriorityQueue
{   
    public:
        vector<T> mpq;

        MinPriorityQueue(int sz = 0): mpq(sz){}
        T remove_min();
        bool is_empty(){ return mpq.size() == 0;}
        void insert(T k);

};


template<typename T>
void MinPriorityQueue<T>::insert(T k)
{
    if(is_empty()){ //front
        mpq.push_back(k);
    } else if (mpq.at(mpq.size() - 1) < k){ // back
        mpq.push_back(k);
    } else { // middle
        for(size_t i = 0; i < mpq.size()-1; i++){
            if(k < mpq.at(i)){
                mpq.insert(mpq.begin() + i, k);
                break;
            }
        }
    }

}

template<typename T>
T MinPriorityQueue<T>::remove_min()
{
    T min;
    int index = 0;
    if(is_empty()){
        throw EmptyDLList("Tree is empty!");
    } else {
        min = mpq.at(0);
        mpq.erase(mpq.begin());
    }

    return min;
}


#endif