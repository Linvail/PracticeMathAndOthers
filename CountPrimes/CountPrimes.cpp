// CountPrimes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPrimes( int n )
    {
        if( n <= 2 )
        {
            return 0;
        }
        // Use Sieve of Eratosthenes algorithm.
        // We know 0, 1 are not prime, do not allocate for them.
        // If n is 5, this vector stands for [2, 3, 4].
        int markedNonPrimeCount = 0;
        vector<bool> primeSieve( n - 2, true );
        for( int i = 2; i * i < n; ++i )
        {
            if( primeSieve[i - 2] )
            {
                for( int j = i * i; j < n; j += i )
                {
                    if( primeSieve[j - 2] )
                    {
                        primeSieve[j - 2] = false;
                        markedNonPrimeCount++;
                    }
                }
            }
        }

        return primeSieve.size() - markedNonPrimeCount;
    }

    // Another method is too check if 1162261467 can be divided by n. 1162261467 = 3^19, which is the max number less than 2^31-1.
    bool isPowerOfThree( int n )
    {
        if( n > 0 )
        {
            // Must use doule. Cannot use float, otherwise 4782968 will fail. 4782969 = 3^14.
            double r = log10( n ) / log10( 3 );
            return std::floor( r ) == r;
        }
        return false;
    }
};

int main()
{
    Solution s;

    std::cout << "countPrimes of 2: " << s.countPrimes( 2 ) << endl;
    std::cout << "countPrimes of 3: " << s.countPrimes( 3 ) << endl;
    std::cout << "countPrimes of 121: " << s.countPrimes( 121 ) << endl;

    std::cout << "isPowerOfThree of 4782968: " << s.isPowerOfThree( 4782968 ) << endl;
}

