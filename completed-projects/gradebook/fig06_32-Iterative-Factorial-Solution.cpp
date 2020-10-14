// Fig. 6.32: fig06_32.cpp
// Testing the iterative factorial function.
#include <iostream>
#include <iomanip>
using namespace std;

unsigned long factorial( unsigned long ); // function prototype

int main()
{
    // calculate the factorials of 0 through 10
    for ( int counter = 0; counter <= 10; counter ++ )
        cout << setw( 2 ) << counter << "! = " << factorial( counter )
            << endl;
} // end main

// iterative function factorial
unsigned long factorial( unsigned long number )
{
    unsigned long result = 1;

    // iterative factorial calculation
    for ( unsigned long i = number; i >= 1; i-- )
        result *= i;

    return result;
} // end function factorial
