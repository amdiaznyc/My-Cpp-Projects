// Fig. 10.8: Increment.cpp
// Erroneous attempt to initialize a constant of a built-in data
// type by assigment.
#include <iostream>
#include "Increment.h" // include definition of class Increment
using namespace std;

// constructor; constant member 'increment' is not initialized
Increment::Increment( int c, int i )
{
    count = c; // allowed because count is not constant
    increment = i; // ERROR: Cannot modify a const object
}   // end constructor Increment

// print count and increment values
void Increment::print() const
{
    cout << "count = " << count << ", increment = " << increment << endl;
} // end function print
