// Fig. 4.14: fig04_14.cpp
// Create GradeBook object and invoke it determineClassAverage function.
#include "GradeBook.h" // include definition of class GradeBook

int main()
{
    // create GradeBook object myGradeBook and
    // pass course name to constructor
    GradeBook myGradeBook( "CS101 C++ Programming" );

    myGradeBook.displayMessage(); // display welcome message
    myGradeBook.determineClassAverage(); // find average of 10 grades
} // end main 
