/*
You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.



Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".

Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"

Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"



Constraints:

    1 <= command.length <= 100
    command consists of "G", "()", and/or "(al)" in some order.


*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string interpret(string command)
    {
        string ans;
        for (int i = 0; i < command.size(); i++)
        {

            if (command[i] == '(' && command[i + 1] == 'a' && command[i + 2] == 'l' && command[i + 3] == ')')
            {
                // cout << "(al) detected" << endl;
                ans += "al";
                // cout << ans << endl;
                i += 3;
            }
            else if (command[i] == '(' && command[i + 1] == ')')
            {
                // cout << "() detected" << endl;
                ans += 'o';
                // cout << ans << endl;
                i++;
            }
            else if (command[i] == 'G')
            {
                // cout << "G detected" << endl;
                ans += 'G';
                // cout << ans << endl;
            }
        }
        return ans;
    }
};
int main()
{
    cout << "Its working.\n";
}