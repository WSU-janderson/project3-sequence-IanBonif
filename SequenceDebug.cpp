/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include "Sequence.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Your project is ready to go!" << endl;

     Sequence mySequence(5);
     mySequence.push_back("cat");
   string i= mySequence.back();
cout << i << endl;
    mySequence.insert(4,"dog");
    string k= mySequence.front();
    cout << k << endl;
    mySequence[3]="rat";

    return 0;
}
