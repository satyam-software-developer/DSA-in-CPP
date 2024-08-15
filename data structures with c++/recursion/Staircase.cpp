
/*
Problem statement
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count how many possible ways the child can run up to the stairs.
You need to return number of possible ways W.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Integer N
Output Format :
Integer W
Constraints :
1 <= N <= 30
Sample Input 1 :
4
Sample Output 1 :
7
Sample Input 2 :
5
Sample Output 2 :
13
*/

/*
  Time Complexity : O(3^n)
  Space Complexity : O(n)
  where n is size of input array
*/

#include <iostream>
using namespace std;

// Function to calculate the number of ways to climb n stairs
int staircase(int n)
{
    // Base case: if n is negative, there are no ways to climb the stairs, return 0
    if (n < 0)
    {
        return 0;
    }
    // Base case: if n is 0, there is one way to climb the stairs (by not climbing), return 1
    if (n == 0)
    {
        return 1;
    }
    // Recursive case: calculate the number of ways to climb n stairs by summing up the number
    // of ways to climb (n-1), (n-2), and (n-3) stairs recursively
    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

// Main function
int main()
{
    // Declare variables to store user input and output
    int n, output;
    // Prompt the user to enter the number of stairs
    cin >> n;
    // Call the staircase function with the input number of stairs and store the result
    output = staircase(n);
    // Print the number of ways to climb the stairs
    cout << output << endl;

    return 0;
}
