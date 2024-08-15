

#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
  int x; // the number of terms to print
  cin >> x; // read the input from the user
  int current = 1; // the current term of the series
  int count = 0; // the number of terms printed so far
  while (count < x) { // loop until we print x terms
    int num = 3 * current + 2; // calculate the value of num for the current term
    if (num % 4 != 0) { // check if num is not a multiple of 4
      cout << num << " "; // print num with a space
      count++; // increment the count of terms printed
    }
    current++; // increment the term of the series
  }
  cout << endl; // print a new line
  return 0; // exit the program
}
