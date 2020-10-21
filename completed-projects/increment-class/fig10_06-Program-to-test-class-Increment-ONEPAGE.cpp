// Fig. 10.4: Increment.h
// Definition of class Increment.
#ifndef INCREMENT_H
#define INCREMENT_H

class Increment
{
public:
    Increment( int c = 0, int i = 1 ); // default constructor

    // function addIncrement definition
    void addIncrement()
    {
        count += increment;
    } // end function addIncrement

    void print() const; // prints count and increment
private:
    int count;
    const int increment; // const data member
}; // end class Increment

#endif




// Fig. 10.5: Increment.cpp
// Member-function definitions for class Increment demonstrate using a
// member initializer to initialize a constant of a built-in data type.
#include <iostream>
#include "Increment.h" // include definition of class Increment
using namespace std;

// constructor
Increment::Increment( int c, int i )
    : count( c ), // initializer for non-const member
      increment( i ) // required initializer for const member
{
    // empty body
}   // end constructor Increment

// print count and increment values
void Increment::print() const
{
    cout << "count = " << count << ", increment = " << increment << endl;
} // end function print





// Fig. 10.6: fig10_06.cpp
// Program to test class Increment.
#include <iostream>
#include "Increment.h" // include definition of class Increment
using namespace std;

int main()
{
    Increment value( 10, 5 );

    cout << "Before incrementing: ";
    value.print();

    for ( int j = 1; j <= 3; j++ )
    {
        value.addIncrement();
        cout << "After increment " << j << ": ";
        value.print();
    } // end 'for' statement
} // end main
