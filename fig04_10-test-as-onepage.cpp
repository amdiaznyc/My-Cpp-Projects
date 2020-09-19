// ***NOTE--This file contains three sections that should be three separate files.
// But I combined them into one file divided into three sections for each file,
// because they g++ compiler was not accepting them as separate files.
// So until I can investigate more I did this and received the correct outcome.***

// This first section (lines 7-24) is the header file GradeBook.h
// Fig. 4.8: GradeBook.h
// Definition of class GradeBook that determines a class average.
// Member functions are defined in GradeBook.cpp
#include <string> // program uses C++ standard string class
using namespace std;

// GradeBook class definition
class GradeBook
{
public:
    GradeBook( string ); // constructor initializes 'course name' object
    void setCourseName( string ); // function to set the course name
    string getCourseName(); // function to retrieve the course name 
    void displayMessage(); // display a welcome message 
    void determineClassAverage(); // averages grades entered by the user
private:
    string courseName; // course name for this GradeBook
}; // end class GradeBook
// End of first section (header file GradeBook.h)





// This second section (lines 32-73) is the source file GradeBook.cpp
// Fig. 4.9: GradeBook.cpp
//  Member-function definitions for class GradeBook that solves the
// class average program with counter-controlled repetition.
#include <iostream>
//#include "GradeBook.h" // include definition of class GradeBook
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

// determine class average bases on 10 grades entered by user
void GradeBook::determineClassAverage()
{
    int total; // sum of grades entered by user
    int gradeCounter; // number of the grade to be entered next
    int grade; // grade value entered by user
    int average; // average of grade

    // intialization phase
    total = 0; // initialize total
    gradeCounter = 1; // initialize loop counter

    // processing phase
    while ( gradeCounter <= 10 ) // loop 10 times
    {
        cout << "Enter grade: "; // promp for input
        cin >> grade; // input next grade
        total = total + grade; // add grade to total
        gradeCounter = gradeCounter + 1; // increment counter by 1
    } // end while

    // termination phase
    average = total / 10; // interger division yields interger result

    // display total and average of grades
    cout << "\nTotal of all 10 grades is " << total << endl;
    cout << "Class average is " << average << endl;
} // end function determineClassAverage
// End of second section (source file GradeBook.cpp)





// This third section (lines 77-89) is the source file fig03_13.cpp
// Fig. 4.10: fig04_10.cpp
// Create GradeBook object and invoke its determineClassAverage function.
//#include "GradeBook.h" // include definition of class GradeBook

int main()
{
    // create GradeBook object myGradeBook and
    // pass course name to constructor
    GradeBook myGradeBook( "CS101 C++ Programming" );

    myGradeBook.displayMessage(); // display welcome message
    myGradeBook.determineClassAverage(); // find average of 10 grades
} // end main
// End of the third section (source file fig03_13.cpp)
