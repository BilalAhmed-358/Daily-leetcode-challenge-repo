/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.



Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:

Input: head = [0]
Output: 0



Constraints:

    The Linked List is not empty.
    Number of nodes will not exceed 30.
    Each node's value is either 0 or 1.


*/
#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <typeinfo>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        string s;
        int decimal_value = 0, count = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            count++;
            s += to_string(temp->val);
            temp = temp->next;
        }
        cout << s << endl;
        temp = head;
        int power = count - 1;
        cout << sizeof(s[0]);
        for (int i = 0; i < count; i++)
        {
            if (s[i] == '1')
            {
                decimal_value += pow(2, power);
            }
            power--;
        }
        return decimal_value;
    }
};
int main()
{
}