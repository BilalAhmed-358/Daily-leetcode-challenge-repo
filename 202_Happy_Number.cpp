/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.



Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:

Input: n = 2
Output: false



Constraints:

    1 <= n <= 231 - 1


*/
#include <bits/stdc++.h>

using namespace std;

bool isHappy(int n);
int main()
{
    cout << isHappy(19) << endl;
    return 0;
}

bool isHappy(int n)
{
    int s = 0, num = n;
    // cout << "Value of n is " << n << endl;
    vector<int> track;
    while (num < INT_MAX)
    {
        n = num;
        s = 0;
        while (n > 0)
        {
            s += pow(n % 10, 2);
            // cout << "val of s: " << s << endl;
            n /= 10;
        }
        num = s;
        // cout << s << endl;
        vector<int>::iterator it = find(track.begin(), track.end(), s);
        if (s == 1)
        {
            return true;
        }
        else if (it != track.end())
        {
            // cout << "Sequence starting to repeat, aborting operation." << endl;
            return false;
        }
        track.push_back(s);
    }
    return 0;
}