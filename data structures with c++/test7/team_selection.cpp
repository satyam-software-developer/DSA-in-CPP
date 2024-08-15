

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& arr, int r, int vidx, string set) {
    // This condition is checked first to print the last set when r reaches 0
    if (r == 0) {
        cout << set << endl;
        return;
    }
    // Base case: if we've reached the end of the array, return
    if (vidx == arr.size()) {
        return;
    }
    // Include the current element in the set and recurse
    // solve(arr, r - 1, vidx + 1, set + to_string(arr[vidx]) + " ");
    // Exclude the current element from the set and recurse
    solve(arr, r, vidx + 1, set);
}

int main() {
    int n;
    cin >> n; // Read the size of the array

    if (n < 12) {
        cout << "Not enough elements to select 12" << endl;
        return 1; // Early exit if there are not enough elements
    }

    vector<int> arr(n); // Create a vector to store the elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Read the elements into the vector
    }

    solve(arr, 12, 0, ""); // Call the solve function to start generating combinations

    return 0;
}

