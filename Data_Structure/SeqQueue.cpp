#include <iostream>
using namespace std;

const int MAXSIZE = 100;

class SeqQueue
{
private:
    int *arr;
    int front, rear;

public:
    SeqQueue()
    {
        arr = new int[MAXSIZE];
        front = rear = 0;
    }

    bool isEmpty()
    {
        return (front == rear);
    }

    bool isFull()
    {
        return ((rear + 1) % MAXSIZE == front);
    }

    void EnQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % MAXSIZE;
    }

    int DeQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % MAXSIZE;
        return value;
    }

    void Output()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getSize()
    {
        return (rear - front + MAXSIZE) % MAXSIZE;
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
            {
                cout << "Dequeued value: " << DeQueue() << endl;
                break;
            }

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