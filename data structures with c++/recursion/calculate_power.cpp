
/* 
Problem statement
Write a program to find x to the power n (i.e. x^n). 
Take x and n from the user. You need to return the answer.

Do this recursively.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Two integers x and n (separated by space)
Output Format :
x^n (i.e. x raise to the power n)
Constraints :
0 <= x <= 30
0 <= n <= 30
Sample Input 1 :
 3 4
Sample Output 1 :
81
Sample Input 2 :
 2 5
Sample Output 2 :
32
*/

/*
  Time Complexity : O(n)
  Space Complexity : O(n)

  where n is the exponent

*/

#include <iostream>
using namespace std;

// Recursive function to compute the power of a number
int power(int x, int n)
{
    // Base case: if the exponent is 0, return 1
    if (n == 0)
    {
        return 1;
    }
    // Recursive case: compute x^n by multiplying x with x^(n-1)
    return x * power(x, n - 1);
}

// Main function
int main()
{
    int x, n;
    // Read the base (x) and the exponent (n) from the user
    cin >> x >> n;

    // Compute x^n using the power function and print the result
    cout << power(x, n) << endl;

    return 0;
}
