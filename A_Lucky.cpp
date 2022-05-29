/* A. Lucky?
time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output

A ticket is a string consisting of six digits. A ticket is considered lucky if the sum of the first three digits is equal to the sum of the last three digits. Given a ticket, output if it is lucky or not. Note that a ticket can have leading zeroes.
Input

The first line of the input contains an integer t
(1≤t≤103

) — the number of testcases.

The description of each test consists of one line containing one string consisting of six digits.
Output

Output t

lines, each of which contains the answer to the corresponding test case. Output "YES" if the given ticket is lucky, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int first = 0, second = 0, num = 0;
        cin >> num;
        for (int i = 0; i < 6; i++)
        {
            if (i < 3)
            {
                second += (num % 10);
                num /= 10;
            }
            else
            {
                first += (num % 10);
                num /= 10;
            }
        }
        // cout << "second:" << second << endl;
        // cout << "first:" << first << endl;
        if (first == second)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}