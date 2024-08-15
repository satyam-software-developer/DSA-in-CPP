
/* 
Problem statement
Given the 'start' and the 'end'' positions of the array 'input'. 
Your task is to sort the elements between 'start' and 'end' using quick sort.

Note :
Make changes in the input array itself.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Integer N i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 2 3 5 7
Sample Output 2 :
1 2 3 5 7 
Constraints :
1 <= N <= 10^3
0 <= input[i] <= 10^9
*/

/*
 *  Time Complexity : O('N' * log('N'))
 *  Space Complexity : O(log('N'))
 *  where 'N' is size of input array
 */


// #include<iostream>
// using namespace std;

// /*
//     The function is called with the parameters:
//     quickSort(input, 0, size - 1);
// */

// // Function to partition the array
// int partitionArray(int input[], int start, int end) {
//     // Choosing pivot element
//     int pivot = input[end];
//     int partitionIndex = start;

//     // Partitioning the array
//     for (int i = start; i < end; i++) {
//         if (input[i] <= pivot) {
//             swap(input[i], input[partitionIndex]);
//             partitionIndex++;
//         }
//     }
//     swap(input[partitionIndex], input[end]); // Placing pivot element in its correct position
//     return partitionIndex; // Returning partition index
// }

// // Function to perform quicksort
// void quickSort(int input[], int start, int end) {
//     if (start < end) {
//         int partitionIndex = partitionArray(input, start, end);
//         quickSort(input, start, partitionIndex - 1); // Sorting left subarray
//         quickSort(input, partitionIndex + 1, end);   // Sorting right subarray
//     }
// }

// int main(){
//     int size;
//     cin >> size; // Input size of array
//     int input[size]; // Create an array to store the input elements
//     for (int i = 0; i < size; i++) {
//         cin >> input[i]; // Input each element of the array
//     }
    
//     // Sorting the array
//     quickSort(input, 0, size - 1);
    
//     // Printing the sorted array
//     for (int i = 0; i < size; i++) {
//         cout << input[i] << " ";
//     }
    
//     return 0;
// }



/*
  Time Complexity : O('N' * log('N'))
  Space Complexity : O(log('N'))
  where 'N' is size of input array
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array and return the index of the pivot element
int partitionArray(int input[], int start, int end) {
    // Choose pivot (using the first element as pivot)
    int pivot = input[start];

    // Count elements smaller than pivot and swap
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (input[i] <= pivot) {
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(input[start], input[pivotIndex]); // Swapping pivot to its correct position

    // Ensure left half contains elements smaller than pivot
    // and right half contains larger elements
    int i = start, j = end;
    while (i <= pivotIndex && input[i] <= pivot) {
        i++;
    }
    while (j >= pivotIndex && input[j] > pivot) {
        j--;
    }
    if (i < pivotIndex && j > pivotIndex) {
        swap(input[i], input[j]); // Swap elements if necessary to ensure correct partitioning
        i++;
        j--;
    }
    return pivotIndex; // Return the index of the pivot element
}

// Recursive function to perform quicksort
void quickSort(int input[], int start, int end) {
    if (start >= end) {
        return; // Base case: if array has 0 or 1 element, it is already sorted
    }
    int pivotIndex = partitionArray(input, start, end); // Partition the array
    quickSort(input, start, pivotIndex - 1); // Recursively sort the left subarray
    quickSort(input, pivotIndex + 1, end); // Recursively sort the right subarray
}


// Main function
int main() {

    int size;
    cin >> size; // Input size of array
    int input[size]; // Create an array to store the input elements
    for (int i = 0; i < size; i++) {
        cin >> input[i]; // Input each element of the array
    }
    
    // Sorting the array
    quickSort(input, 0, size - 1);
    
    // Printing the sorted array
    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }
    
    return 0; // Return 0 to indicate successful execution
}
