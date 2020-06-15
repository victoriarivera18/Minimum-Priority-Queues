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
    //need to create struct
    //insert into binary heap of CPU_Jobs

    //reading from file also
    BinaryHeap<CPU_Job> myHeap4; // works
    BinaryHeap<CPU_Job> myHeap10; // works
    BinaryHeap<CPU_Job> myHeap100; // works
    BinaryHeap<CPU_Job> myHeap1000; //works
    BinaryHeap<CPU_Job> myHeap10000;
    BinaryHeap<CPU_Job> myHeap100000;

    string file4 = "SetSize4.txt";
    string file10 = "SetSize10.txt";
    string file100 = "SetSize100.txt";
    string file1000 = "SetSize1000.txt";
    string file10000 = "SetSize10000.txt";
    string file100000 = "SetSize100000.txt";

    ifstream ifs(file4);
    //ifstream ifs2(file10);
   // ifstream ifs3(file100);
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

*/
        while(!myHeap100000.is_empty()){
            cout << myHeap100000.remove_min();
        }

        //cout << myHeap10000.getSize()<< endl;;
  

    } catch(EmptyTree){
        cout << "Tree is empty!" << endl;
    }




    return 0;
}

