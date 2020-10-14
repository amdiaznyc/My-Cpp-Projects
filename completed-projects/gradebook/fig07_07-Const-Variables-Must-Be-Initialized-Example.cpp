// Fig. 7.7: fig07_07.cpp
// A const variable must be initialized.

int main()
{
    const int x; // Error: x must be initialized

    x = 7; // Error: cannot modify a const variable
} // end main
