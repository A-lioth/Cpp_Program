#include <iostream>
using namespace std;

const int MAXSIZE = 100;

struct Node
{
    int front, rear;
    int data[MAXSIZE];
};

class SeqQueue
{
private:
    Node *arr;

public:
    SeqQueue()
    {
        arr = new Node;
        arr->front = 0;
        arr->rear = 0;
    }

    bool isEmpty()
    {
        return (arr->front == arr->rear);
    }

    bool isFull()
    {
        return ((arr->rear + 1) % MAXSIZE == arr->front);
    }

    void EnQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        arr->data[arr->rear] = value;
        arr->rear = (arr->rear + 1) % MAXSIZE;
    }

    int DeQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int value = arr->data[arr->front];
        arr->front = (arr->front + 1) % MAXSIZE;
        return value;
    }

    void Output()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = arr->front; i < arr->rear; i++)
        {
            cout << arr->data[i] << " ";
        }
        cout << endl;
    }

    int getSize()
    {
        return (arr->rear - arr->front + MAXSIZE) % MAXSIZE;
    }

    ~SeqQueue()
    {
        delete arr;
        arr = nullptr;
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
                int value;
                cout << "Enter value to enqueue: ";
                cin >> value;
                EnQueue(value);
                break;
            case 2:
                cout << "Dequeued value: " << DeQueue() << endl;
                break;
            case 3:
                Output();
                break;
            case 4:
                cout << "Size of queue: " << getSize() << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
            }
        } while (choice != 5);
    }
};

int main()
{
    SeqQueue queue;
    queue.Menu();
    return 0;
}