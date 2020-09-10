#include <iostream>

int main() {

    double tempf, tempc; //declare two variables using the type 'double'
    
    std::cout << "What is the current temperature in degrees Farenheit? \n";
    std::cin >> tempf;


    tempc = (tempf - 32) / 1.8;

    std::cout << "OK, so converted, the temp is " << tempc << " degrees Celsius.\n";

}
