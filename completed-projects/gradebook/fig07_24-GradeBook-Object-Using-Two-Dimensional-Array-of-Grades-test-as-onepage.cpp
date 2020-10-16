// Fig. 7.22: GradeBook.h
// Definition of class GradeBook that uses a
// two-dimensional array to store test grades.
// Member functions are defined in GradeBook.cpp
#include <string> // program uses C++ Standard Library string class
using namespace std;

// GradeBook class definition
class GradeBook
{
public:
    // constants
    static const int students = 10; // number of students
    static const int tests = 3; // number of tests

    // constructor initializes course name and array of grades
    GradeBook( string, const int [][ tests ] );

    void setCourseName( string ); // function to set the course name
    string getCourseName(); // function to retrieve the course name
    void displayMessage(); // display a welcome message
    void processGrades(); // perform various operations on the grade data
    int getMinimum(); // find the minimum grade in the grade book
    int getMaximum(); // find the maximum grade in the grade book
    double getAverage( const int [], const int ); // get student's average
    void outputBarChart(); // output bar chart of grade distribution
    void outputGrades(); // output the contents of the grades array
private:
    string courseName; // course name for this grade book
    int grades[ students ][ tests ]; // two-dimensional array of grades
}; // end class GradeBook




// Fig. 7.23: GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses a two-dimensional array to store grades.
#include <iostream>
#include <iomanip> // parameterized stream manipulators
using namespace std;

// include definition of class GradeBook from GradeBook.h
// #include "GradeBook.h"  //Note:REMOVED HEADER HERE TO COMPILE AS ONE PAGE FILE!!

// two-argument constructor initializes courseName and grades array
GradeBook::GradeBook( string name, const int gradesArray[][ tests] )
{
    setCourseName( name ); // initialize courseName

    // copy grades from gradeArray to grades
    for ( int student = 0; student < students; student++ )

        for ( int test = 0; test < tests; test++ )
            grades[ student ][ test ] = gradesArray[ student ][ test ];
} // end two-argument GradeBook constructor

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
void GradeBook::displayMessage()
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

    // call functions getMinimum and getMaximum
    cout << "\nLowest grade in the grade book is " << getMinimum()
        << "\nHighest grade in the grade book is " << getMaximum() << endl;

    outputBarChart(); // display distribution chart of grades on all tests
} // end function processGrades

// find minimum grade in the entire gradebook
int GradeBook::getMinimum()
{
    int lowGrade = 100; // assume lowest grade is 100

    // loop through rows of grades array
    for ( int student = 0; student < students; student++ )
    {
        // loop through columns of current row
        for ( int test = 0; test < tests; test++ )
        {
            // if current grade less than lowGrade, assign it to lowGrade
            if ( grades[ student ][ test ] < lowGrade )
                lowGrade = grades[ student ][ test ]; // new lowest grade
        } // end inner for
    } // end outer for

    return lowGrade; // return lowest grade
} // end function getMinimum

// find maximum grade in the entire gradebook
int GradeBook::getMaximum()
{
    int highGrade = 0; // assume highest grade is 0

    // loop through rows of grades array
    for ( int student = 0; student < students; student++ )
    {
        // loop through columns of current row
        for ( int test = 0; test < tests; test++ )
        {
            // if current grade greater than highGrade, assign to highGrade
            if ( grades[ student ][ test ] > highGrade )
                highGrade = grades[ student ][ test ]; // new highest grade
        } // end inner for
    } // end outer for

    return highGrade; // return highest grade
} // end function getMaximum

// determine average grade for particular set of grades
double GradeBook::getAverage( const int setOfGrades[], const int grades )
{
    int total = 0; // initialize total

    // sum grades in array
    for ( int grade = 0; grade < grades; grade++ )
        total += setOfGrades[ grade ];

    // return average of grades
    return static_cast< double >( total ) / grades;
} // end function getAverage

// output bar chart displaying grade distribution
void GradeBook::outputBarChart()
{
    cout << "\nOverall grade distribution:" << endl;

    // stores frequency of grades in each range of 10 grades
    const int frequencySize = 11;
    int frequency[ frequencySize ] = {}; // initialize elements to 0

    // for each grade, increment the appropiate frequency
    for ( int student = 0; student < students; student++ )

        for ( int test = 0; test < tests; test++ )
            ++frequency[ grades[ student ][ test ] / 10 ];

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
    cout << "            "; // align column heads

    // create a column heading for each of the tests
    for ( int test = 0; test < tests; test++ )
        cout << "Test " << test + 1 << "  ";

    cout << "Average" << endl; // student average column heading

    // create rows/columns of text representing array grades
    for ( int student = 0; student < students; student++ )
    {
        cout << "Student " << setw( 2 ) << student + 1;

        // output student's grades
        for ( int test = 0; test < tests; test++ )
            cout << setw( 8 ) << grades[ student ][ test ];

        // call member function getAverage to calculate student's average;
        // pass row of grades and the value of tests as the arguments
        double average = getAverage( grades[ student ], tests );
        cout << setw( 9 ) << setprecision( 2 ) << fixed << average << endl;
    } // end outer for
} // end function outputGrades




// Fig. 7.24: fig07_24.cpp
// Creates GradeBook object using a two-dimensional array of grades.

// #include "GradeBook.h" // GradeBook class definition  //Note:COMMENTED OUT HEADER HERE TO COMPILE AS ONE PAGE FILE!!

// function main begins program execution
int main()
{
    // two-dimensional array of student grades
    int gradesArray[ GradeBook::students ][ GradeBook::tests ] =
        { { 87, 96, 70 },
          { 68, 87, 90 },
          { 94, 100, 90 },
          { 100, 81, 82 },
          { 83, 65, 85 },
          { 78, 87, 65 },
          { 85, 75, 83 },
          { 91, 94, 100 },
          { 76, 72, 84 },
          { 87, 93, 73 } };

    GradeBook myGradeBook(
        "CS101 Introduction to C++ Programming", gradesArray );
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
} // end main
