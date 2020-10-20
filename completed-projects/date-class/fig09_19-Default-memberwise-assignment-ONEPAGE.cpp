// Fig. 9.17: Date.h
// Date class declaration. Member functions are defined in Date.cpp.

// prevent multiple inclusions of header file
#ifndef DATE_H
#define DATE_H

// class Date definition
class Date
{
public:
    Date( int = 1, int = 1, int = 2000 ); // default constructor
    void print();
private:
    int month;
    int day;
    int year;
}; // end class Date

#endif




// Fig. 9.18: Date.cpp
// Date class member-function definitions.
#include <iostream>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;

// Date constructor (should do range checking)
Date::Date( int m, int d, int y )
{
    month = m;
    day = d;
    year = y;
} // end constructor Date

// print Date in the format mm/dd/yyyy
void Date::print()
{
    cout << month << '/' << day << '/' << year;
} // end function print





// Fig. 9.19: fig09_19.cpp
// Demonstrating that class objects can be assigned
// to each other using default memberwise assignment.
#include <iostream>
#include "Date.h" // include definition of class Date from Date.h
using namespace std;

int main()
{
    Date date1( 7, 4, 2004 );
    Date date2; // date2 defaults to 1/1/2000

    cout << "date1 = ";
    date1.print();
    cout << "\ndate2 = ";
    date2.print();

    date2 = date1; // default memberwise assignment

    cout << "\n\nAfter default memberwise assignment, date2 = ";
    date2.print();
    cout << endl;
} // end main
