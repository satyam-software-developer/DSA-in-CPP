
/*
Problem statement
Write a recursive function to convert a given string into the number it represents.
That is input will be a numeric string that contains only numbers,
you need to convert the string into corresponding integer and return the answer.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 < |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/

/*
   Time Complexity : O(n)
   Space Complexity : O(n)
   where n is size of input array
*/

#include <iostream>
using namespace std;

// Function to find the length of a character array (string)
int length(char input[])
{
    int len = 0;
    // Iterate through the array until the null terminator '\0' is encountered
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// Recursive function to convert a string to a number
int stringToNumber(char input[], int last)
{
    // Base case: If only one character left in the string
    if (last == 0)
    {
        // Convert the character to integer and return
        return input[last] - '0';
    }

    // Recursive case: More than one character left in the string
    // Convert the substring starting from the first character up to the second last character to a number
    int smallAns = stringToNumber(input, last - 1);
    // Convert the last character to integer
    int a = input[last] - '0';
    // Combine the result of the recursive call with the last digit to get the final number
    return smallAns * 10 + a;
}

// Function to initiate the recursive conversion process
int stringToNumber(char input[])
{
    // Find the length of the input string
    int len = length(input);
    // Call the recursive function with the last index of the string
    return stringToNumber(input, len - 1);
}

// Main function
int main()
{
    // Declare a character array to store the input string
    char input[50];
    // Prompt the user to enter a string
    cin >> input;
    // Call the stringToNumber function and print the result
    cout << stringToNumber(input) << endl;

    return 0;
}
