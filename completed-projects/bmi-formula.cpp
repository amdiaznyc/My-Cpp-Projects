// This is a program to formulate a person's Body Mass Index

#include <iostream>  // This line lets the preprocessor know to include the input/output stream. 


int main() {  // This line start the main function

    double weightkg, heightm, bmi;  // This line declares three variables using the value 'double' for floating-point numbers.

    std::cout << "What is your weight in kg's? \n";
    std::cin >> weightkg;

    std::cout << "What is your height in m's? \n";
    std::cin >> heightm;

    bmi = weightkg / (heightm * heightm);
    std::cout << "Your body mass index (BMI) is:\n" << bmi << ".\n";

}

    


