
/* 
Problem statement
You have made a smartphone app and want to set its subscription price such that the profit earned is maximised. 
There are certain users who will subscribe to your app only if their budget is greater than or equal to your price.

You will be provided with a list of size N having budgets of subscribers and you need to return the maximum profit that you can earn.

Lets say you decide that price of your app is Rs. x and there are N number of subscribers. So maximum profit you can earn is :

 m * x
where m is total number of subscribers whose budget is greater than or equal to x.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : N (No. of subscribers)
Line 2 : Budget of subscribers (separated by space)
Output Format :
 Maximum profit
Constraints :
1 <= N <= 10^6

1 <=budget[i]<=9999

Sample Input 1 :
4
30 20 53 14
Sample Output 1 :
60
Sample Output 1 Explanation :
Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.
Sample Input 2 :
5
34 78 90 15 67
Sample Output 2 :
201
Sample Output 2 Explanation :
Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).
*/

#include <iostream>
#include <algorithm> // Include the algorithm library for using the sort function
using namespace std;

// Function to calculate the maximum profit from given budget
int maximumProfit(int budget[], int n)
{
    // Sort the budget array in ascending order
    sort(budget, budget + n);

    // Create an array to store the cost for each budget value
    int *cost = new int[n];
    
    // Calculate the cost for each budget value
    for (int i = 0; i < n; i++)
        cost[i] = budget[i] * (n - i);
    
    // Initialize the maximum profit as 0
    int max = 0;
    
    // Find the maximum cost, which represents the maximum profit
    for (int i = 0; i < n; i++)
        if (cost[i] > max)
            max = cost[i];
    
    // Return the maximum profit
    return max;
}

// Main function
int main()
{
    int n, *input, i, *cost;
    
    // Read the number of budget values from the user
    cin >> n;
    
    // Create an array to store the budget values
    input = new int[n];
    
    // Read the budget values from the user
    for (i = 0; i < n; i++)
        cin >> input[i];

    // Calculate and print the maximum profit
    cout << maximumProfit(input, n) << endl;
    
    // Free the dynamically allocated memory
    delete[] input;
    
    // Return 0 to indicate successful execution
    return 0;
}
