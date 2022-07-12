/*
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).



Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 20
    order.length == 26
    All characters in words[i] and order are English lowercase letters.


*/

// Uncomment the cout statements to understand the working of the program

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int order_alphabets[26];
        for (int i = 0; i < 26; i++)
        {
            order_alphabets[order[i] - 'a'] = i;
        }

        // for(int i=0;i<26;i++)
        // {
        //     cout<<char(97+i)<<" "<<order_alphabets[i]<<endl;
        // }
        // cout << "Total words to check " << words.size() << endl;

        for (int i = 0; i < words.size() - 1; i++)
        {
            string s1 = words[i], s2 = words[i + 1];
            if (s1.size() >= s2.size())
            {
                // cout << "First case running." << endl;
                for (int j = 0; j < s1.size(); j++)
                {
                    if (j == s2.size())
                    {
                        // cout << "Size of s2 reached (returning true bcoz ""apple"">""app"")"<< endl;
                        return false;
                    }
                    // cout << "checking " << s1[j] << "=" << order_alphabets[int(s1[j] - 'a')] << " and " << s2[j] << "=" << order_alphabets[int(s2[j] - 'a')] << endl;
                    if (order_alphabets[int(s1[j] - 'a')] == order_alphabets[int(s2[j] - 'a')])
                    {
                        continue;
                    }

                    else if (order_alphabets[int(s1[j] - 'a')] < order_alphabets[int(s2[j] - 'a')])
                    {
                        // cout << "Everything normal." << endl;
                        break;
                    }
                    else if (order_alphabets[int(s1[j] - 'a')] > order_alphabets[int(s2[j] - 'a')])
                    {
                        // cout << "Lexical order voilated." << endl;
                        return false;
                    }
                }
            }
            else
            {
                // cout << "Second case running." << endl;
                for (int j = 0; j < s2.size(); j++)
                {
                    if (j == s1.size())
                    {
                        // cout << "Size of s1 reached (returning true bcoz ""app""<""apple"")"<< endl;
                        return true;
                    }
                    // cout << "checking " << s1[j] << "=" << order_alphabets[int(s1[j] - 'a')] << " and " << s2[j] << "=" << order_alphabets[int(s2[j] - 'a')]<< endl;

                    if (order_alphabets[int(s1[j] - 'a')] == order_alphabets[int(s2[j] - 'a')])
                    {
                        continue;
                    }

                    else if (order_alphabets[int(s1[j] - 'a')] < order_alphabets[int(s2[j] - 'a')])
                    {
                        // cout << "Everything normal." << endl;
                        break;
                    }
                    else if (order_alphabets[int(s1[j] - 'a')] > order_alphabets[int(s2[j] - 'a')])
                    {
                        // cout << "Lexical order voilated." << endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
int main()
{
}