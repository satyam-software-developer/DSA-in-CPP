
/* Problem statement
Punit is playing a game of prime numbers. Given a number N, he is assigned to form a list that contains all the primes less than or equal to N. Now, print all the elements from the list that occupy prime numbered positions.These prime indexed primes are known as super prime.

Like (2, 3, 5, 7, 11, 13, 17, 19, 23, ...) and 3 appears at second position, 2 is also prime. Similarly 5 appears at third position and 3 is a prime. And so on.

The first few super primes are: 3 5 11 17 and so on.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
First and only line contains an integer N.
Output Format:
Print all the super primes less than or equal to N separated by a single space.
Constraints:
1 <= N <= 10^7
Sample Input 1:
7
Sample Output 1:
3 5
Sample Input 2:
17
Sample Output 2:
3 5 11 17  */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to generate all prime numbers less than or equal to n using the Sieve of Eratosthenes.
void SieveOfEratosthenes(int n, vector<bool> &isPrime)
{
    isPrime.assign(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers.

    for (int p = 2; p * p <= n; p++)
    {
        if (isPrime[p])
        {
            // Update all multiples of p to not be prime.
            for (int i = p * p; i <= n; i += p)
            {
                isPrime[i] = false;
            }
        }
    }
}

void superPrimes(int n)
{
    vector<bool> isPrime(n + 1);
    SieveOfEratosthenes(n, isPrime);

    // Vector to store all the primes less than or equal to n.
    vector<int> primes;

    // Collect all prime numbers up to n.
    for (int p = 2; p <= n; p++)
    {
        if (isPrime[p])
        {
            primes.push_back(p);
        }
    }

    // Print the super primes, which are primes at prime-numbered positions.
    for (int k = 0; k < primes.size(); k++)
    {
        if (isPrime[k + 1])
        { // k+1 because positions are 1-indexed.
            cout << primes[k] << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    superPrimes(n);
    return 0;
}
