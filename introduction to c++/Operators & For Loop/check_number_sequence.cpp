
/*Problem statement
You are given S, a sequence of n integers i.e. S = s1, s2, ..., sn.
Compute if it is possible to split S into two parts : s1, s2, ..., si and si+1, si+2, ….., sn (0 <= i <= n) in
such a way that the first part is strictly decreasing while the second is strictly increasing one.

Note : We say that x is strictly larger than y when x > y.
So, a strictly increasing sequence can be 1 4 8.
However, 1 4 4 is NOT a strictly increasing sequence.


That is, in the sequence if numbers are decreasing, they can start increasing at one point.
Thereafter, they cannot decrease at any point further.

Sequence made up of only increasing numbers or only decreasing numbers is a valid sequence.
So, in both the cases, print true.


You just need to print true/false. No need to split the sequence.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= n <= 10^7
Sample Input 1 :
5
9
8
4
5
6
Sample Output 1 :
true
Sample Input 2 :
3
1
2
3
Sample Output 2 :
true
Sample Input 3 :
3
8
7
7
Sample Output 3 :
false
Explanation for Sample Format 3 :
8 7 7 is not strictly decreasing, so output is false.
Sample Input 4 :
6
8
7
6
5
8
2
Sample Output 4 :
false
Explanation for Sample Input 4 :
The series is :
8 7 6 5 8 2
It is strictly decreasing first (8 7 6 5). Then it's strictly increasing (5 8).
But then it starts strictly decreasing again (8 2).
Therefore, the output for this test case is 'false'
*/
#include <iostream>	 // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
	// Write your code here
	int n;					  // the number of elements in the sequence
	cin >> n;				  // read the input from the user
	int prev, curr;			  // variables to store the previous and current element
	bool isDecreasing = true; // variable to indicate if the sequence is decreasing
	bool isValid = true;	  // variable to indicate if the sequence is valid
	cin >> prev;			  // read the first element
	for (int i = 1; i < n; i++)
	{				 // loop from the second element to the last
		cin >> curr; // read the current element
		if (isDecreasing)
		{ // if the sequence is decreasing
			if (curr > prev)
			{						  // if the current element is larger than the previous
				isDecreasing = false; // switch to increasing mode
			}
			else if (curr == prev)
			{					 // if the current element is equal to the previous
				isValid = false; // the sequence is not strictly decreasing
				break;			 // exit the loop
			}
		}
		else
		{ // if the sequence is increasing
			if (curr < prev)
			{					 // if the current element is smaller than the previous
				isValid = false; // the sequence is not strictly increasing
				break;			 // exit the loop
			}
			else if (curr == prev)
			{					 // if the current element is equal to the previous
				isValid = false; // the sequence is not strictly increasing
				break;			 // exit the loop
			}
		}
		prev = curr; // update the previous element
	}
	if (isValid)
	{							// if the sequence is valid
		cout << "true" << endl; // print true
	}
	else
	{							 // if the sequence is not valid
		cout << "false" << endl; // print false
	}
	return 0; // exit the program
}
