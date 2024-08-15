
/* 
Problem statement
A ComplexNumber class contains two data members : one is the real part (R) and the other is imaginary (I) (both integers).

Implement the Complex numbers class that contains following functions -

1. constructor
You need to create the appropriate constructor.

2. plus -
This function adds two given complex numbers and updates the first complex number.

e.g.

if C1 = 4 + i5 and C2 = 3 +i1
C1.plus(C2) results in: 
C1 = 7 + i6 and C2 = 3 + i1
3. multiply -
This function multiplies two given complex numbers and updates the first complex number.

e.g.

if C1 = 4 + i5 and C2 = 1 + i2
C1.multiply(C2) results in: 
C1 = -6 + i13 and C2 = 1 + i2
4. print -
This function prints the given complex number in the following format :

a + ib
Note : There is space before and after '+' (plus sign) and no space between 'i' (iota symbol) and b.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : Two integers - real and imaginary part of 1st complex number
Line 2 : Two integers - real and imaginary part of 2nd complex number
Line 3 : An integer representing choice (1 or 2) (1 represents plus function will be called and 2 represents multiply function will be called)
Output format :
Check details of 'print' function given above.
Sample Input 1 :
4 5
6 7
1
Sample Output 1 :
10 + i12
Sample Input 2 :
4 5
6 7
2
Sample Output 2 :
-11 + i58
*/

#include <iostream>
using namespace std;

// Class representing complex numbers
class ComplexNumbers {
public:
    int real; // Real part of the complex number
    int imaginary; // Imaginary part of the complex number

    // Constructor to initialize the real and imaginary parts of the complex number
    ComplexNumbers(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    // Method to add another complex number to the current complex number
    void plus(ComplexNumbers c) {
        // Calculate the sum of real parts and imaginary parts separately
        this->real += c.real;
        this->imaginary += c.imaginary;
    }

    // Method to multiply another complex number with the current complex number
    void multiply(ComplexNumbers c) {
        // Calculate the product using the formula for multiplication of complex numbers
        int temp_real = this->real * c.real - this->imaginary * c.imaginary;
        int temp_imaginary = this->real * c.imaginary + this->imaginary * c.real;
        // Update the real and imaginary parts of the current complex number
        this->real = temp_real;
        this->imaginary = temp_imaginary;
    }

    // Method to print the complex number in the format "real + i*imaginary"
    void print() {
        cout << this->real << " + i" << this->imaginary << endl;
    }
};

// Main function to take input and perform operations on complex numbers
int main() {
    // Create objects for the two complex numbers
    int real1, imaginary1, real2, imaginary2;
    cin >> real1 >> imaginary1 >> real2 >> imaginary2;
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    // Read the choice from the user (1 for addition, 2 for multiplication)
    int choice;
    cin >> choice;

    // Perform the operation based on the user's choice
    if (choice == 1) {
        // Add the two complex numbers
        c1.plus(c2);
        // Print the result
        c1.print();
    } else if (choice == 2) {
        // Multiply the two complex numbers
        c1.multiply(c2);
        // Print the result
        c1.print();
    } else {
        // Exit the program if the choice is invalid
        return 0;
    }

    return 0;
}
