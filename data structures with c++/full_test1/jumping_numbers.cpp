
/* Problem statement
Given a number x, print all the jumping numbers below or equal to x. A number is called a jumping number if for a number all the adjacent digits differ by 1. All single digit numbers are also jumping numbers.

Eg. 432345, 32, 543, 989, 12, 21 are jumping numbers whereas 843, 485, 9348 are not.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
An integer x.
Output Format :
All the jumping numbers smaller than or equal to x, separated by space and generated in increasing order of most significant digit.
Input Constraints :
1 <= x <= 10^5

Sample Input 1 :
10
Sample Output 1 :
0 1 10 2 3 4 5 6 7 8 9
Sample Input 2 :
50
Sample Output 2 :
0 1 12 10 2 23 21 3 34 32 4 45 43 5 6 7 8 9 */

#include <iostream>
#include <queue>

using namespace std;

class JumpingNumbers
{
public:
    // Method to display all jumping numbers less than or equal to x
    static void showJumpingNos(int x)
    {
        cout << "0 "; // 0 is always a jumping number
        for (int i = 1; i <= 9 && i <= x; i++)
        {                    // Loop through digits 1 to 9
            bfsHelper(x, i); // Call helper function for each digit
        }
    }

private:
    // Helper method that uses BFS to generate and display jumping numbers
    static void bfsHelper(int x, int num)
    {
        queue<int> q; // Queue to manage BFS
        q.push(num);  // Start BFS with the current number
        while (!q.empty())
        {                    // Continue until queue is empty
            num = q.front(); // Get the front element
            q.pop();         // Dequeue the front element
            if (num <= x)
            {                        // If the number is less than or equal to x
                cout << num << " ";  // Print the number
                int last = num % 10; // Get the last digit of the number
                if (last == 0)
                {
                    // If last digit is 0, only append last digit + 1 to the number
                    q.push((num * 10) + (last + 1));
                }
                else if (last == 9)
                {
                    // If last digit is 9, only append last digit - 1 to the number
                    q.push((num * 10) + (last - 1));
                }
                else
                {
                    // For digits 1 to 8, append both last digit + 1 and last digit - 1
                    q.push((num * 10) + (last + 1));
                    q.push((num * 10) + (last - 1));
                }
            }
        }
    }
};

int main()
{
    int x;
    cin >> x;                          // Read the input number
    JumpingNumbers::showJumpingNos(x); // Display all jumping numbers less than or equal to x
    return 0;
}
