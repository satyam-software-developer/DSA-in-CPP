
/* 
Problem statement
Given two integers M & N, calculate and return their multiplication using recursion. 
You can only use subtraction and addition for your calculation. No other operators are allowed.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= M <= 1000
0 <= N <= 1000
Sample Input 1 :
3 
5
Sample Output 1 :
15
Sample Input 2 :
4 
0
Sample Output 2 :
0
*/

/*
  Time Complexity : O(n)
  Space Complexity : O(n)
  where n is the smaller of the two numbers we need to multiply

*/

#include <iostream>
using namespace std;

// Function to perform multiplication of two integers recursively
int multiplyNumbers(int m, int n) {
    // Base case: If either of the numbers is 0, the result is 0
    if (m == 0 || n == 0) {
        return 0;
    }
    // Swapping m and n if n is greater than m to ensure the recursive call reduces the value of n
    if (n > m) {
        return multiplyNumbers(n, m);
    }
    // Recursive case: Add 'm' 'n' times to achieve multiplication
    return m + multiplyNumbers(m, n - 1);
}

int main() {
    // Input two integers from the user
    int m, n;
    cin >> m >> n;
    // Calculate and print the product of the two integers using the multiplyNumbers function
    cout << multiplyNumbers(m, n) << endl;
    return 0;
}
