/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *Ian Bonifas
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include "Sequence.h"
#include <iostream>

using namespace std;

int main() {
    //cout that the project runs
    cout << "Your project is ready to go!" << endl;
    //creates mySequence Sequence
    Sequence mySequence(6);
    //addes cat to the end
    //      mySequence.push_back("cat");
    //gets string cat
    //    string i= mySequence.back();
    //print string cat
    // cout << i << endl;
    //inserts string dog at postion four
    // mySequence.insert(4,"dog");
    //gets string at front
    //   //  string k= mySequence.front();
    //prints the front string
    //    // cout << k << endl;
    //changes position 3 to string rat
    //     mySequence[3]="rat";
    //changes positon 4 to hello
    //  mySequence[4]="hello";
    //clears the Sequence mySequence
    //    //mySequence.clear();
    //erases last position
    // mySequence.pop_back();
    //erases position 4 and 5
    mySequence.erase(4, 1);
    return 0;
}
