// Fig. 7.15: GradeBook.h
// Definition of class GradeBook that uses an array to store test grades.
// Member functions are defined in GradeBook.cpp
#include <string> // program uses C++ standard string class
using namespace std;

// GradeBook class definition
class GradeBook
{
public:
    // constant -- number of students who took the test
    static const int students = 10; // note public data

    // constructor initializes course name and array of grades
    GradeBook( string, const int [] );

    void setCourseName( string ); // function to set the course name
    string getCourseName(); // function to retrieve the course name
    void displayMessage(); // display a welcome message
    void processGrades(); // perform various operations on the grade data
    int getMinimum(); // find the minimum grade for the test
    int getMaximum(); // find the maximum grade for the test
    double getAverage(); // determine the average grade for the test
    void outputBarChart(); // output bar chart of grade distribution
    void outputGrades(); // output the contents of the grades array
private:
    string courseName; // course name for this grade book
    int grades[ students ]; // array of student grades
}; // end class GradeBook



// Fig. 7.16: GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses an array to store test grades.
#include <iostream>
#include <iomanip>
// #include "GradeBook.h" // GradeBook class definition--commented out for one page
using namespace std;

// constructor initializes courseName and grade array
GradeBook::GradeBook( string name, const int gradesArray[] )
{
    setCourseName( name ); // initialize courseName

    // copy grades from gradesArray to grades data member
    for ( int grade = 0; grade < students; grade++ )
        grades[ grade ] = gradesArray[ grade ];
} // end GradeBook constructor

// function to set the course name
void GradeBook::setCourseName( string name )
{
    courseName = name; // store the course name
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName()
{
    return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook:: displayMessage()
{
    // this statement calls getCourseName to get the
    // name of the course this GradeBook represents
    cout << "Welcome to the grade book for\n" << getCourseName() << "!"
        << endl;
} // end function displayMessage

// perform various operations on the data
void GradeBook::processGrades()
{
    outputGrades(); // output grades array

    // display average of all grades and minimum and maximum grades
    cout << "\nClass average is " << setprecision( 2 ) << fixed <<
        getAverage() << "\nLowest grade is " << getMinimum() <<
        "\nHighest grade is " << getMaximum() << endl;

    outputBarChart(); // print grade distribution chart
} // end function processGrades

// find minimum grade
int GradeBook::getMinimum()
{
    int lowGrade = 100; // assume lowest grade is 100

    // loop through grades array
    for ( int grade = 0; grade < students; grade++ )
    {
        // if current grade lower than lowGrade, assign it to lowGrade
        if ( grades[ grade ] < lowGrade )
            lowGrade = grades[ grade ]; // new lowest grade
    } // end 'for' statement

    return lowGrade; // return lowest grade
} // end function getMinimum

// find maximum grade
int GradeBook::getMaximum()
{
    int highGrade = 0; // assume highest grade is 0

// loop through grades array
    for ( int grade = 0; grade < students; grade++ )
    {
        // if current grade higher than highGrade, assign it to highGrade
        if ( grades[ grade ] > highGrade )
            highGrade = grades[ grade ]; // new highest grade
    } // end 'for' statement

    return highGrade; // return highest grade
} // end function getMaximum

// determine average grade for test
double GradeBook::getAverage()
{
    int total = 0; // initialize total

    // sum grades in array
    for ( int grade = 0; grade < students; grade++ )
        total += grades[ grade ];

    // return average of grades
    return static_cast< double >( total ) / students;
} // end function getAverage

// output bar chart displaying grade distribution
void GradeBook::outputBarChart()
{
    cout << "\nGrade distribution:" << endl;

    // stores frequency of grades in each range of 10 grades
    const int frequencySize = 11;
    int frequency[ frequencySize ] = {}; // initialize elements to 0

    // for each grade, increment the appropiate frequency
    for ( int grade = 0; grade < students; grade++ )
        frequency[ grades[ grade ] / students ]++;

    // for each grade frequency, print bar in chart
    for ( int count = 0; count < frequencySize; count++ )
    {
        // output bar labels ("0-9:", ..., "90-99:", "100:" )
        if ( count == 0 )
            cout << "  0-9: ";
        else if ( count == 10 )
            cout << "  100: ";
        else
            cout << count * 10 << "-" << ( count * 10 ) + 9 << ": ";

        // print bar of asterisks
        for ( int stars = 0; stars < frequency[ count ]; stars++ )
            cout << '*';

        cout << endl; // start a new line of output
    } // end outer 'for'
} // end function outputBarChart

// output the contents of the grades array
void GradeBook::outputGrades()
{
    cout << "\nThe grades are:\n\n";

    // output each student's grade
    for ( int student = 0; student < students; student++ )
        cout << "Student " << setw( 2 ) << student + 1 << ": " << setw( 3 )
            << grades[ student ] << endl;
} // end function outputGrades


// Fig. 7.17: fig07_17.cpp
// Creates GradeBook object using an array of grades.
// #include "GradeBook.h" // GradeBook class definition--commented out for one page

// function main begins program execution
int main()
{
    // array of student grades
    int gradesArray[ GradeBook::students ] =
        { 87, 68, 94, 100, 83, 78, 85, 91, 76, 87 };

    GradeBook myGradeBook(
        "CS101 Introduction to C++ Programming", gradesArray );
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
} // end main                                                                               
