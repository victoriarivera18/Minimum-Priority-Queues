// V. Rivera Casanova
// CSCE 221
// Leyk 199
// w/ git version comntrol

# include "LinkedList-imp.h"
# include "Vector-imp.h"
# include "BinaryHeap.h"

# include <iostream>
# include <ctime>
# include <stdexcept>
# include <sstream>
# include <fstream>
# include <string>
# include <vector>
using namespace std;

// need 9 timings all together
// Vector: 1000, 10000, 100000
// Linked List: 1000, 10000, 100000
// Binary Heap: 1000, 10000, 100000
/*
Linked List:
1. 140.625 milisecs
2. 1546.88 milisec
3. 133047 milisec

vector:
4. 78.125 milisec
5. 2656.25 milisec
6. 203766 milisec

Binary Heap:
7. 62.5 milisec
8. 796.875 milisec
9. 6421.88 milisec

Linked List:
Timing: 62.5 milisec
Timing: 406.25 milisec
Timing: 43796.9 milisec

vector:
Timing: 15.625 milisec
Timing: 953.125 milisec
Timing: 62812.5 milisec

Binary Heap:
Timing: 0 milisec
Timing: 187.5 milisec
Timing: 2828.12 milisec



Linked List:
Timing: 15.625 milisec
Timing: 468.75 milisec
Timing: 34250 milisec

vector:
Timing: 62.5 milisec
Timing: 843.75 milisec
Timing: 60093.8 milisec

Binary Heap:
Timing: 31.25 milisec
Timing: 234.375 milisec
Timing: 2625 milisec


Linked List:
Timing: 31.25 milisec
Timing: 390.625 milisec
Timing: 35625 milisec

vector:
Timing: 46.875 milisec
Timing: 781.25 milisec
Timing: 59531.2 milisec

Binary Heap:
Timing: 15.625 milisec
Timing: 218.75 milisec
Timing: 2453.12 milisec


Linked List:
Timing: 46.875 milisec
Timing: 453.125 milisec
Timing: 34687.5 milisec

vector:
Timing: 31.25 milisec
Timing: 828.125 milisec
Timing: 64140.6 milisec

Binary Heap:
Timing: 15.625 milisec
Timing: 281.25 milisec
Timing: 3171.88 milisec
*/


