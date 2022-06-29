/*
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.



Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.



Constraints:

    1 <= arr.length <= 500
    0 <= arr[i] <= 104


*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<pair<int, int>> count;
        int one_count = 0;
        vector<int> temp = arr;
        for (int i = 0; i < arr.size(); i++)
        {
            one_count = 0;
            // cout<<"Checking "<<temp[i]<<endl;
            for (int j = 0; j < 32; j++)
            {
                if ((temp[i] & 1) == 1)
                {
                    one_count++;
                }
                temp[i] = temp[i] >> 1;
            }
            // cout<<one_count<<endl;
            count.push_back(make_pair(one_count, arr[i]));
        }
        sort(count.begin(), count.end());
        // Printvecpair(count);
        for (int i = 0; i < temp.size(); i++)
            temp[i] = count[i].second;
        return temp;
    }
    void Printvecpair(vector<pair<int, int>> vec)
    {
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i].first << " " << vec[i].second << endl;
    }
};
int main()
{
}