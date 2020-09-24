// Fig. 5.5: fig05_05.cpp
// Summing integers with the 'for' statement.
#include <iostream>
using namespace std;

int main()
{
    int total = 0; // initialize total

    // total even integers from 2 through 20
    for ( int number = 2; number <= 20; number += 2 )
        total = total + number;

    cout << "Sum is " << total << endl; // displays results
} // end main