int main()
{
    clock_t t1, t2, t3, t4, t5, t6; 
    clock_t t21, t22, t23, t24, t25, t26;
    clock_t t31, t32, t33, t34, t35, t36;
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

    // 1.
    t1 = clock(); //start
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp3(id, len, prior);
        myllHeap1000.insert(temp3); // inserting job into heap
    }

    cout << "SetSize 1000:: " << endl;
    while(!myllHeap1000.is_empty()){
        cout << myllHeap1000.remove_min();
    }
    cout << "No more jobs to run"<< endl;
    t2 = clock(); // stop

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file10000);

    // 2.
    t3 = clock(); //start
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp4(id, len, prior);
        myllHeap10000.insert(temp4); // inserting job into heap
    }

    cout << endl;
    cout << "SetSize 10000:: " << endl;
    while(!myllHeap10000.is_empty()){
        cout << myllHeap10000.remove_min();
    }
    cout << "No more jobs to run"<< endl;
    t4 = clock(); //stop
    

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file100000);

    //3. 
    t5 = clock(); //start
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp5(id, len, prior);
        myllHeap100000.insert(temp5); // inserting job into heap
    }
    cout << endl;
    cout << "SetSize 100000:: " << endl;
    while(!myllHeap100000.is_empty()){
        cout << myllHeap100000.remove_min();
    }
    cout << "No more jobs to run"<< endl;
    t6 = clock(); //stop

    ss.clear();
    ifs.clear();
    ifs.close();

    // the vector implementation
    MinPriorityQueue<CPU_Job> myVHeap1000; //works
    MinPriorityQueue<CPU_Job> myVHeap10000; //works
    MinPriorityQueue<CPU_Job> myVHeap100000; //works


    ifs.open(file1000);


    // 4. 
    t21 = clock(); //start
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp3(id, len, prior);
        myVHeap1000.insert(temp3); // inserting job into heap
    }

    cout << "SetSize 1000:: " << endl;
    while(!myVHeap1000.is_empty()){
        cout << myVHeap1000.remove_min();
    }
    cout << "No more jobs to run"<< endl;
    cout << endl;
    t22 = clock(); //stop

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file10000);

    // 5. 
    t23 = clock(); //start
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp4(id, len, prior);
        myVHeap10000.insert(temp4); // inserting job into heap
    }

    cout << "SetSize 10000:: " << endl;
    while(!myVHeap10000.is_empty()){
        cout << myVHeap10000.remove_min();
    }
    cout << "No more jobs to run"<< endl;
    cout << endl;
    t24 = clock(); //stop

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file100000);

    //6.
    t25 = clock(); //start
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp5(id, len, prior);
        myVHeap100000.insert(temp5); // inserting job into heap
    }
    cout << endl;
    cout << "SetSize 100000:: " << endl;
    while(!myVHeap100000.is_empty()){
        cout << myVHeap100000.remove_min();
    }
    cout << "No more jobs to run"<< endl;
    t26 = clock(); //stop

    ss.clear();
    ifs.clear();
    ifs.close();


    //Binary Heap implementation
    BinaryHeap<CPU_Job> myHeap1000; //works
    BinaryHeap<CPU_Job> myHeap10000; //works
    BinaryHeap<CPU_Job> myHeap100000; //works

    ifs.open(file1000);

    
    // 7.
    t31 = clock(); //start
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp(id, len, prior);
        myHeap1000.insert(temp); // inserting job into heap
    }

    cout << "SetSize 1000:: " << endl;
    while(!myHeap1000.is_empty()){
        cout << myHeap1000.remove_min();
    }
    cout << "No more jobs to run"<< endl;
    t32 = clock(); //stop
    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file10000);


    // 8.
    t33 = clock(); //start
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp1(id, len, prior);
        myHeap10000.insert(temp1); // inserting job into heap
    }
    cout << endl;
    cout << "SetSize 10000:: " << endl;
    while(!myHeap10000.is_empty()){
        cout << myHeap10000.remove_min();
    }
    cout << "No more jobs to run"<< endl;
    t34 = clock(); //stop

    ss.clear();
    ifs.close();
    ifs.clear();
    ifs.open(file100000);

    // 9.
    t35 = clock(); //start
    while(!ifs.eof()){ // only going into loop 1 time when doing 10
        getline(ifs, line);
        ss << line;
        ss >> id >> len >> prior;
        CPU_Job temp2(id, len, prior);
        myHeap100000.insert(temp2); // inserting job into heap
    }

    cout << endl;
    cout << "SetSize 100000:: " << endl;
    while(!myHeap100000.is_empty()){
        cout << myHeap100000.remove_min();
    }
    cout << "No more jobs to run"<< endl;
    t36 = clock(); //stop
    ss.clear();
    ifs.clear();
    ifs.close();

    double diff1 = (double)(t2 - t1)*1000/CLOCKS_PER_SEC; 
    cout << "Timing: " << diff1 << " milisec" << endl; 

    double diff2 = (double)(t4 - t3)*1000/CLOCKS_PER_SEC; 
    cout << "Timing: " << diff2 << " milisec" << endl; 

    double diff3 = (double)(t6 - t5)*1000/CLOCKS_PER_SEC; 
    cout << "Timing: " << diff3 << " milisec" << endl;

    double diff4 = (double)(t22 - t21)*1000/CLOCKS_PER_SEC; 
    cout << "Timing: " << diff4 << " milisec" << endl; 

    double diff5 = (double)(t24 - t23)*1000/CLOCKS_PER_SEC; 
    cout << "Timing: " << diff5 << " milisec" << endl; 

    double diff6 = (double)(t26 - t25)*1000/CLOCKS_PER_SEC; 
    cout << "Timing: " << diff6 << " milisec" << endl; 

    double diff7 = (double)(t32 - t31)*1000/CLOCKS_PER_SEC; 
    cout << "Timing: " << diff7 << " milisec" << endl; 

    double diff8 = (double)(t34 - t33)*1000/CLOCKS_PER_SEC; 
    cout << "Timing: " << diff8 << " milisec" << endl; 

    double diff9 = (double)(t36 - t35)*1000/CLOCKS_PER_SEC; 
    cout << "Timing: " << diff9 << " milisec" << endl;
       



    return 0;
}

