// ***NOTE--This file contains three sections that should be three separate files.
// But I combined them into one file divided into three sections for each file,
// because the g++ compiler was not accepting them as separate files.
// So until I can investigate more I did this and received the correct outcome.***

// This first section (lines 7-30) is the header file GradeBook.h
// Fig. 5.9: GradeBook.h
// Definition of class GradeBook that counts A, B, C, D and F grades.
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
    void inputGrades(); // input arbitrary number of grades from user
    void displayGradeReport(); // display a report based on the grades
private:
    string courseName; // course name for this GradeBook
    int aCount; // count of A grades
    int bCount; // count of B grades
    int cCount; // count of C grades
    int dCount; // count of D grades
    int fCount; // count of F grades
}; // end class GradeBook
// End of first section (header file GradeBook.h)





// This second secton (lines 38-148) is the source file GradeBook.cpp
// Fig. 5.10: GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses a 'switch' statement to count A, B, C, D and F grades.
#include <iostream>
// #include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument;
// initializes counter data members to 0
GradeBook::GradeBook( string name )
{
    setCourseName( name ); // validate and store courseName
    aCount = 0; // initialize count of A grades to 0
    bCount = 0; // initialize count of B grades to 0
    cCount = 0; // initialize count of C grades to 0
    dCount = 0; // initialize count of D grades to 0
    fCount = 0; // initialize count of F grades to 0
} // end GradeBook constructor

// function to set the course name; limits name to 25 or fewer character
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
    // this statement calls getCourseName to get the
    // name of the course this GradeBook represents
    cout << "Welcome to the grade book for\n" << getCourseName() << "!\n"
        << endl;
} // end function displayMessage

// input arbitrary number of grades from user; update grade counter
void GradeBook::inputGrades()
{
    int grade; // grade entered by user

    cout << "Enter the letter grades." << endl
        << "Enter the EOF character to end input." << endl;

    // loop until user types end-of-file key sequence
while ( ( grade = cin.get() ) != EOF )
    {
        // determine which grade was entered
        switch ( grade ) // switch statement nested in while
        {
            case 'A': // grade was uppercase A
            case 'a': // or lowercase a
                aCount++; // increment aCount
                break; // necessary to exit switch

            case 'B': // grade was uppercase B
            case 'b': // or lowercase b
                bCount++; // increment bCount
                break; // exit switch

            case 'C': // grade was uppercase C
            case 'c': // or lowercase c
                cCount++; // increment cCount
                break; // exit switch

            case 'D': // grade was uppercase D
            case 'd': // or lowercase d
                dCount++; // increment dCount
                break; // exit switch

            case 'F': // grade was uppercase F
            case 'f': // or lowercase f
                fCount++; // increment fCount
                break; // exit switch

            case '\n': // ignore newlines,
            case '\t': // ignore tabs,
            case ' ': // and ignore spaces in input
                break; // exit switch

            default: // catch all other characters
                cout << "Incorrect letter grade entered."
                    << " Enter a new grade." << endl;
                break; // optional; will exit switch anyway
        } // end switch
    } // end while
} // end function inputGrades

// display a report based on the grades entered by user
void GradeBook::displayGradeReport()
{
    // output summary of results
    cout << "\n\nNumber of students who received each letter grade:"
        << "\nA: " << aCount // display number of A grades
        << "\nB: " << bCount // display number of B grades
        << "\nC: " << cCount // display number of C grades
        << "\nD: " << dCount // display number of D grades
        << "\nF: " << fCount // display number of F grades
        << endl;
} // end function displayGradeReport
// End of second section (source file GradeBook.cpp)





// This third section (lines 156-168) is the source file fig05-11.cpp
// Fig. 5.11: fig05_11.cpp
// Create GradeBook object, input grades and display grade report.
// #include "GradeBook.h" // include definition of class GradeBook

int main()
{
    // create GradeBook object
    GradeBook myGradeBook( "CS101 C++ Programming" );

    myGradeBook.displayMessage(); // display welcome message
    myGradeBook.inputGrades(); // read grades from user
    myGradeBook.displayGradeReport(); // display report based on grades
} // end main
// End of the third section (source file fig05-11.cpp)
