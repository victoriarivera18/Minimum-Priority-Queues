// V. Rivera Casanova
// CSCE 221
// Leyk 199

#ifndef LINKEDLISTIMP_H
#define LINKEDLISTIMP_H

# include <iostream>
# include <stdexcept>
# include <fstream>
# include <cmath>
using namespace std;

template<typename T>
struct Item {
    int key;
    T element;
    Item<T>* prev;
    Item<T>* next; 
    // constructor
    Item(int j = -10, T e = T(), Item<T>* n=nullptr, Item<T>* m=nullptr):key(j),element(e), prev(n), next(n){}
    void setKey(int k){key = k;}
    void setElement(T e){element = e;}
};

// one header and the end of the list is designated by nullptr
template<typename T>
class LinkedList {
    private:
        Item<T> head, tail;
    public:
        LinkedList():head(T()), tail(T()) { head.next = &tail; tail.prev = &head;}
        void insert(int k, T val);
        int remove_min();
        bool is_empty(){ return head.next == &tail;}
        Item<T>* first_node() const {return head.next;}
        const Item<T> *after_last_node() const { return &tail; }
};

template <typename T>
void LinkedList<T>::insert(int k, T val) // insert in mpq order
{
    //smallest key at the beginning
    if(is_empty()){
        Item<T>* first = new Item<T>(k, val, &head, &tail);
        head.next = first;
        tail.prev = first;
    }

}

template <typename T>
int LinkedList<T>::remove_min()
{

}
template <typename T>
ostream& operator<<(ostream& out, const LinkedList<T>& dll) //O(n)
{  
  Item<T>* traverse = dll.first_node();
  int nodeNum = 0;
  while (traverse != dll.after_last_node()){
    out << "Node: " << nodeNum << " -- " << traverse->key << endl;
    traverse = traverse->next;
    nodeNum++;
  }
  return out;
}

#endif