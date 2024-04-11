#include <iostream>
using namespace std;

// 设有两个栈S1、S2都采用顺序栈方式，并且共享一个存储空间[0, 1,…maxsize - 1]，为了尽量利用空间，减少溢出的可能，可采用栈顶相向，迎面增长的存储方式。试设计S1、S2有关入栈和出栈的操作算法。
// 实验测试数据： S1中的数据元素为：1, 2, 3, 4, 5, 6, 7, 8, 9, 10，S2中的数据元素为：10, 20, 30, 40, 50, 60, 70, 80, 90, 100

const int MAXSIZE = 25;

struct Node
{
    int data[MAXSIZE];
    int top1;
    int top2;
};

class DualStack
{
private:
    Node *S;

public:
    DualStack()
    {
        S = new Node;
        S->top1 = -1;
        S->top2 = MAXSIZE;
    }

    void Push(int val, int stackNumber)
    {
        if (S->top1 + 1 == S->top2)
        {
            cout << "Stack is full\n"
                 << endl;
            return;
        }
        if (stackNumber == 1)
            S->data[++S->top1] = val;
        else if (stackNumber == 2)
            S->data[--S->top2] = val;
    }

    int Pop(int stackNumber)
    {
        int val;
        if (stackNumber == 1)
        {
            if (S->top1 == -1)
                return -1;
            val = S->data[S->top1--];
        }
        else if (stackNumber == 2)
        {
            if (S->top2 == MAXSIZE)
                return -1;
            val = S->data[S->top2++];
        }
        return val;
    }

    void Output()
    {
        for (int i = S->top1; i >= 0; i--)
            cout << S->data[i] << " ";
        cout << endl;
        for (int i = S->top2; i < MAXSIZE; i++)
            cout << S->data[i] << " ";
        cout << endl;
    }

    ~DualStack()
    {
        delete S;
        S = nullptr;
    }

    void Menu()
    {
        int choice;
        do
        {
            cout << "1. Push to S1" << endl;
            cout << "2. Push to S2" << endl;
            cout << "3. Pop from S1" << endl;
            cout << "4. Pop from S2" << endl;
            cout << "5. Output" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                for (int i = 1; i <= 10; i++)
                {
                    Push(i, 1);
                }
                break;
            }
            case 2:
            {
                for (int i = 1; i <= 10; i++)
                {
                    Push(i * 10, 2);
                }
                break;
            }
            case 3:
            {
                for (int i = 0; i < 10; i++)
                {
                    cout << "Pop from S1: " << Pop(1) << endl;
                }
                break;
            }
            case 4:
            {
                for (int i = 0; i < 10; i++)
                {
                    cout << "Pop from S2: " << Pop(2) << endl;
                }
                break;
            }
            case 5:
                Output();
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
        } while (choice != 6);
    }
};

int main()
{
    DualStack ds;
    ds.Menu();

    /*for (int i = 1; i <= 10; i++)
    {
        ds.Push(i, 1);
        // ds.Push(i * 10, 2);
    }

    for (int i = 1; i <= 10; i++)
    {
        cout << "Pop from S1: " << ds.Pop(1) << endl;
        // cout << "Pop from S2: " << ds.Pop(2) << endl;
    }*/

    return 0;
}
