// Math.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:

    // Check if log(3)(n) is an integer.
    // logarithmic identity - Changing the base
    // log(a)(b) = log(c)(b) / log(c)(a) while a and c > 1
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

    // Another method is too check if 1162261467 can be divided by n. 1162261467 = 3^19, which is the max number less than 2^31-1.
    bool isPowerOfThree_v2( int n )
    {
        return n > 0 && ( 1162261467 % n ) == 0;
    }

    /*
    * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
    For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer.
    */

    // This is worse than v2.
    int romanToInt( string s )
    {
        int result = 0;
        for( int i = 0; i < s.length(); ++i )
        {
            if( s[i] == 'V' )
            {
                result += ( i > 0 && s[i - 1] == 'I' ) ? 3 : 5;
            }
            else if( s[i] == 'X' )
            {
                result += ( i > 0 && s[i - 1] == 'I' ) ? 8 : 10;
            }
            else if( s[i] == 'L' )
            {
                result += ( i > 0 && s[i - 1] == 'X' ) ? 30 : 50;
            }
            else if( s[i] == 'C' )
            {
                result += ( i > 0 && s[i - 1] == 'X' ) ? 80 : 100;
            }
            else if( s[i] == 'D' )
            {
                result += ( i > 0 && s[i - 1] == 'C' ) ? 300 : 500;
            }
            else if( s[i] == 'M' )
            {
                result += ( i > 0 && s[i - 1] == 'C' ) ? 800 : 1000;
            }
            else if( s[i] == 'I' )
            {
                result += 1;
            }
        }

        return result;
    }

    // Straightforward approach.
    int romanToInt_v2( string s )
    {

        int result = 0;
        int i = 0;
        for( ; i < s.length(); ++i )
        {
            if( s[i] == 'I' )
            {
                if( s[i + 1] == 'V' )
                {
                    i++;
                    result += 4;
                    continue;
                }
                else if( s[i + 1] == 'X' )
                {
                    i++;
                    result += 9;
                    continue;
                }
                else
                {
                    result += 1;
                }
            }
            else if( s[i] == 'V' )
            {
                result += 5;
            }
            else if( s[i] == 'X' )
            {
                if( s[i + 1] == 'L' )
                {
                    i++;
                    result += 40;
                    continue;
                }
                else if( s[i + 1] == 'C' )
                {
                    i++;
                    result += 90;
                    continue;
                }
                else
                {
                    result += 10;
                }
            }
            else if( s[i] == 'L' )
            {
                result += 50;
            }
            else if( s[i] == 'C' )
            {
                if( s[i + 1] == 'D' )
                {
                    i++;
                    result += 400;
                    continue;
                }
                else if( s[i + 1] == 'M' )
                {
                    i++;
                    result += 900;
                    continue;
                }
                else
                {
                    result += 100;
                }
            }
            else if( s[i] == 'D' )
            {
                result += 500;
            }
            else if( s[i] == 'M' )
            {
                result += 1000;
            }
        }

        /*if( s[i] == 'I' )
        {
            result += 1;
        }
        else if( i == 0 || s[i - 1] != 'I' )
        {
            if( s[i] == 'V' )
            {
                result += 5;
            }
            else if( s[i] == 'X' )
            {
                result += 10;
            }
            else if( s[i] == 'L' )
            {
                result += 50;
            }
            else if( s[i] == 'C' )
            {
                result += 100;
            }
            else if( s[i] == 'D' )
            {
                result += 500;
            }
            else if( s[i] == 'M' )
            {
                result += 1000;
            }
        }*/

        return result;
    }

    // This is concise and more extendable, but Leetcode says it is slower than v2.
    int romanToInt_v3( string s )
    {
        std::map<char, int> table =
        {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 },
            { '0', -1 },
        };

        int sum = 0;
        for( int i = 0; i < s.length(); ++i )
        {
            const int current = table[s[i]];
            const int next = table[s[i + 1]];
            if( current < next )
            {
                sum -= current;
            }
            else
            {
                sum += current;
            }
        }

        return sum;
    }
};

int main()
{
    using namespace std;

    Solution sol;

    std::cout << "isPowerOfThree of 27: " << sol.isPowerOfThree( 27 ) << endl;
    std::cout << "isPowerOfThree of 27: " << sol.isPowerOfThree_v2( 27 ) << endl;
    std::cout << "isPowerOfThree of 1162261467: " << sol.isPowerOfThree( 1162261467 ) << endl;
    std::cout << "isPowerOfThree of 1162261467: " << sol.isPowerOfThree_v2( 1162261467 ) << endl;

    // 3, 58, 1994, 1000
    vector<string> testCaseRoman = { "III", "LVIII", "MCMXCIV", "M" };

    for( auto s : testCaseRoman )
    {
        std::cout << "romanToInt for: " << s << " is " << sol.romanToInt_v2( s ) << endl;
    }
}

