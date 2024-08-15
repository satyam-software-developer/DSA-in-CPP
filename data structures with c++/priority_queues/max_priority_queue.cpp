
/*Problem statement
Implement the class for Max Priority Queue which includes following functions -

1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.

2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.

3. insert -
Given an element, insert that element in the priority queue at the correct position.

4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.

5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.

Note : main function is given for your reference which we are using internally to test the class.*/

/*
 * Time complexity: O(log(N)) [for insert and removeMax functions]
 * O(1) [for all other functions]
 * 
 * Space complexity: O(1) [for all functions]
 * 
 * where N is the size of the Priority Queue
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue
{
private:
    vector<int> heap; // Vector to store the elements of the max priority queue

public:
    // Constructor to initialize the heap
    MaxPriorityQueue()
    {
        heap = vector<int>();
    }

    // Check if the priority queue is empty
    bool isEmpty()
    {
        return heap.size() == 0;
    }

    // Get the size of the priority queue
    int getSize()
    {
        return heap.size();
    }

    // Get the maximum element from the priority queue
    int getMax()
    {
        if (isEmpty())
        {
            return INT_MIN; // Return INT_MIN if the heap is empty
        }
        return heap[0]; // The root of the heap is the maximum element
    }

    // Insert a new element into the priority queue
    void insert(int element)
    {
        heap.push_back(element);                // Add the element to the end of the heap
        int childIndex = heap.size() - 1;       // Index of the newly added element
        int parentIndex = (childIndex - 1) / 2; // Index of the parent element

        // Percolate up: Swap the child and parent if the child is larger than the parent
        while (childIndex > 0)
        {
            if (heap[childIndex] > heap[parentIndex])
            {
                // Swap the child and parent
                int temp = heap[childIndex];
                heap[childIndex] = heap[parentIndex];
                heap[parentIndex] = temp;

                // Update childIndex and parentIndex to continue percolating up
                childIndex = parentIndex;
                parentIndex = (childIndex - 1) / 2;
            }
            else
            {
                return; // Stop if the heap property is satisfied
            }
        }
    }

    // Remove and return the maximum element from the priority queue
    int removeMax()
    {
        if (isEmpty())
        {
            return INT_MIN; // Return INT_MIN if the heap is empty
        }
        int ans = heap[0]; // Store the maximum element to return later

        // Move the last element to the root and remove the last element
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();

        // Heapify down: Restore the heap property by moving the root element down
        int index = 0;
        int maxIndex = index;
        int leftChildIndex = 1;
        int rightChildIndex = 2;

        // While there are children to consider
        while (leftChildIndex < heap.size())
        {
            // Find the larger of the two children
            if (heap[leftChildIndex] > heap[maxIndex])
            {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[maxIndex])
            {
                maxIndex = rightChildIndex;
            }
            if (maxIndex == index)
            {
                break; // Stop if the heap property is satisfied
            }
            else
            {
                // Swap the current element with the larger child
                int temp = heap[index];
                heap[index] = heap[maxIndex];
                heap[maxIndex] = temp;

                // Update index and child indices to continue heapifying down
                index = maxIndex;
                leftChildIndex = 2 * index + 1;
                rightChildIndex = 2 * index + 2;
            }
        }
        return ans; // Return the removed maximum element
    }
};

int main()
{
    MaxPriorityQueue pq; // Create a new MaxPriorityQueue instance
    int choice;
    cin >> choice; // Read the first choice

    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // Insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // Get maximum element
            cout << pq.getMax() << endl;
            break;
        case 3: // Remove maximum element
            cout << pq.removeMax() << endl;
            break;
        case 4: // Get size
            cout << pq.getSize() << endl;
            break;
        case 5: // Check if empty
            cout << (pq.isEmpty() ? "true" : "false") << endl;
            break;
        default:
            return 0; // Exit if an invalid choice is entered
        }
        cin >> choice; // Read the next choice
    }

    return 0;
}
