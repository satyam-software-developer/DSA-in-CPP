
/*Problem statement
A popular tourist destination country is situated on a breathtakingly beautiful archipelago constantly bathed by the sun. The country's residents are very proud of their numerous islands. However, global warming has them very worried: raising sea levels are resulting in rapidly increasing loss of dry land, which is diminishing the beauty of the archipelago.

The map of the archipelago is represented by a grid of R by C squares (characters). The character 'X' (uppercase letter x) represents dry land, while '.' (period) represents sea. It has been estimated that, in fifty years, sea will have flooded every square of land that is currently surrounded by sea on three or on all four sides (north, south, east, west). Assume that all squares outside the map (along the edges) are covered by sea.

Your task is computing the map of the archipelago in fifty years (after the described sea level rise).

Since there will probably be less land than today, you shouldn't print out the whole map, but only its smallest rectangular part that contains all land squares. It is guaranteed that at least one square of land will remain in all test cases.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains two positive integers, R and C, the dimensions of the current map.
Each of the following R lines contains C characters. These R by C characters represent the current map of the archipelago.
Constraints:
1 ≤ R, C ≤ 10
Time limit: 1 sec
Output Format:
The output must contain an appropriate number of lines representing the required rectangular part of the future (flooded) map.
Sample Input 1:
5 3
...
.X.
.X.
.X.
...
Sample Output 1:
X
Sample Input 2:
3 10
..........
..XXX.XXX.
XXX....... 
Sample Output 2:
.XX...X
XX..... */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Variables to store the map and a modified version of the map
vector<string> map;
char newmap[12][12];

// Arrays to represent the four possible directions (right, left, down, up)
int u[] = {0, 0, 1, -1};
int v[] = {1, -1, 0, 0};

int main()
{
    int r, s;
    cin >> r >> s; // Read the number of rows and columns

    map.resize(r);  // Resize the map vector to have 'r' rows
    int mini = 100; // Initialize minimum row index for 'X'
    int maxi = 0;   // Initialize maximum row index for 'X'
    int minj = 100; // Initialize minimum column index for 'X'
    int maxj = 0;   // Initialize maximum column index for 'X'

    // Read the map from input
    for (int i = 0; i < r; ++i)
    {
        cin >> map[i];
    }

    // Traverse through the map to determine the new map and find the bounding box for 'X'
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < s; ++j)
        {
            int more = 0; // Counter for adjacent water cells
            // Check the four possible directions for adjacent water cells
            for (int k = 0; k < 4; ++k)
            {
                int x = i + u[k];
                int y = j + v[k];
                // If the adjacent cell is out of bounds or is water, increment the counter
                if (x < 0 || y < 0 || x >= r || y >= s || map[x][y] == '.')
                {
                    more++;
                }
            }
            // If there are three or more adjacent water cells, the current cell becomes water
            if (more >= 3)
            {
                newmap[i][j] = '.';
            }
            else
            {
                // Otherwise, the current cell remains as is
                newmap[i][j] = map[i][j];
            }
            // Update the bounding box if the current cell contains 'X'
            if (newmap[i][j] == 'X')
            {
                mini = min(mini, i);
                maxi = max(maxi, i);
                minj = min(minj, j);
                maxj = max(maxj, j);
            }
        }
    }

    // Print the new map within the bounding box of 'X'
    for (int i = mini; i <= maxi; ++i)
    {
        for (int j = minj; j <= maxj; ++j)
        {
            cout << newmap[i][j];
        }
        cout << '\n';
    }

    return 0;
}
