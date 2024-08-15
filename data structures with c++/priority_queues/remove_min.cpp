
/*Problem statement
Implement the function RemoveMin for the min priority queue class.

For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.

Note : main function is given for your reference which we are using internally to test the code. */

/*
 * Time complexity: O(log(N))
 * Space complexity: O(1)
 *
 * where N is the size of the Priority Queue
 */

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// Custom exception for priority queue operations
class PriorityQueueException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Priority Queue Exception";
    }
};

class RemoveMin
{
private:
    vector<int> heap; // Vector to store the heap elements

public:
    // Constructor to initialize the heap
    RemoveMin() {}

    // Method to check if the heap is empty
    bool isEmpty() const
    {
        return heap.empty();
    }

    // Method to get the size of the heap
    int size() const
    {
        return heap.size();
    }

    // Method to get the minimum element (root) of the heap
    // Throws an exception if the heap is empty
    int getMin() const
    {
        if (isEmpty())
        {
            throw PriorityQueueException();
        }
        return heap[0];
    }

    // Method to insert an element into the heap
    void insert(int element)
    {
        heap.push_back(element);                // Add the element to the end of the heap
        int childIndex = heap.size() - 1;       // Get the index of the newly added element
        int parentIndex = (childIndex - 1) / 2; // Get the index of its parent

        // Percolate up: Swap the child and parent if the child is smaller than the parent
        while (childIndex > 0)
        {
            if (heap[childIndex] < heap[parentIndex])
            {
                swap(heap[childIndex], heap[parentIndex]);
                childIndex = parentIndex;           // Update childIndex to the parent index
                parentIndex = (childIndex - 1) / 2; // Update parentIndex to the new parent
            }
            else
            {
                return; // Stop if the heap property is satisfied
            }
        }
    }

    // Method to remove and return the minimum element (root) of the heap
    // Throws an exception if the heap is empty
    int removeMin()
    {
        if (isEmpty())
        {
            throw PriorityQueueException();
        }
        int ans = heap[0];     // Store the minimum element to return later
        heap[0] = heap.back(); // Move the last element to the root
        heap.pop_back();       // Remove the last element

        // Heapify down: Restore the heap property by moving the root element down
        int index = 0;
        int minIndex = index;
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;

        while (leftChildIndex < heap.size())
        {
            if (heap[leftChildIndex] < heap[minIndex])
            {
                minIndex = leftChildIndex; // Update minIndex to left child if smaller
            }
            if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[minIndex])
            {
                minIndex = rightChildIndex; // Update minIndex to right child if smaller
            }
            if (minIndex == index)
            {
                break; // Stop if the heap property is satisfied
            }
            else
            {
                swap(heap[index], heap[minIndex]);
                index = minIndex;                // Update index to minIndex
                leftChildIndex = 2 * index + 1;  // Update left child index
                rightChildIndex = 2 * index + 2; // Update right child index
            }
        }
        return ans; // Return the removed minimum element
    }
};

// Main function to test the priority queue
int main()
{
    RemoveMin pq; // Create a new RemoveMin instance
    int choice;

    while (cin >> choice && choice != -1)
    {
        switch (choice)
        {
        case 1: // Insert
        {
            int element;
            cin >> element;
            pq.insert(element);
            break;
        }
        case 2: // Get minimum element
            try
            {
                cout << pq.getMin() << endl;
            }
            catch (const PriorityQueueException &e)
            {
                cout << INT_MIN << endl;
            }
            break;
        case 3: // Remove minimum element
            try
            {
                cout << pq.removeMin() << endl;
            }
            catch (const PriorityQueueException &e)
            {
                cout << INT_MIN << endl;
            }
            break;
        case 4: // Get size
            cout << pq.size() << endl;
            break;
        case 5: // Check if empty
            cout << pq.isEmpty() << endl;
            break;
        default:
            return 0;
        }
    }

    return 0;
}
