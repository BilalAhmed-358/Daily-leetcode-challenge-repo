/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false



Constraints:

    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        bool status = true;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != t[i])
            {
                status = false;
                break;
            }
        return status;
    }
};
int main()
{
}