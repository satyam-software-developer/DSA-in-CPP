
/*Problem statement
Given three integers A, X, and n, the task is to print terms of below binomial expression series.

(A+X)^n = a0*X^0 + a1*X^1 +….+an*X^n.
So at each position find the value of the general term and print that term(Print a0,a1x,a2x^2,....,an*x^n).

Detailed explanation ( Input/output format, Notes, Images )
Input Format:

3 space seperated integers-> A,X,n.
Output Format:

The output is the terms of the binomial expression series.
Sample input:
 1 2 6
Sample Output:
1 12 60 160 240 192 64 */

#include <iostream>
#include <cmath>

using namespace std;

class BinomialExpansion
{
public:
    // Function to print the binomial expansion series
    static void series(int A, int X, int n)
    {
        // Calculate and print the first term A^n
        int term = pow(A, n);
        cout << term << " ";

        // Compute and print the remaining terms
        for (int i = 1; i <= n; i++)
        {
            // Calculate the current term using the previous term
            // Update the term by multiplying it with X and (n - i + 1)
            // Divide the term by (i * A)
            term = term * X * (n - i + 1) / (i * A);
            cout << term << " ";
        }
    }
};

int main()
{
    // Declare variables for A, X, and n
    int A, X, n;

    // Read integer values for A, X, and n from the user
    cin >> A >> X >> n;

    // Call the series function to print the binomial expansion
    BinomialExpansion::series(A, X, n);

    return 0;
}
