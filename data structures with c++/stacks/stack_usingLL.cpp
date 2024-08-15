
/* Problem statement
Implement a Stack Data Structure specifically to store integer data using a Singly Linked List.

The data members should be private.

You need to implement the following public functions :

1. Constructor:
It initialises the data members as required.

2. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.

3. pop() :
It pops the element from the top of the stack and in turn, returns the element being popped or deleted. In case the stack is empty, it returns -1.

4. top :
It returns the element being kept at the top of the stack. In case the stack is empty, it returns -1.

5. size() :
It returns the size of the stack at any given instance of time.

6. isEmpty() :
It returns a boolean value indicating whether the stack is empty or not.

Operations Performed on the Stack:
Query-1(Denoted by an integer 1): Pushes an integer data to the stack.

Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack and returns it to the caller.

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack but doesn't remove it, unlike the pop function.

Query-4(Denoted by an integer 4): Returns the current size of the stack.

Query-5(Denoted by an integer 5): Returns a boolean value denoting whether the stack is empty or not.
Detailed explanation ( Input/output format, Notes, Images )
 Constraints:
1 <= q <= 10^5
1 <= x <= 5
-2^31 <= data <= 2^31 - 1 and data != -1

Where 'q' is the total number of queries being performed on the stack, 'x' is the range for every query and data represents the integer pushed into the stack. 

Time Limit: 1 second
Sample Input 1:
6
1 13
1 47
4
5
2
3
Sample Output 1:
2
false
47
13
Sample Input 2:
4
5
2
1 10
5
Sample Output 2:
true
-1
false
 Explanation of Sample Input 2:
There are 4 queries in total.
The first one is Query-5: It tells whether the stack is empty or not. Since the stack is empty at this point, the output is  'true'.

The second one is Query-2: It pops the data from the stack. Since at this point in time, no data exist in the stack hence, it prints -1.

The third one is Query-1: It pushes the specified data 10 into the stack and since the function doesn't return anything, nothing is printed.

The fourth one is Query-5: It tells whether the stack is empty at this point or not. Since the stack has one element and hence it is not empty, false is printed.
				
 */

/*
 * Time complexity: O(1) [for all operations]
 * Space complexity: O(N)
 *
 * where N is the number of operations
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Node class represents each element in the stack
class Node
{
private:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node

public:
    // Constructor to initialize the node with data
    Node(int data) : data(data), next(nullptr) {}

    // Getter for data
    int getData() const
    {
        return data;
    }

    // Getter for the next node
    Node *getNext() const
    {
        return next;
    }

    // Setter for the next node
    void setNext(Node *next)
    {
        this->next = next;
    }
};

// StackUsingLL class represents the stack using a singly linked list
class StackUsingLL
{
private:
    Node *head; // Pointer to the top of the stack
    int size;   // Current size of the stack

public:
    // Constructor to initialize an empty stack
    StackUsingLL() : head(nullptr), size(0) {}

    // Pushes an element onto the stack
    void push(int element)
    {
        Node *newNode = new Node(element); // Create a new node
        newNode->setNext(head);            // Link the new node to the current head
        head = newNode;                    // Update head to the new node
        size++;                            // Increment the size of the stack
    }

    // Pops the top element from the stack and returns it
    int pop()
    {
        if (isEmpty())
        {
            return -1; // Return -1 if the stack is empty
        }
        int data = head->getData(); // Get data from the head node
        Node *temp = head;          // Temporarily store the current head
        head = head->getNext();     // Update head to the next node
        delete temp;                // Delete the old head node
        size--;                     // Decrement the size of the stack
        return data;                // Return the popped data
    }

    // Returns the top element without removing it
    int top() const
    {
        if (isEmpty())
        {
            return -1; // Return -1 if the stack is empty
        }
        return head->getData(); // Return data from the head node
    }

    // Returns the current size of the stack
    int getSize() const
    {
        return size;
    }

    // Checks if the stack is empty
    bool isEmpty() const
    {
        return head == nullptr; // Return true if head is null, false otherwise
    }
};

int main()
{
    int q;
    cin >> q;           // Read the number of queries
    cin.ignore();       // Ignore the newline character after the number of queries
    StackUsingLL stack; // Initialize the stack
    string output;      // String to store the output
    string line;        // String to store each line of input

    // Loop through each query
    for (int i = 0; i < q; i++)
    {
        getline(cin, line);    // Read the entire line of input
        stringstream ss(line); // Create a string stream from the input line
        int choice, element;   // Variables to store the query type and element

        ss >> choice; // Read the query type

        switch (choice)
        {
        case 1:                  // Push operation
            ss >> element;       // Read the element to push
            stack.push(element); // Push the element onto the stack
            break;

        case 2:                                      // Pop operation
            output += to_string(stack.pop()) + "\n"; // Pop the top element and add it to output
            break;

        case 3:                                      // Top operation
            output += to_string(stack.top()) + "\n"; // Get the top element and add it to output
            break;

        case 4:                                          // Size operation
            output += to_string(stack.getSize()) + "\n"; // Get the size and add it to output
            break;

        case 5:                                                            // IsEmpty operation
            output += (stack.isEmpty() ? "true" : "false") + string("\n"); // Check if the stack is empty and add result to output
            break;

        default:
            break; // Do nothing for unrecognized commands
        }
    }

    cout << output; // Print the accumulated output
    return 0;
}
