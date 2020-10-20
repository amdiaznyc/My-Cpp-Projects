// Fig. 9.14: Time.h
// Time class declaration.
// Member functions are defined in Time.cpp

// prevent multiple inclusions of header file
#ifndef TIME_H
#define TIME_H

class Time
{
public:
    Time( int = 0, int = 0, int = 0 ); // default constructor
    void setTime( int, int, int ); // // set functions to set hour, minute and second
    int getHour();
    int &badSetHour( int ); // DANGEROUS reference return
private:
    int hour;
    int minute;
    int second;
}; // end class Time

#endif
