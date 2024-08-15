
/*
Problem statement
Given k, find the geometric sum i.e.

1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)
Note :
using recursion.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
Integer k
Output format :
Geometric sum (upto 5 decimal places)
Constraints :
0 <= k <= 1000
Sample Input 1 :
3
Sample Output 1 :
1.87500
Sample Input 2 :
4
Sample Output 2 :
1.93750
Explanation for Sample Input 1:
1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500
*/


/*
   Time Complexity : O(K)
   Space Complexity : O(K)
*/

#include <iostream>
#include <math.h>  // Include the math.h library for pow() function
#include <iomanip> // Include the iomanip library for setprecision()
using namespace std;

// Function to calculate the geometric sum recursively
double geometricSum(int k)
{
    // Base case: if k is 0, return 1
    if (k == 0)
    {
        return 1;
    }
    // Recursive call to calculate the geometric sum for k-1 and add 1/2^k
    return (1 / pow(2, k)) + geometricSum(k - 1);
}

// Main function
int main()
{
    int k;
    // Read input for k
    cin >> k;
    // Set the precision for output to display with 5 decimal places
    cout << fixed << setprecision(5);
    // Call the geometricSum function and print the result
    cout << geometricSum(k) << endl;
    return 0;
}
