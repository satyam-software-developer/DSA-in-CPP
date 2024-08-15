
/* Problem statement
You are given a 2D array of integers of size N * M. Each of the cell contains either of these 3 integers: 0, 1, 2. The integer 2 denotes a rotten orange, 1 denotes a fresh orange and 0 denotes an empty cell.

Each rotten orange can rot fresh oranges in 4 adjacent cells in 1 unit of time. The 4 cells are left, right, top and bottom cell.

For a given matrix, find the minimum units of time in which all oranges become rot. Return -1, if it is not possible.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains 2 space separated integers, N and M, that denotes size of given 2D array.
The following N lines contains M space separated integers, that denotes the value of cells of given 2D array.
Constraints:
Value of N and M lies in the range: [1, 10000].
Value of each cell in 2D array can be either 0, 1 or 2.
Output Format:
Print the required integer, as described in the problem description.
Sample Input 1:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1
Sample Output 1:
2
Explanation:
 In the first unit of time, fresh oranges at coordinates: (0, 1), (0, 4), (1, 0), (1, 2), (1, 4), (2, 4).
 In the second unit of time, fresh orange at coordinate: (2, 0) gets rot. Hence, in 2 units of time, all the fresh oranges become rot.
Sample Input 2:
3 5
2 1 0 2 1
1 0 1 0 1
1 0 0 0 2
Sample Output 2:
-1
Explanation:
It is impossible to rot the fresh orange at (1, 2).
 */

#include <iostream>
#include <queue>
using namespace std;

// Class to represent a coordinate pair (x, y)
class Pair
{
public:
    int x;
    int y;
    Pair(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

// Function to check if a cell is within the grid bounds
bool isValid(int r, int c, int rmax, int cmax)
{
    if (r < 0 || r >= rmax || c < 0 || c >= cmax)
    {
        return false;
    }
    return true;
}

// Function to determine the minimum time required to rot all oranges
int rottenOranges(int **arr, int rmax, int cmax)
{
    queue<Pair *> q;

    // Initialize the queue with all initially rotten oranges
    for (int i = 0; i < rmax; i++)
    {
        for (int j = 0; j < cmax; j++)
        {
            if (arr[i][j] == 2)
            {
                Pair *pdash = new Pair(i, j);
                q.push(pdash);
            }
        }
    }
    // Marker to separate time frames in the queue
    q.push(new Pair(-1, -1));

    int count = 0;
    // Process the queue until empty
    while (!q.empty())
    {
        Pair *p = q.front();
        int row = p->x;
        int col = p->y;
        q.pop();

        // Check for the time frame separator
        if (row == -1 && col == -1)
        {
            count++;
            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(new Pair(-1, -1));
                continue;
            }
        }

        // Check the adjacent cells to rot fresh oranges
        // right
        if (isValid(row, col + 1, rmax, cmax) && arr[row][col + 1] == 1)
        {
            arr[row][col + 1] = 2;
            q.push(new Pair(row, col + 1));
        }
        // left
        if (isValid(row, col - 1, rmax, cmax) && arr[row][col - 1] == 1)
        {
            arr[row][col - 1] = 2;
            q.push(new Pair(row, col - 1));
        }
        // top
        if (isValid(row - 1, col, rmax, cmax) && arr[row - 1][col] == 1)
        {
            arr[row - 1][col] = 2;
            q.push(new Pair(row - 1, col));
        }
        // bottom
        if (isValid(row + 1, col, rmax, cmax) && arr[row + 1][col] == 1)
        {
            arr[row + 1][col] = 2;
            q.push(new Pair(row + 1, col));
        }
    }

    // Check if there are any fresh oranges left
    for (int i = 0; i < rmax; i++)
    {
        for (int j = 0; j < cmax; j++)
        {
            if (arr[i][j] == 1)
            {
                return -1; // If there are fresh oranges left, return -1
            }
        }
    }
    return count - 1; // Return the number of time frames taken to rot all oranges
}

int main()
{
    int n, m;
    cin >> n >> m; // Read the dimensions of the grid

    // Dynamically allocate memory for the 2D array
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j]; // Read the elements of the grid
        }
    }

    // Call the function to determine the minimum time to rot all oranges
    int ans = rottenOranges(arr, n, m);
    cout << ans; // Print the result

    // Free the dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
