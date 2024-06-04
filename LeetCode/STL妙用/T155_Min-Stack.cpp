#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
public:
    stack<int> s, min_s;
    MinStack()
    {
    }

    void push(int x)
    {
        s.push(x);
        if (min_s.empty() || x <= min_s.top())
            min_s.push(x);
    }

    void pop()
    {
        if (s.top() == min_s.top())
            min_s.pop();
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min_s.top();
    }
};