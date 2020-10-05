// Fig. 6.25: fig06_25.cpp
// Name mangling.

// function square for int values
int square( int x )
{
    return x * x;
} // end function square

// function square for double values
double square( double y )
{
    return y * y;
} // end function square

// function that receives arguments of types
// int, float, char and int &
void nothing1( int a, float b, char c, int &d )
{
    // empty function body
} // end function nothing1

// function that receives arguments of types
// char, int, float & and double &
int nothing2( char a, int b, float &c, double &d )
{
    return 0;
} // end function nothing2

int main()
{
} // end main
