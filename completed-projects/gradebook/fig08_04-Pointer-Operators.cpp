// Fig. 8.4: fig08_04.cpp
// Pointer operators & and *.
#include <iostream>
using namespace std;

int main()
{
    int a; // a is an integer
    int *aPtr; // aPtr is an int * which is a pointer to an integer

    a = 7; // assigned 7 to a
    aPtr = &a; // assign the address of a to aPtr

    cout << "The address of a is " << &a
        << "\nThe value of aPtr is " << aPtr;
    cout << "\n\nThe value of a is " << a
        << "\nThe value of *aPtr is " << *aPtr;
    cout << "\n\nShowing that * and & are inverses of "
        << "each other.\n&*aPtr = " << &*aPtr
        << "\n*&aPtr = " << *&aPtr << endl;
} // end main
