// Fig. 3.12: GradeBook.cpp
// GradeBook member-function definitions. This file contains
// implementations of the member functions prototyped in GradeBook.h.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name )
{
    setCourseName( name ); // call set function to initialize courseName
} // end GradeBook constructor

// function to set the course name
void GradeBook::setCourseName ( string name )
{
    courseName = name; // store the course name in the object
} // end function setCourseName

// function to get the course name
string GradeBook::getCourseName()
{
    return courseName; // return object's courseName
} // end function getCourseName

// (function that) display(s) a welcome message to the GradeBook user
void GradeBook::displayMessage()
{
    // (this statement) call(s) getCourseName to get the courseName
    cout << "Welcome to the grade book for\n" << getCourseName() 
        << "!" << endl;
} //end function displayMessage
