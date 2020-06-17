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
vector<T> merge(vector<T> left, vector<T> right) 
{
    vector<T> result;
    while (left.size() > 0 || right.size() > 0) {
      if (left.size() > 0 && right.size() > 0) {
         if (left.front() < right.front()) { // overload operator
            result.push_back((left.front()));
            left.erase(left.begin());
         } else {
            result.push_back(right.front());
            right.erase(right.begin());
         }
      }else if((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
                result.push_back(left[i]);
            break;
      }else if((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result; 
}

template<typename T>
vector<T> mergeSort(vector<T> m) 
{
   if (m.size() <= 1){
      return m;
    }
    vector<T> left, right, result;
    int middle = ((int)m.size()+ 1) / 2;
 
    for (int i = 0; i < middle; i++) {
        left.push_back(m[i]);
    }

    for (int i = middle; i < (int)m.size(); i++) {
        right.push_back(m[i]);
    }
 
    left = mergeSort(left);
    right = mergeSort(right);
    result = merge(left, right);
 
    return result;
}

template<typename T>
void MinPriorityQueue<T>::insert(T k)
{
    mpq.push_back(k);
    mpq = mergeSort(this->mpq);
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