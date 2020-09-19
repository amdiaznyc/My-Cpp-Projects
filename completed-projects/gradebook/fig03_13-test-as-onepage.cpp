// ***NOTE--This file contains three sections that should be three separate files.
// But I combined them into one file divided into three sections for each file,
// because the g++ compiler was not accepting them as separate files.
// So until I can investigate more I did this and received the correct outcome.***

// This first section (lines 7-24) is the header file GradeBook.h
// Fig. 3.11: GradeBook.h
// GradeBook class definition. This file presents GradeBook's public
// interface without revealing the implementation of GradeBook's member
// functions, which are defined in GradeBook.cpp.
#include <string> // class GradeBook uses C++ standard string class
using namespace std;

// GradeBook class definition
class GradeBook
{
public:
    GradeBook( string ); // constructor that initializes courseName
    void setCourseName( string ); // function that sets the course name
    string getCourseName(); // function that gets the course name
    void displayMessage(); // function that displays a welcome message
private:
    string courseName; // course name for this GradeBook
}; // end class GradeBook
// End of first section (header file GradeBook.h)





// This second section (lines 32-63) is the source file GradeBook.cpp
// Fig. 3.12: GradeBook.cpp
// GradeBook member-function definitions. This file contains
// implementations of the member functions prototyped in GradeBook.h.
#include <iostream>
//#include "GradeBook.h" // include definition of class GradeBook
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
// End of second section (source file GradeBook.cpp)





// This third section (lines 70-88 ) is the source file fig03_13.cpp
// Fig. 3.13: fig03_13.cpp
// GradeBook class demonstration after seperating
// its interface from its implementation.
#include <iostream>
//#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// function main begins program execution
int main()
{
    // create two GradeBook objects
    GradeBook gradeBook1( "CS101 Introduction to C++ Programming" );
    GradeBook gradeBook2( "CS102 Data Structures in C++" );

    // display intial value of courseName for each GradeBook
    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
        << "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
        <<endl;
} // end main
// End of the third section (source file fig03_13.cpp)
