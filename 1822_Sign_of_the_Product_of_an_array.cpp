#include <bits/stdc++.h>

using namespace std;

int arraySign(vector<int> &nums);
int main()
{
    vector<int> vec = {-1, -1, -1, 0, -1};
    cout << arraySign(vec) << endl;
}
int arraySign(vector<int> &nums)
{
    double prod = 1;
    for (int i = 0; i < nums.size(); i++)
        prod *= nums[i];
    if (prod > 0)
        return 1;
    else if (prod < 0)
        return -1;
    else
        return 0;
}