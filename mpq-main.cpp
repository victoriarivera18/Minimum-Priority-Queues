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
    // LinkedList implentation
    LinkedList<CPU_Job> myllHeap1000; //works
    LinkedList<CPU_Job> myllHeap10000; //works
    LinkedList<CPU_Job> myllHeap100000; //works

    string file1000 = "SetSize1000.txt";
    string file10000 = "SetSize10000.txt";
    string file100000 = "SetSize100000.txt";

    ifstream ifs(file1000);

    int id, len, prior;
    string line;
    stringstream ss;

    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp3(id, len, prior);
        myllHeap1000.insert(temp3); // inserting job into heap
    }

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file10000);
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp4(id, len, prior);
        myllHeap10000.insert(temp4); // inserting job into heap
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
        myllHeap100000.insert(temp5); // inserting job into heap
    }

    ss.clear();
    ifs.clear();
    ifs.close();

    try{
        cout << "SetSize 1000:: " << endl;
        while(!myllHeap1000.is_empty()){
           cout << myllHeap1000.remove_min();
        }

        cout << "No more jobs to run"<< endl;
        cout << endl;
        cout << "SetSize 10000:: " << endl;
        while(!myllHeap10000.is_empty()){
            cout << myllHeap10000.remove_min();
        }
        cout << "No more jobs to run"<< endl;
    

        cout << endl;
        cout << "SetSize 100000:: " << endl;
        while(!myllHeap100000.is_empty()){
           cout << myllHeap100000.remove_min();
        }
        cout << "No more jobs to run"<< endl;

    } catch(EmptyTree){
        cout << "Tree is empty!" << endl;
    } 

    // the vector implementation
    /*MinPriorityQueue<CPU_Job> myHeap1000; //works
    MinPriorityQueue<CPU_Job> myHeap10000; //works
    MinPriorityQueue<CPU_Job> myHeap100000; //works

    string file1000 = "SetSize1000.txt";
    string file10000 = "SetSize10000.txt";
    string file100000 = "SetSize100000.txt";

    ifstream ifs(file1000);

    int id, len, prior;
    string line;
    stringstream ss;

    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp3(id, len, prior);
        myHeap1000.insert(temp3); // inserting job into heap
    }

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

    ss.clear();
    ifs.clear();
    ifs.close();

    try{
        cout << "SetSize 1000:: " << endl;
        while(!myHeap1000.is_empty()){
           cout << myHeap1000.remove_min();
        }

       cout << endl;
        cout << "SetSize 10000:: " << endl;
        while(!myHeap10000.is_empty()){
            cout << myHeap10000.remove_min();
        }
    
        cout << endl;
        cout << "SetSize 100000:: " << endl;
        while(!myHeap100000.is_empty()){
           cout << myHeap100000.remove_min();
        }

    } catch(EmptyTree){
        cout << "Tree is empty!" << endl;
    } */

    //Binary Heap implementation
    /*BinaryHeap<CPU_Job> myHeap1000; //works
    BinaryHeap<CPU_Job> myHeap10000; //works
    BinaryHeap<CPU_Job> myHeap100000; //works

    string file1000 = "SetSize1000.txt";
    string file10000 = "SetSize10000.txt";
    string file100000 = "SetSize100000.txt";

    ifstream ifs(file1000);

    int id, len, prior;
    string line;
    stringstream ss;
    
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp(id, len, prior);
        myHeap1000.insert(temp); // inserting job into heap
    }
    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file10000);

    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp1(id, len, prior);
        myHeap10000.insert(temp1); // inserting job into heap
    }

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file100000);
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp2(id, len, prior);
        myHeap100000.insert(temp2); // inserting job into heap
    }
    ss.clear();
    ifs.clear();
    ifs.close();

    try {        
        cout << endl;
        cout << "SetSize 1000:: " << endl;
        while(!myHeap1000.is_empty()){
           cout << myHeap1000.remove_min();
        }

        cout << endl;
        cout << "SetSize 10000:: " << endl;
        while(!myHeap10000.is_empty()){
            cout << myHeap10000.remove_min();
        }
    
        cout << endl;
        cout << "SetSize 100000:: " << endl;
        while(!myHeap100000.is_empty()){
           cout << myHeap100000.remove_min();
        }

    } catch(EmptyTree){
        cout << "Tree is empty!" << endl;
    }*/


    return 0;
}

