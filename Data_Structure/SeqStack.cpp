
#include <iostream>
using namespace std;
const int MAXSIZE = 100;

class SeqStack
{
private:
    int *arr;
    int top;

public:
    SeqStack()
    {
        arr = new int[MAXSIZE];
        top = -1;
    }

    void Outout()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void getSize()
    {
        cout << "Size of stack: " << top + 1 << endl;
    }

    bool IsEmpty()
    {
        return (top == -1) ? true : false;
    }

    void Push(int val)
    {
        if (top == MAXSIZE - 1)
        {
            cout << "Stack is full!" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    int Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int val = arr[top];
        top--;
        return val;
    }

    int getTop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    ~SeqStack()
    {
        top = -1;
        delete[] arr;
        cout << "Stack is destroyed!" << endl;
    }

    void Menu()
    {
        int choice;
        do
        {
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Get top" << endl;
            cout << "4. Get size" << endl;
            cout << "5. Output" << endl;
            cout << "6. Is empty" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                int val;
                cout << "Enter value to push: ";
                cin >> val;
                Push(val);
                break;
            }
            case 2:
            {
                Pop();
                break;
            }
            case 3:
            {
                cout << "Top element: " << getTop() << endl;
                break;
            }
            case 4:
            {
                getSize();
                break;
            }
            case 5:
            {
                Outout();
                break;
            }
            case 6:
            {
                IsEmpty();
                break;
            }
            case 7:
            {
                break;
            }
            default:
            {
                cout << "Invalid choice!" << endl;
                break;
            }
            }
        } while (choice != 7);
    }
};

int main()
{
    SeqStack s;
    s.Menu();
    return 0;
}