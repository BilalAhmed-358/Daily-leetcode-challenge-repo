/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.



Constraints:

    1 <= nums1.length <= nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 104
    All integers in nums1 and nums2 are unique.
    All the integers of nums1 also appear in nums2.

*/
#include <bits/stdc++.h>

using namespace std;
void PrintVec(vector<int> vec);
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2);
int main()
{
    vector<int> vec[2];
    vector<int> ans;
    vec[0] = {1, 3, 5, 2, 4};
    vec[1] = {6, 5, 4, 3, 2, 1, 7};
    ans = nextGreaterElement(vec[0], vec[1]);
    PrintVec(ans);
}
void PrintVec(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    bool flag = false;
    for (int i = 0; i < nums1.size(); i++)
    {
        int element = nums1[i];
        flag = false;
        for (int j = 0; j < nums2.size(); j++)
        {
            if (element == nums2[j])
            {
                for (int k = j + 1; k < nums2.size(); k++)
                {
                    if (element < nums2[k])
                    {
                        ans.push_back(nums2[k]);
                        flag = true;
                        break;
                    }
                }
            }
            if (flag == true)
                break;
        }
        if (flag == false)
            ans.push_back(-1);
    }
    return ans;
}