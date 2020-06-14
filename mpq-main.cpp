// V. Rivera Casanova
// CSCE 221
// Leyk 199
// w/ git version comntrol

# include "LinkedList-imp.h"
# include "Vector-imp.h"
# include "BinaryHeap.h"

# include <iostream>
# include <stdexcept>
# include <sstream>
# include <fstream>
# include <string>
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
    /* BinaryHeap<int> intHeap;
    BinaryHeap<CPU_Job> myHeap;

    intHeap.insert(1);
    intHeap.insert(4);
    intHeap.insert(7);
    intHeap.insert(-2);
    intHeap.insert(5);
    intHeap.insert(3);

    try {
        cout << intHeap.remove_min() << endl;
        cout << intHeap.remove_min() << endl;
        cout << intHeap.remove_min() << endl;
        cout << intHeap.remove_min() << endl;
        cout << intHeap.remove_min() << endl;
        cout << intHeap.remove_min() << endl;
        // cout << intHeap.remove_min() << endl; invokes runtime_error()

    } catch(EmptyTree){
        cout << "Tree is empty!" << endl;
    } */

    //need to create struct
    //insert into binary heap of CPU_Jobs

    //reading from file also
    BinaryHeap<CPU_Job> myHeap;
    string file4 = "Data file/SetSize4.txt";
    string file10 = "SetSize10.txt";
    string file100 = "SetSize100.txt";
    string file1000 = "SetSize10000.txt";
    string file10000 = "SetSize10000.txt";
    string file100000 = "SetSize10000.txt";

    ifstream ifs("SetSize10.txt");
    //ifstream ifs2(file10);
    //ifstream ifs3(file100);
    //ifstream ifs4(file1000);
    //ifstream ifs5(file10000);
    //ifstream ifs6(file100000);

    int id, len, prior;
    string line;
    stringstream ss;
    
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp(id, len, prior);
        myHeap.insert(temp); // inserting job into heap
    }



    try {

        CPU_Job min = myHeap.remove_min();
        cout << endl << min.prior << endl;
        CPU_Job min2 = myHeap.remove_min();
        cout << endl << min2.prior << endl;
        CPU_Job min3 = myHeap.remove_min();
        cout << endl << min3.prior << endl;
        CPU_Job min4 = myHeap.remove_min();
        cout << endl << min4.prior << endl;
        CPU_Job min5 = myHeap.remove_min();
        cout << endl << min5.prior << endl;
        CPU_Job min6 = myHeap.remove_min();
        cout << endl << min6.prior << endl;
    } catch(EmptyTree){
        cout << "Tree is empty!" << endl;
    }




    return 0;
}

