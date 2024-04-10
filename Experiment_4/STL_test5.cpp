#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// 已知Q是一个非空队列，S是一个空栈。仅用队列和栈的基本操作和少量的工作变量，编写一个算法，将队列Q中的所有元素逆置。队列元素为: （1, 3, 6, 10, 15, 16, 17, 18, 19, 20）
int main()
{
    queue<int> Q;
    Q.push(1);
    Q.push(3);
    Q.push(6);
    Q.push(10);
    Q.push(15);
    Q.push(16);
    Q.push(17);
    Q.push(18);
    Q.push(19);
    Q.push(20);

    stack<int> S;
    while (!Q.empty())
    {
        S.push(Q.front());
        Q.pop();
    }

    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
    cout << endl;

    return 0;
}
