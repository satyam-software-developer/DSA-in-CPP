
/*Problem statement
Raj is throwing a birthday party. He wants to invite as many friends as possible. He wants a large wooden table to accommodate his friends. There is constraint for this: space in the room. The number of friends a table can accommodate is equal to its perimeter (the sum of all side lengths). The furniture must be placed so that the edges are parallel to the edges of the flat.

You will be given layout of the flat and you have to tell maximum number of friends that he can accommodate in his room.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains two integers R and C (1 <= R, C <= 400), these are the dimensions of the flat.
Each of the following R rows contain exactly C characters. Characters can be '.', 'X'. '.' character means that cell is free and can be used for placing wooden table. 'X' means that cell is blocked and hence, cannot be used.
Constraints:
Time Limit: 1 second
Output format:
Print the maximum number of friends Raj can accommodate, if he buys his table.
Sample Input 1
2 2
..
..
Sample Output 1:
7
Sample Input 1
4 4
X.XX
X..X
..X.
..XX
Sample Output 1:
9
Explanation:
Please refer to the image below for explanation:
Alt Text */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to calculate the perimeter of a rectangle given its width and height
int peri(int w, int h)
{
    return w * 2 + h * 2;
}

int main()
{
    int n, m;
    cin >> n >> m; // Read the dimensions of the grid

    // Initialize a 2D character array to store the grid
    vector<string> arr(n);

    // Initialize an array to keep track of consecutive empty cells ('.') in each column
    vector<int> cnt(m, 0);

    // Variable to track the maximum perimeter found
    int max_perimeter = 0;

    // Loop through each row in the grid
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read the row as a string

        // Update the count of consecutive empty cells in each column
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.')
            {
                cnt[j]++; // Increment the count if the cell is empty
            }
            else
            {
                cnt[j] = 0; // Reset the count if the cell is blocked
            }
        }

        // Calculate the maximum perimeter for rectangles ending in the current row
        for (int j = 0; j < m; j++)
        {
            int h = cnt[j]; // Height of the rectangle is the count of consecutive empty cells in the column
            int w = 1;      // Initialize the width of the rectangle as 1

            // Expand the width of the rectangle to the right
            if (h > 0)
            { // Only expand if there is a height
                for (int k = j + 1; k < m; k++)
                {
                    if (cnt[k] < h)
                    { // Stop expanding if a shorter column is encountered
                        break;
                    }
                    w++;
                }

                // Expand the width of the rectangle to the left
                for (int k = j - 1; k >= 0; k--)
                {
                    if (cnt[k] < h)
                    { // Stop expanding if a shorter column is encountered
                        break;
                    }
                    w++;
                }
            }

            // Update the maximum perimeter found so far
            max_perimeter = max(max_perimeter, peri(w, h));
        }
    }

    // Output the maximum perimeter minus 1 (since the question likely requires this adjustment)
    cout << max_perimeter - 1 << endl;

    return 0;
}
