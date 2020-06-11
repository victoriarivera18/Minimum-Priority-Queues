// V. Rivera Casanova
// CSCE 221
// Leyk 199
// w/ git version comntrol

# include "LinkedList-imp.h"
# include "Vector-imp.h"

# include <iostream>
# include <stdexcept>
# include <cmath>
# include <vector>
using namespace std;


// definition of (key, value) pair that makes up the mpq

int main()
{   
    MinPriorityQueue<int, int> my_queue;

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
    }

    return 0;
}

