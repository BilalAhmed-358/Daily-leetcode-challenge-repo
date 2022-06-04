#include <bits/stdc++.h>
/*
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.



Example 1:

Input: nums = [2,1,2]
Output: 5

Example 2:

Input: nums = [1,2,1]
Output: 0



Constraints:

    3 <= nums.length <= 104
    1 <= nums[i] <= 106


*/
using namespace std;

void Printvector(vector<int> &nums);
int largestPerimeter(vector<int> &nums);
int main()
{
    vector<int> nums;
    int side = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> side;
        nums.push_back(side);
    }
    cout << largestPerimeter(nums);
}

int largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int i = 0;
    int a = 0, b = 0, c = 0;
    while ((nums[n - 3 - i] + nums[n - 2 - i]) <= nums[n - 1 - i] && ((nums.size() - i) > 3))
    {
        i++;
    }
    a = nums[n - 3 - i];
    b = nums[n - 2 - i];
    c = nums[n - 1 - i];
    if (a + b > c)
        return a + b + c;
    else
        return 0;
}