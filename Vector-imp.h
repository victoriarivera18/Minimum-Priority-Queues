// V. Rivera Casanova
// CSCE 221
// Leyk 199

#ifndef VECTORIMP_H
#define VECTORIMP_H

# include <iostream>
# include <stdexcept>
# include <fstream>
# include <vector>
using namespace std;


template<typename T>
struct ItemV
{   
    int key;
    T element;

    ItemV(int j = 0, T e = T()):key(j), element(e){} 
    void setKey(int k){key = k;}
    void setElement(T e){element = e;}
    int get_key(){return key;}
    T get_element(){return element;
};

template<typename T>
class MinPriorityQueue
{   
    private:
        int mpq_size;
        vector<ItemV<T>> mpq;
    public:

        MinPriorityQueue(int sz = 0): mpq_size(sz), mpq(sz, 0){}
        int remove_min();
        bool is_empty(){ return mpq.size() == 0;}
        void insert_item(int k, T val);
        int get_size(){return mpq.size();}
        int get_key(int index){return  mpq.at(index).get_key();}
        T get_element(int index){return mpq.at(index).get_element();}


};

template<typename T>
void MinPriorityQueue<T>::insert_item(int k, T val)
{
    ItemV<T> add(k, val);
    typename vector<ItemV<T>>::iterator it;
    it = mpq.begin();

    if(is_empty()){
        mpq.push_back(add); 
    }else if(k > (mpq.at(mpq.size()-1)).key){
        mpq.push_back(add); // if at end
    } else {
        for(it = mpq.begin(); it < mpq.end() - 1; it++){
            if(get_key(it) < k && get_key(it+1) > k){
                mpq.insert(it, add);
            }
        }
    }
}


#endif