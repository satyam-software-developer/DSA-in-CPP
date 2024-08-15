
/* 
Problem statement
Aadil has been provided with a sentence in the form of a string as a function parameter. 
The task is to implement a function so as to change the sentence such that each word in the sentence is reversed. 
A word is a combination of characters without any spaces.

Example:
Input Sentence: "Hello I am Aadil"
The expected output will look, "olleH I ma lidaA".
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. 
The input string represents the sentence given to Aadil.
Output Format:
You don't need to print anything just change the sentence(string) such that each word in the sentence is reversed. 
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

All the words in string are separated by a single space.

String does not contain any leading or trailing spaces.

Time Limit: 1 second
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
emocleW ot gnidoC sajniN
Sample Input 2:
Always indent your code
Sample Output 2:
syawlA tnedni ruoy edoc

*/
#include<iostream>
#include <cstring> // Include the header file for string manipulation
using namespace std;

// Define a function to reverse each word in a given string
void reverseEachWord(char input[]){
    int ptrA = 0, ptrB = 0, i = 0;
    int len = strlen(input); // Get the length of the input string

    // Iterate through the input string until reaching the end
    while(true){
        // Check if the current character is a space or end of string
        if(input[i] == ' ' || input[i] == '\0'){
            ptrB= i - 1; // Set the end pointer to the previous character

            // Reverse the characters between the start and end pointers
            while(ptrA < ptrB){
                std::swap(input[ptrA], input[ptrB]); // Swap characters
                ptrA++; // Move the start pointer forward
                ptrB--; // Move the end pointer backward
            }
            ptrA = i + 1; // Update the start pointer for the next word
            ptrB = ptrA; // Set the end pointer equal to the start pointer
        }
        // Check if the current character is the end of string
        if(input[i] == '\0'){
            break; // Exit the loop if end of string is reached
        }
        i++; // Move to the next character
    }
}

// Main function
int main(){

    int size = 1e6; // Define the size for the character array
    char str[size]; // Declare a character array to store the input string
    cin.getline(str, size); // Read input string including spaces
    reverseEachWord(str); // Reverse each word in the input string
    cout << str; // Print the modified string after reversing each word
    
    return 0; // Return 0 to indicate successful completion
}
