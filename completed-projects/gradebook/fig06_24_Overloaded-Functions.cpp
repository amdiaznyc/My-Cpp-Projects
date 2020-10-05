// Fig. 6.24: fig06_24.cpp
// Overloaded functions.
#include <iostream>
using namespace std;

// function square for int values
int square ( int x )
{
    cout << "square of integer " << x << " is ";
    return x * x;
} // end function square with int argument

// function square for double values
double square( double y )
{
    cout << "square of double " << y << " is ";
    return y * y;
} // end function square with double argument

int main()
{
    cout << square( 7 ); // calls int version
    cout << endl;
    cout << square( 7.5 ); // call double version
    cout << endl;
} // end main
