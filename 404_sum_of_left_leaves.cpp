/*
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.



Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:

Input: root = [1]
Output: 0

*/

#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode *root)
    {
        helper(root, false);
        return sum;
    }
    void helper(TreeNode *root, bool flag)
    {
        int a = 0;
        // cout<<"Got this value of sum from the parent."<<sum<<endl;
        if (root == NULL)
            return;
        // cout<<"Flag is "<<flag<<endl;
        // cout<<"Value is "<<root->val<<endl;
        // cout<<"Sum is "<<sum<<endl;
        if (flag == true && root->left == NULL && root->right == NULL)
        {
            sum += root->val;
            // cout<<sum<<endl;
        }
        helper(root->left, true);
        helper(root->right, false);
    }
};
int main()
{
}