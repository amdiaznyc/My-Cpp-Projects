// Fig. 8.10: fig08_10.cpp
// Attempting to modify data through a
// nonconstant pointer to constant data. Results in an error message.

void f( const int * ); // prototype

int main()
{
    int y;

    f( &y ); // f attempts illegal modification
} // end main

// xPrt cannot modify the value of constant variable to which it points
void f( const int *xPtr )
{
    *xPtr = 100; // error: cannot modify a const object
} // end function f
