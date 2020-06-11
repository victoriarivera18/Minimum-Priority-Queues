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
template<typename T, typename U>
struct Item {
    T key;
    U element;
    Item<T, U>* prev;
    Item<T, U>* next; 
    // constructor
    Item(T e = T(), U j = U(), Item<T, U>* n=nullptr, Item<T, U>* m=nullptr):key(e),element(j), prev(n), next(m){}
    void setKey(T k){key = k;}
    void setElement(U e){element = e;}
};

// one header and the end of the list is designated by nullptr
template<typename T, typename U>
class LinkedList {
    private:
        Item<T, U> head, tail;
    public:
        LinkedList():head(T()), tail(T()) { head.next = &tail; tail.prev = &head;}
        void insert(T k, U val);
        T remove_min();
        bool is_empty(){ return head.next == &tail;}
        Item<T, U>* first_node() const {return head.next;}
        const Item<T, U> *after_last_node() const { return &tail; }
};
struct EmptyDLList : public std::runtime_error {
  explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

template<typename T, typename U>
void LinkedList<T, U>::insert(T k, U val) // insert to end of the list
{
    Item<T, U>* add = new Item<T,U>(k , val, tail.prev, &tail);
    tail.prev->next = add;
    tail.prev = add;
}

template<typename T, typename U>
T LinkedList<T, U>::remove_min()
{
    if (is_empty()) {
        throw EmptyDLList("List is empty!");
    }

    Item<T, U>* node = first_node();
    T min = node->key;
    while(node->next != after_last_node()){
        if(node->key < min){
            min = node->key;
        }
        node = node->next;
    }

    //now we have the min value
    node = first_node();
    Item<T, U>* node2 = first_node();
    while(node->next != after_last_node()){
        if(node->key == min){
            node2 = node->prev->next;
           	node->next->prev = node->prev;
	        node->prev->next = node->next;
            delete node;
            node = node2;
        } else {
            node2 = node;
            node = node->next;
        }

    }
    return min;


}

#endif