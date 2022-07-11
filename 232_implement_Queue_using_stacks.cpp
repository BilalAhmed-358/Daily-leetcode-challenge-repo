/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.



Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false



Constraints:

    1 <= x <= 9
    At most 100 calls will be made to push, pop, peek, and empty.
    All the calls to pop and peek are valid.

*/
#include <bits/stdc++.h>

using namespace std;
// You can uncomment the cout statements to see how the program popping and pushing values.
class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        // cout<<"In the pop function currently."<<endl;
        while (!s1.empty())
        {
            s2.push(s1.top());
            // cout<<s1.top()<<endl;
            s1.pop();
        }
        int queue_pop = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            // cout<<s2.top()<<endl;
            s2.pop();
        }
        return queue_pop;
    }

    int peek()
    {
        // cout<<"In the peek function currently."<<endl;
        while (!s1.empty())
        {
            s2.push(s1.top());
            // cout<<s1.top()<<endl;
            s1.pop();
        }
        int a = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            // cout<<s2.top()<<endl;
            s2.pop();
        }
        return a;
    }

    bool empty()
    {
        if (s1.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main()
{
}