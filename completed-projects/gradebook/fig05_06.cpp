// Fig. 5.6: fig05_06.cpp
// Compound interest calculations with 'for'.
/* Application: Compound Interest Calculations
    Consider the following problem statement:
    "A person invest $1000.00 in a savings account yielding 5 percent
    interest. Assuming that all interest is left on deposit in the account,
    calculate and print the amount of money in the account at the end
    of each year for 10 years. Use the following formula for
    determining these amounts:
        a= p( 1 + r)n
    where
        p is the original amount invested (i.e., the principal),
        r is the annual interest rate,
        n is the number of years and
        a is the amount on deposit at the end of the nth year.
    
    Note--This problem involves a loop that performs the indicated
    calculation for each of the 10 years the money remains on deposit.
    The solution is shown below.
*/



#include <iostream>
#include <iomanip>
#include <cmath> // standard C++ math library
using namespace std;

int main()
{
    double amount; // amount of deposit at the end of each year
    double principal = 1000.0; // initial amount before interest
    double rate = .05; // interest rate

    // display headers
    cout << "Year" << setw( 21 ) << "Amount on deposit" << endl;

    // set floating-point number format
    cout << fixed << setprecision( 2 );

    // calculate amount on deposit for each of ten years
    for ( int year = 1; year <= 10; year++ )
    {
        // calculate new amount for specified year
        amount = principal * pow( 1.0 + rate, year );

        // display the year and the amount
        cout << setw( 4 ) << year << setw( 21 ) << amount << endl;
    } // end for
} // end main
