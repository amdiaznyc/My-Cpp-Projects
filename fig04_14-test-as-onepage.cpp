// ***NOTE--This file contains three sections that should be three separate files.
// But I combined them into one file divided into three sections for each file,
// because the g++ compiler was not accepting them as separate files.
// So until I can investigate more I did this and received the correct outcome.***

// This first section (lines 7-24) is the header file GradeBook.h
// Fig. 4.12: GradeBook.h
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





// This second secton (lines 32-115) is the source file GradeBook.cpp
// Fig. 4.13: GradeBook.cpp
// Member-function definitions for class GradeBook that solves the
// class average program with sentinel-controlled repetition.
#include <iostream>
#include <iomanip> // parameterized stream manipulators
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

// determine class average based on 10 grades entered by user
void GradeBook::determineClassAverage()
{
    int total; // sum of grades entered by user
    int gradeCounter; // number of grades entered 
    int grade; // grade value
    double average; // number with decimal point for average

    // initialization phase
    total = 0; // initialize total
    gradeCounter = 0; // initialize loop counter

    // processing phase
    // prompt for input and read grade from user
    cout << "Enter grade or -1 to quit: ";
    cin >> grade;  // input grade or sentinel value

    // loop until sentinel value read from user
    while ( grade != -1 ) // while grade is not -1
    {
        total = total + grade; // add grade to total
        gradeCounter = gradeCounter + 1; // increment counter

        // prompt for input and read next grade from user
        cout << "Enter grade or -1 to quit: ";
        cin >> grade; // input grade or sentinel value
    } // end while

// termination phase
    if ( gradeCounter != 0 ) // if user entered at least one grade...
    {
        // calculate average of all grades entered
        average = static_cast< double >( total ) / gradeCounter;

        // display total and average (with two digits of precision)
        cout << "\nTotal of all " << gradeCounter << " grades entered is "
            << total << endl;
        cout << "Class average is " << setprecision( 2 ) << fixed << average
            << endl;
    } // end if
    else // no grades were entered, so output appropiate message
        cout << "No grades were entered" << endl;
} // end function determineClassAverage
// End of second section (source file GradeBook.cpp)





// This third section (line 123-135) is the source file fig04-14.cpp
// Fig. 4.14: fig04_14.cpp
// Create GradeBook object and invoke it determineClassAverage function.
//#include "GradeBook.h" // include definition of class GradeBook

int main()
{
    // create GradeBook object myGradeBook and
    // pass course name to constructor
    GradeBook myGradeBook( "CS101 C++ Programming" );

    myGradeBook.displayMessage(); // display welcome message
    myGradeBook.determineClassAverage(); // find average of 10 grades
} // end main
// End of the third section (source file fig04-14.cpp)
