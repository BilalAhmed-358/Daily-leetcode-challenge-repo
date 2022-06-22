/*
A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.



Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.



Constraints:

    2 <= arr.length <= 1000
    -106 <= arr[i] <= 106


*/

#include <bits/stdc++.h>

using namespace std;
bool canMakeArithmeticProgression(vector<int> &arr);
void PrintVec(vector<int> vec);
int main()
{
    vector<int> v = {20, 17, -18, -13, 13, -14, -8, 10, 1, 14, -19};
    cout << canMakeArithmeticProgression(v) << endl;
}
bool canMakeArithmeticProgression(vector<int> &arr)
{
    int flag = 0;
    sort(arr.begin(), arr.end());
    // PrintVec(arr);
    if (arr.size() > 2)
    {
        for (int i = 0; i < (arr.size() - 2); i++)
        {
            if (arr[i + 1] - arr[i] == arr[i + 2] - arr[i + 1])
                flag = 1;
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            return true;
        }
        else
            return false;
    }
    else
        return true;
}
void PrintVec(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}