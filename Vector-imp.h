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

template<typename T, typename U>
class MinPriorityQueue
{   
    public:
        vector<Pair<T, U>> mpq;

        MinPriorityQueue(int sz = 0): mpq(sz){}
        T remove_min();
        bool is_empty(){ return mpq.size() == 0;}
        void insert(T k, U val);

};

template<typename T, typename U>
vector<Pair<T, U>> merge(vector<Pair<T, U>> left, vector<Pair<T, U>> right) 
{
    vector<Pair<T, U>> result;
    while (left.size() > 0 || right.size() > 0) {
      if (left.size() > 0 && right.size() > 0) {
         if (left.front().key <= right.front().key) {
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

template<typename T, typename U>
vector<Pair<T, U>> mergeSort(vector<Pair<T, U>> m) 
{
   if (m.size() <= 1){
      return m;
    }
    vector<Pair<T, U>> left, right, result;
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

template<typename T, typename U>
void MinPriorityQueue<T, U>::insert(T k, U val)
{
    Pair<T, U>* add = new Pair<T, U>(k, val);
    mpq.push_back((*add));
    mpq = mergeSort(this->mpq);
}

template<typename T, typename U>
T MinPriorityQueue<T, U>::remove_min()
{
    T min = mpq.at(0).key;
    int index = 0;
    while (mpq.at(index).key == min && mpq.size() != 0){
        mpq.erase(mpq.begin());
        index++;
    }

    return min;
}


#endif