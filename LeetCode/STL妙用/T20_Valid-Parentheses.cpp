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
        else
        {
            if (sk.empty())
                return false;
            if ((c == ')' && sk.top() == '(') || (c == ']' && sk.top() == '[') || (c == '}' && !sk.empty() && sk.top() == '{'))
                sk.pop();
            else
                return false;
        }
    }
    return sk.empty();
}

int main()
{
    string s = "()[]{}";
    if (isValid(s))
        cout << "Parentheses are valid." << endl;
    else
        cout << "Parentheses are not valid." << endl;
    return 0;
}