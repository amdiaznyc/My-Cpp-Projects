// ***NOTE--This file contains three sections that should be three separate files.
// But I combined them into one file divided into three sections for each file,
// because the g++ compiler was not accepting them as separate files.
// So until I can investigate more I did this and received the correct outcome.***

// This first section (lines 7-23) is the header file GradeBook.h
// Fig. 3.15: GradeBook.h
// GradeBook class definition presents the public interface of
// the class. Member-function definitions appear in GradeBook.cpp.
#include <string> // program uses C++ standard string class
using namespace std;

// GradeBook class definition
class GradeBook
{
public:
    GradeBook( string ); // constructor that initializes a GradeBook object
    void setCourseName( string ); // function that sets the course name
    string getCourseName(); // function that gets the course name
    void displayMessage(); // function that displays a welcome message
private:
    string courseName; // course name for this GradeBook
}; // end class GradeBook
// End of first section (header file GradeBook.h)





// This second section (lines 31-73) is the source file GradeBook.cpp
// Fig. 3.16: GradeBook.cpp
// Implementations of the GradeBook member-function definitions.
// The setCourseName function performs validation.
#include <iostream>
//#include "GradeBook.h" // include the definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name )
{
    setCourseName( name ); // validate and store courseName
} // end GradeBook constructor

// function that sets the course name;
// ensures that the course name has at most 25 characters
void GradeBook::setCourseName( string name )
{
    if ( name.length() <= 25 ) // if name has 25 or fewer characters
        courseName = name; // store the course name in the object

    if ( name.length() > 25 ) // if name has more than 25 characters
    {
        // set courseName to first 25 characters of parameter name
        courseName = name.substr( 0, 25 ); // start at 0, length of 25

        cout << "Name \"" << name << "\" exceeds maximum length (25).\n"
            << "Limiting courseName to first 25 character.\n" << endl;
    } // end if
} // end function setCourseName

// function to get the course name
string GradeBook::getCourseName()
{
    return courseName; // return object's courseName
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage()
{
    // call getCourseName to get the courseName
    cout << "Welcome to the grade book for\n" << getCourseName()
        << "!" << endl;
} // end function displayMessage
// End of second section (source file GradeBook.cpp)





// This third seciton (lines 81-109) is the source file fig03_17.cpp
//Fig. 3.17: fig03_17.cpp
// Create and manipulate a GradeBook object; illustrate validation.
#include <iostream>
//#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// function main begins program execution
int main()
{
    // create two GradeBook objects;
    // initial course name of gradeBook1 is too long
    GradeBook gradeBook1( "CS101 Introduction to Programming in C++" );
    GradeBook gradeBook2( "CS102 C++ Data Structures" );

    // display each GradeBook's courseName
    cout << "gradeBook1's initial course name is: "
        << gradeBook1.getCourseName()
        << "\ngradeBook2's initial course name is: "
        << gradeBook2.getCourseName() << endl;

    // modify myGradeBook's courseName (with a valid-length string)
    gradeBook1.setCourseName( "CS101 C++ Programming" );

    // display each GradeBook's courseName
    cout << "\ngradeBook1's course name is: "
        << gradeBook1.getCourseName()
        << "\ngradeBook2's course name is: "
        << gradeBook2.getCourseName() << endl;
} // end main
// End of the third section (souce file fig03_13.cpp)
