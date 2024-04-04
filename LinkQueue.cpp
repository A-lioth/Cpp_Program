#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkQueue
{
private:
    Node *front, *rear;

public:
    LinkQueue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return (front == rear) ? true : false;
    }

    void EnQueue(int val)
    {
        Node *s = new Node;
        s->data = val;
        s->next = nullptr;
        if (rear == nullptr)
        {
            front = rear = s;
            return;
        }
        rear->next = s;
        rear = s;
    }

    int DeQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int val = front->data;
        Node *p = front;
        front = front->next;
        delete p;
        return val;
    }

    void Output()
    {
        Node *p = front;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    int getSize()
    {
        int size = 0;
        Node *p = front;
        while (p != nullptr)
        {
            size++;
            p = p->next;
        }
        return size;
    }

    ~LinkQueue()
    {
        Node *p = front;
        while (p != nullptr)
        {
            Node *q = p;
            p = p->next;
            delete q;
        }
    }

    void Menu()
    {
        int choice;
        do
        {
            cout << "1. Enqueue" << endl;
            cout << "2. Dequeue" << endl;
            cout << "3. Output" << endl;
            cout << "4. Size" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                int val;
                cout << "Enter value to enqueue: ";
                cin >> val;
                EnQueue(val);
                break;
            }
            case 2:
            {
                int val = DeQueue();
                if (val != -1)
                {
                    cout << "Dequeued value: " << val << endl;
                }
                break;
            }
            case 3:
            {
                Output();
                break;
            }
            case 4:
            {
                cout << "Size of queue: " << getSize() << endl;
                break;
            }
            case 5:
            {
                cout << "Exiting..." << endl;
                break;
            }
            default:
            {
                cout << "Invalid choice" << endl;
                break;
            }
            }
        } while (choice != 5);
    }
};

int main()
{
    LinkQueue q;
    q.Menu();
    return 0;
}