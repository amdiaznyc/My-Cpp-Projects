// Fig. 9.5: SalesPerson.h
// SalesPerson class definition.
// Member functions defined in SalesPerson.cpp.
#ifndef SALESP_H
#define SALESP_H

class SalesPerson
{
public:
    static const int monthsPerYear = 12; // months in one year
    SalesPerson(); // constructor
    void getSalesFromUser(); // input sales from keyboard
    void setSales( int, double ); // set sales for a specific month
    void printAnnualSales(); // summarize and print sales
private:
    double totalAnnualSales(); // prototype for utility function
    double sales[ monthsPerYear ]; // 12 monthly sales figures
}; // end class SalesPerson

#endif
