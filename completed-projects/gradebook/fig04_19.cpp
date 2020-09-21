// Fig. 4.19: fig04_19.cpp
// Preincrementing and postincrementing
#include <iostream>
using namespace std;

int main()
{
    int c;

    // demonstrate postincrement
    c = 5; // assign 5 to c
    cout << c << endl; // print 5
    cout << c++ << endl; // print 5 then postincrement
    cout << c << endl; // print 6

    cout << endl; // skip a line

    // demonstrate preincrement
    c = 5; // assign 5 to c
    cout << c << endl; // print 5
    cout << ++c << endl; // preincrement then print 6
    cout << c << endl; // print 6
} // end main
