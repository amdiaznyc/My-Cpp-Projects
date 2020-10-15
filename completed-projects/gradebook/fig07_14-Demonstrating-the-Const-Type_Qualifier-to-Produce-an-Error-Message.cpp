// Fig. 7.14: fig07_14.cpp
// Demonstrating the const type qualifier to produce an error message.
#include <iostream>
using namespace std;

void tryToModifyArray( const int [] ); // function prototype

int main()
{
    int a[] = { 10, 20, 30 };

    tryToModifyArray( a );
    cout << a[ 0 ] << ' ' << a[ 1 ] << ' ' << a[ 2 ] << '\n';
} // end main

// In function tryToModifyArray, "b" cannot be used
// to modify the original array "a" in main.
void tryToModifyArray( const int b[] )
{
    b[ 0 ] /= 2; // compilation error
    b[ 1 ] /= 2; // compilation error
    b[ 2 ] /= 2; // compilation error
} // end function tryToModifyArray
