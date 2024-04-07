#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkStack
{
private:
    Node *top;

public:
    LinkStack()
    {
        top = nullptr;
    };

    ~LinkStack()
    {

        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    };

    bool isEmpty()
    {
        return (top == nullptr) ? true : false;
    };

    void push(int data)
    {
        Node *p = new Node;
        p->data = data;
        p->next = top;
        top = p;
    };

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int data = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return data;
    };

    int getTop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return top->data;
    };

    void Output()
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    };

    int getSize()
    {
        int size = 0;
        Node *temp = top;
        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        return size;
    };

    void Menu()
    {
        int choice;
        do
        {
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Peek" << endl;
            cout << "4. Is Empty" << endl;
            cout << "5. Output" << endl;
            cout << "6. Get Size" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                int data;
                cout << "Enter data to push: ";
                cin >> data;
                push(data);
                break;
            }
            case 2:
            {
                int data = pop();
                if (data != -1)
                {
                    cout << "Popped data: " << data << endl;
                }
                break;
            }
            case 3:
            {
                int data = getTop();
                if (data != -1)
                {
                    cout << "Top data: " << data << endl;
                }
                break;
            }
            case 4:
            {
                if (isEmpty())
                {
                    cout << "Stack is empty" << endl;
                }
                else
                {
                    cout << "Stack is not empty" << endl;
                }
                break;
            }
            case 5:
            {
                Output();
                break;
            }
            case 6:
            {
                int size = getSize();
                cout << "Size of stack: " << size << endl;
                break;
            }
            case 7:
            {
                break;
            }
            default:
            {
                cout << "Invalid choice" << endl;
                break;
            }
            }
        } while (choice != 7);
    }
};

int main()
{
    LinkStack s;
    s.Menu();
    return 0;
}