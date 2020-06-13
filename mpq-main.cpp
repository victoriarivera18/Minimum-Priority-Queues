// V. Rivera Casanova
// CSCE 221
// Leyk 199
// w/ git version comntrol

# include "LinkedList-imp.h"
# include "Vector-imp.h"
# include "BinaryHeap.h"

# include <iostream>
# include <stdexcept>
# include <cmath>
# include <vector>
using namespace std;


// definition of (key, value) pair that makes up the mpq

int main()
{   
    /*MinPriorityQueue<int, int> my_queue;

    LinkedList<int, int> my_list;
    if (my_list.is_empty()){
        cout << "Adding new items into list" << endl;
        my_list.insert(2, 4);
        my_list.insert(-1, 4);
        my_list.insert(8, 3);
        my_list.insert(-5, 4);
        my_list.insert(3, 4);
        cout << my_list.remove_min() << endl;
    } else {
        cout << "List not empty"<< endl;
    }

    if (my_list.is_empty()){
        cout << "Adding new items into list" << endl;
        my_list.insert(2, 4);
        my_list.insert(-1, 4);
        my_list.insert(5, 4);
        my_list.insert(3, 4);
    } else {
        cout << "List not empty"<< endl;
    }


    if (my_queue.is_empty()){
        cout << "Adding new pairs into vector" << endl;
        my_queue.insert(2, 4);
        my_queue.insert(-1, 4);
        my_queue.insert(5, 4);
        my_queue.insert(3, 4);
        cout << "Size: " <<  my_queue.mpq.size() << endl;
    } else {
        cout << "List not empty"<< endl;
    }

    cout << "Minimum: " << my_queue.remove_min() << endl;

    if (my_queue.is_empty()){
        cout << "Adding new pairs into vector" << endl;
        my_queue.insert(2, 4);
        my_queue.insert(-1, 4);
        my_queue.insert(5, 4);
        my_queue.insert(3, 4);
        cout << "Size: " <<  my_queue.mpq.size() << endl;
    } else {
        cout << "List not empty"<< endl;
    } */
    BinaryHeap<int> intHeap;
    BinaryHeap<CPU_Job> myHeap;

    intHeap.insert(1);
    intHeap.insert(4);
    intHeap.insert(7);
    intHeap.insert(-2);
    intHeap.insert(5);
    cout << endl;
    cout << endl;
    intHeap.insert(3);
    cout << endl;
    cout << endl;
    try {
        cout << intHeap.remove_min() << endl;
        cout << intHeap.remove_min() << endl;
        cout << intHeap.remove_min() << endl;
        cout << intHeap.remove_min() << endl;
        cout << intHeap.remove_min() << endl;
        cout << intHeap.remove_min() << endl;

    } catch(EmptyTree){
        cout << "Tree is empty!" << endl;
    }



    return 0;
}

