
/* Problem statement
You allowed to open a single tab in the browser. All the activities have to be done on that particular tab. You will start with the given homepage. You can visit a particular url. You can get back x steps in history and get forward x steps in the history.

Implement the BrowserHistory class:

1. BrowserHistory(string homepage): Initializes the object with the homepage of the browser. 
2. void visit(string url): Visits url from the current page. It clears up all the forward history.
3. string back(int steps): Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url, after moving back in history.
4. string forward(int steps): Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
There is only one line of input. The first word in the input denotes the homepage. The following line of input contain function calls made using following choices:
1. If the choice is 1, then visit function is called. First the choice and then a string is given to us as input, which is passed as an input url to visit function.
2. If the choice is 2, then back function is called. First the choice and then a integer is given to us as input, which is passed as an input integer to back function.
3. If the choice is 3, then forward function is called. First the choice and then a integer is given to us as input, which is passed as an input integer to forward function.
Output format:
For each call, made to back or forward function, we have to print the url, which will be opened after moving back or forward in history. Each url needs to be printed on a newline. 
Sample Input 1:
gfg.com 1 google.com 1 codingninjas.com 1 youtube.com 2 1 2 1 3 1 1 linkedin.com 3 2 2 2 2 7 1 facebook.com  3 2 2 2 2 4 0
Sample Output 1:
codingninjas.com
google.com
codingninjas.com
linkedin.com
google.com
gfg.com
facebook.com
gfg.com
gfg.com

*/

#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
private:
    string history[5001]; // Array to store the URLs
    int curr; // Current position in the history array
    int max; // Maximum position reached in the history array

public:
    // Constructor to initialize the browser history with the homepage
    BrowserHistory(string homepage) {
        history[0] = homepage; // Set the homepage as the first entry
        curr = 0; // Initialize current position to 0
        max = 0; // Initialize maximum position to 0
    }

    // Method to visit a new URL
    void visit(string url) {
        curr++; // Move to the next position
        history[curr] = url; // Store the new URL at the current position
        max = curr; // Update the maximum position
    }

    // Method to go back a certain number of steps in history
    string back(int steps) {
        if (curr - steps < 0) { // If steps exceed the start of history
            curr = 0; // Set current position to the start
            return history[0]; // Return the first URL (homepage)
        }
        curr = curr - steps; // Move back by the given number of steps
        return history[curr]; // Return the URL at the new current position
    }

    // Method to go forward a certain number of steps in history
    string forward(int steps) {
        if (curr + steps > max) { // If steps exceed the maximum position
            curr = max; // Set current position to the maximum position
            return history[curr]; // Return the URL at the maximum position
        }
        curr = curr + steps; // Move forward by the given number of steps
        return history[curr]; // Return the URL at the new current position
    }
};

int main() {
    string input;
    cin >> input; // Read the initial homepage URL
    BrowserHistory obj(input); // Initialize browser history with the homepage

    int k; // Variable to store the number of steps
    int i; // Variable to store the command

    while (cin >> i) { // Continuously read commands
        switch (i) {
            case 1: // Visit a new URL
                cin >> input; // Read the URL to visit
                obj.visit(input); // Call visit method
                break;
            case 2: // Go back in history
                cin >> k; // Read the number of steps to go back
                cout << obj.back(k) << endl; // Call back method and print the result
                break;
            case 3: // Go forward in history
                cin >> k; // Read the number of steps to go forward
                cout << obj.forward(k) << endl; // Call forward method and print the result
                break;
            default: // Exit the loop for any other command
                return 0;
        }
    }
    return 0;
}
