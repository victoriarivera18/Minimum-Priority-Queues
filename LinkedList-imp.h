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

//unsorted linked list implementation of a MPQ
template<typename T>
struct Item {
    T value; 
    Item<T> *prev, *next;
    // constructor
    Item(T e = T(), Item<T>* n=nullptr, Item<T>* m=nullptr):value(e), prev(n), next(m){}
};

// one header and the end of the list is designated by nullptr
template<typename T>
class LinkedList {
    private:
        Item<T> head, tail;
    public:
        LinkedList():head(T()), tail(T()) { head.next = &tail; tail.prev = &head;}
        void insert(T k);
        T remove_min();
        bool is_empty(){ return head.next == &tail;}
        Item<T>* first_node() const {return head.next;}
        const Item<T> *after_last_node() const { return &tail; }
        void insert_first(T obj);
        void insert_before(Item<T> &p, T obj);
};
struct EmptyDLList : public std::runtime_error {
  explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

template<typename T>
void LinkedList<T>::insert_first(T obj)
{ 
  Item<T> *toAdd = new Item<T>(obj, &head, head.next);
  head.next->prev = toAdd;
  head.next = toAdd;
}


template<typename T>
void LinkedList<T>::insert_before(Item<T> &p, T obj)
{
  //check if previous is "head"
  if(p.prev == &head) {
    insert_first(obj);
  } else {
		Item<T> *toAdd = new Item<T>(obj, p.prev, &p);
		p.prev->next = toAdd;
		p.prev = toAdd;
  }
}

template<typename T>
void LinkedList<T>::insert(T k) // insert to end of the list
{

    if(is_empty()){
        Item<T> *toAdd = new Item<T>(k, &head, &tail);
        head.next = toAdd;
        tail.prev = toAdd;
    } else if (after_last_node()->prev->value < k){
        Item<T> *toAdd = new Item<T>(k, tail.prev, &tail);
        tail.prev->next = toAdd;
        tail.prev = toAdd;
    } else {
        Item<T>* node = head.next;
        while(node != after_last_node()){
            if(k < node->value){
                insert_before((*node), k);
                break;
            }
            node = node->next;
        }

    }

}

template<typename T>
T LinkedList<T>::remove_min() // delete first node
{
  if (is_empty()){
    throw EmptyDLList("List is empty!");
  } else {
    Item<T>* temp = head.next;
    temp->next->prev = &head;
    head.next = temp->next;
    T obj = temp->value;
    delete temp;  //temp is old header
    return obj;
  }

}

#endif