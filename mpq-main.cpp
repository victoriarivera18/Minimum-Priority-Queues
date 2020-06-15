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
    BinaryHeap<CPU_Job> myHeap4;
    BinaryHeap<CPU_Job> myHeap10;
    BinaryHeap<CPU_Job> myHeap100;
    BinaryHeap<CPU_Job> myHeap1000;
    BinaryHeap<CPU_Job> myHeap10000;
    BinaryHeap<CPU_Job> myHeap100000;

    string file4 = "SetSize4.txt";
    string file10 = "SetSize10.txt";
    string file100 = "SetSize100.txt";
    string file1000 = "SetSize10000.txt";
    string file10000 = "SetSize10000.txt";
    string file100000 = "SetSize10000.txt";

    ifstream ifs(file4);
    //ifstream ifs2(file10);
   // ifstream ifs3(file100);
    //ifstream ifs4(file1000);
    //ifstream ifs5(file10000);
    //ifstream ifs6(file100000);

    int id, len, prior;
    string line;
    stringstream ss;
    
    /*while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp(id, len, prior);
        myHeap4.insert(temp); // inserting job into heap
    }
    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file10);

    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp1(id, len, prior);
        myHeap10.insert(temp1); // inserting job into heap
    }

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file100);
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp2(id, len, prior);
        myHeap100.insert(temp2); // inserting job into heap
    }

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file1000);

    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp3(id, len, prior);
        myHeap1000.insert(temp3); // inserting job into heap
    }*/

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file10000);
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp4(id, len, prior);
        myHeap10000.insert(temp4); // inserting job into heap
    }

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file100000);
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp5(id, len, prior);
        myHeap100000.insert(temp5); // inserting job into heap
    }
    ifs.close();

    try {
        /*while(!myHeap4.is_empty()){
            cout << myHeap4.remove_min();
        }

        cout << endl;
        while(!myHeap10.is_empty()){
            cout << myHeap10.remove_min();
        }

        cout << endl;
        while(!myHeap100.is_empty()){
            cout << myHeap100.remove_min();
        }


        while(!myHeap1000.is_empty()){
            cout << myHeap1000.remove_min();
        }*/

        cout << myHeap10000.getSize()<< endl;;
  

    } catch(EmptyTree){
        cout << "Tree is empty!" << endl;
    }




    return 0;
}

