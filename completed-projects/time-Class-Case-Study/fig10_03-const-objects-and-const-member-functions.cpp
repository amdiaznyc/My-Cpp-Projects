// Fig. 10.3: fig10_03.cpp
// Attempting to access a const object with non-const member functions; results in error messages.
#include "Time.h" // include Time class definition

int main()
{
    Time wakeUp( 6, 45, 0 ); // non-constant object
    const Time noon( 12, 0, 0 ); // constant object

                           // OBJECT    MEMBER FUNCTION
    wakeUp.setHour( 18 );  // non-const non-const

    noon.setHour( 12 );    // const     non-const

    wakeUp.getHour();      // non-const const

    noon.getMinute();      // const     const
    noon.printUniversal(); // const     non-const

    noon.printStandard();  // const     non-const
} // end main
