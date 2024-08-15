
/*
Problem statement
You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.

Detailed explanation ( Input/output format, Notes, Images )
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements(in ascending order) of the singly linked list separated by a single space.
 Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Sample Input 1 :
1
1 2 3 3 3 3 4 4 4 5 5 7 -1
Sample Output 1 :
1 2 3 4 5 7 
Sample Input 2 :
2
10 20 30 40 50 -1
10 10 10 10 -1
Sample Output 2 :
10 20 30 40 50
10 
*/

/*
 *  Time Complexity : O(n)
 *  Space Complexity : O(1)
 * Where 'n' is the size of the Singly Linked List
 */

#include <iostream>
using namespace std;

// Define a Node class for the linked list
class Node
{
public:
	int data;	// Data of the node
	Node *next; // Pointer to the next node in the linked list

	// Constructor to initialize the node with data and set next pointer to NULL
	Node(int data)
	{
		this->data = data; // Set the data of the node
		this->next = NULL; // Initialize next pointer as NULL
	}
};

// Function to take input and create a linked list
Node *takeinput()
{
	int data;
	cin >> data; // Read the first data

	Node *head = NULL; // Initialize head pointer as NULL
	Node *tail = NULL; // Initialize tail pointer as NULL

	// Read data until -1 is encountered
	while (data != -1)
	{
		Node *newnode = new Node(data); // Create a new node with the given data

		// If head is NULL, set the new node as head and tail
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			// Otherwise, append the new node to the end of the linked list
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data; // Read the next data
	}
	return head; // Return the head of the linked list
}

// Function to print the linked list
void print(Node *head)
{
	Node *temp = head; // Create a temporary pointer to traverse the linked list

	// Traverse the linked list and print each node's data
	while (temp != NULL)
	{
		cout << temp->data << " "; // Print the data of the current node
		temp = temp->next;		   // Move to the next node
	}
	cout << endl; // Print a new line after printing all nodes
}

// Function to remove duplicates from the linked list
Node *removeDuplicates(Node *head)
{
	// If the head is null, return null
	if (head == NULL)
	{
		return head;
	}
	Node *currHead = head; // Initialize current head as head of the linked list

	// Iterate over the linked list until the next node of current head is null
	while (currHead->next != NULL)
	{
		// If the data of current head and its next node are equal
		if (currHead->data == currHead->next->data)
		{
			currHead->next = currHead->next->next; // Remove the next node
		}
		else
		{
			// Otherwise, move to the next node
			currHead = currHead->next;
		}
	}
	return head; // Return the head of the modified linked list
}

// Main function to execute the program
int main()
{
	int t;
	cin >> t; // Read the number of test cases

	// Iterate over the test cases
	while (t--)
	{
		Node *head = takeinput();	   // Take input and create a linked list
		head = removeDuplicates(head); // Remove duplicates from the linked list
		print(head);				   // Print the modified linked list
	}

	return 0; // Return 0 to indicate successful execution
}
