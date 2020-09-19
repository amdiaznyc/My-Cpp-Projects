// Fig. 4.9: GradeBook.cpp
//  Member-function definitions for class GradeBook that solves the
// class average program with counter-controlled repetition.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name )
{
    setCourseName( name ); // validate and store courseName
} // end GradeBook constructor

// function to set the course name;
// ensures that the course name has at most 25 characters
void GradeBook::setCourseName ( string name )
{
    if ( name.length() <= 25 ) // if name has 25 of fewer characters
        courseName = name; // store the course name in the object
    else // if name if longer than 25 characters
    { // set courseName to first 25 characters of parameter name
        courseName = name.substr( 0, 25 ); // select first 25 character
        cout << "Name \"" << name << "\" exceeds maximum length (25).\n"
            << "Limiting courseName to first 25 character.\n" << endl;
    } // end if...else
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName()
{
    return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage()
{
    cout << "Welcome to the grade book for\n" << getCourseName() << "!\n"
        << endl;
} // end function displayMessage

// determine class average based on 10 grades entered by user
void GradeBook::determineClassAverage()
{
    int total; // sum of grades entered by user
    int gradeCounter; // number of the grade to be entered next
    int grade; // grade value entered by user
    int average; // average of grades

    // initialization phase
    total = 0; // initialize total
    gradeCounter = 1; // initialize loop counter

    // processing phase
    while ( gradeCounter <= 10 ) // loop 10 times
    {
        cout << "Enter grade: "; // prompt for input
        cin >> grade; // input next grade
        total = total + grade; // add grade to total
        gradeCounter = gradeCounter + 1; // increment counter by 1
    } // end while

    // termination phase
    average = total / 10; // integer division yields integer result

    // display total and average of grades
    cout << "n/Total of all 10 grades is " << total << endl;
    cout << "Class average is " << average << endl;
} // end function determineClassAverage
