#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> sk;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            sk.push(c);

        else if (c == ')' && !sk.empty() && sk.top() == '(')
            sk.pop();

        else if (c == ']' && !sk.empty() && sk.top() == '[')
            sk.pop();

        else if (c == '}' && !sk.empty() && sk.top() == '{')
            sk.pop();
        else
            return false;
    }
    return sk.empty();
}

int main()
{
    string s = "()[]{}";
    cout << isValid(s) << endl; 
    return 0;
}