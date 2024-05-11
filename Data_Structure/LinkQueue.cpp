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
        return front == nullptr;
    }

    void EnQueue(int val)
    {
        Node *s = new Node;
        s->data = val;
        s->next = nullptr;
        if (front == nullptr)
        {
            front = rear = s;
        }
        else
        {
            rear->next = s;
            rear = s;
        }
    }

    void DeQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *p = front;
        int val = p->data;
        cout << "Dequeued value: " << val << endl;
        front = front->next;
        delete p;
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
       while (!isEmpty())
       {
           Node *p = front;
           front = front->next;
           delete p;
       }
       front = rear = nullptr;
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
                DeQueue();
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