// Fig. 5.1: fig05_01.cpp
// Counter-controlled repetition with the 'while' statement
#include <iostream>
using namespace std;

int main()
{
    int counter = 1; // declare and initialize control variable

    while ( counter <= 10 ) // loop-continuation condition
    {
        cout << counter << " "; // a statement
        counter++; // increment control variable by 1
    } // end while

    cout << endl; // output a newline
} // end main
