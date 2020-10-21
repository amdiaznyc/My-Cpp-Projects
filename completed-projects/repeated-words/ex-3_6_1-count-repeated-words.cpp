#include <iostream>
using namespace std;

int main()
{
    int number_of_words = 0;
    string previous = " "; // previous word; initialized to "not a word"
    string current;  // current word
    while ( cin >> current ){ //read a stream of words
        ++number_of_words; // increase word count
        if ( previous == current ) // check if the word is same as last
            cout << "word number " << number_of_words
                << " words repeated: "<< current << '\n';
        previous = current;
    }
}
