// Fig. 9.8: Time.h
// Time class containing a constructor with default arguments.
// Member functions are defined in Time.cpp

// prevent multiple inclusions of header file
#ifndef TIME_H
#define TIME_H

// Time abstract data type definition
class Time
{
public:
    Time( int = 0, int = 0, int = 0 ); // default constructor

    // set functions
    void setTime( int, int, int ); // set hour, minute and second
    void setHour( int ); // set hour (after validation)
    void setMinute( int ); // set minute (after validation)
    void setSecond( int ); // set second (after validation)

    // get functions
    int getHour(); // return hour
    int getMinute(); // return minute
    int getSecond(); // return second

    void printUniversal(); // output time in universal-time format
    void printStandard(); // output time in standar-time format
private:
    int hour; // 0 - 23 (24-hour clock format)
    int minute; // 0 - 59
    int second; // 0 - 59
}; // end class Time

#endif





// Fig. 9.9: Time.cpp
// Member-function definitions for class Time.
#include <iostream>
#include <iomanip>
#include "Time.h" // include definition of class Time from Time.h--Still included here for ONEPAGE file because the above preprocessor wrapper allows us by preventing the header code from being included into the same source code file more than once;
using namespace std;

// Time constructor initializes each data member to zero;
// Ensures all Time objects start in a consistent state.
Time::Time( int hr, int min, int sec )
{
    setTime( hr, min, sec ); // validate and set time
} // end Time constructor

// set new Time value using universal time; ensure that
// the data remains consistent by setting invalid values to zero
void Time::setTime( int h, int m, int s )
{
    setHour( h ); // set private field hour
    setMinute( m ); // set private field minute
    setSecond( s ); // set private field second
} // end function setTime

// set hour value
void Time::setHour( int h )
{
    hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
} // end function setHour

// set minute value
void Time::setMinute( int m )
{
    minute = ( m >= 0 && m < 60 ) ? m : 0; // validate minute
} // end function setMinute

// set second value
void Time::setSecond( int s )
{
    second = ( s >= 0 && s < 60 ) ? s : 0; // validate second
} // end function setSecond

// return hour value
int Time::getHour()
{
    return hour;
} // end function getHour

// return minute value
int Time::getMinute()
{
    return minute;
} // end function getMinute

// return second value
int Time::getSecond()
{
    return second;
} // end function getSecond

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal()
{
    cout << setfill( '0' ) << setw( 2 ) << hour << ":"
        << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond();
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard()
{
    cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
        << ":" <<  setfill( '0' ) << setw( 2 ) << getMinute()
        << ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard






// Fig. 9.10: fig09_10.cpp
// Demonstrating a default constructor for class Time.
#include <iostream>
#include "Time.h" // include definition of class Time from Time.h--Still included here for ONEPAGE file because the above preprocessor wrapper allows us by preventing the header code from being included into the same source code file more than once;
using namespace std;

int main()
{
    Time t1; // all arguments defaulted
    Time t2( 2 ); // hour specified; minute and second defaulted
    Time t3( 21, 34 ); // hour and minute specified; second defaulted
    Time t4( 12, 25, 42 ); // hour, minute and second specified
    Time t5( 27, 74, 99 ); // all bad values specified

    cout << "Constructed with:\n\nt1: all arguments defaulted\n ";
    t1.printUniversal(); // 00:00:00
    cout << "\n ";
    t1.printStandard(); // 12:00:00 AM

    cout << "\n\nt2: hour specified; minute and second defaulted\n ";
    t2.printUniversal(); // 02:00:00
    cout << "\n ";
    t2.printStandard(); // 2:00:00 AM

    cout << "\n\nt3: hour and minute specified; second defaulted\n ";
    t3.printUniversal(); // 21:34:00
    cout << "\n ";
    t3.printStandard(); // 9:34:00 PM

    cout << "\n\nt4: hour, minute and second specified\n ";
    t4.printUniversal(); // 12:25:42
    cout << "\n ";
    t4.printStandard(); // 12:25:42 PM

    cout << "\n\nt5: all invalid values specified\n ";
    t5.printUniversal(); // 00:00:00
    cout << "\n ";
    t5.printStandard(); // 12:00:00AM
    cout << endl;
} // end main
