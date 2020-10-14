// Fig. 7.4: fig07_04.cpp
// Initializing an array in a declaration.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // use initializer list to initialize array n
    int n[ 10 ] = { 32, 27, 64, 18, 95, 14, 90, 70, 60, 37 };

    cout << "Element" << setw( 13 ) << "Value" << endl;

    // output each array element's value
    for ( int i = 0; i < 10; i++ )
        cout << setw( 7 ) << i << setw( 13 ) << n[ i ] << endl;
} // end main
