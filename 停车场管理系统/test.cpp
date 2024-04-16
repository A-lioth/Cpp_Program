#include <iostream>
using namespace std;

const int parkMax = 2;
const int waitMax = 2;
const int unitPrice = 5;

class SeqStack
{
private:
    int *arr;
    int *parkTime;
    int top;

public:
    SeqStack()
    {
        arr = new int[parkMax];
        parkTime = new int[parkMax];
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
        if (top == parkMax - 1)
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
        delete[] parkTime;
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
        return (front == rear);
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
        front = rear = nullptr;
        cout << "Queue is destroyed!" << endl;
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
                cout << "Dequeued value: " << DeQueue() << endl;
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

struct CarInfo
{
    int carId[parkMax];
    int carTime[parkMax];
};

class ParkingLot
{
private:
    SeqStack *parkStack;
    SeqStack *waitStack;
    LinkQueue *waitQueue;
    CarInfo c;
    int parkCount;

public:
    ParkingLot()
    {
        parkStack = new SeqStack;
        waitStack = new SeqStack;
        waitQueue = new LinkQueue;
        for (int i = 0; i < parkMax; i++)
        {
            c.carId[i] = -1;
            c.carTime[i] = -1;
        }
        parkCount = 0;
    }

    bool parkisFull()
    {
        return (parkCount == parkMax);
    }

    bool waitisFull()
    {
        return (waitQueue->getSize() == waitMax);
    }

    void Park(int carId, int carTime)
    {
        // 停车场没满
        if (!parkisFull())
        {
            parkStack->Push(carId);
            c.carId[parkCount] = carId;
            c.carTime[parkCount] = carTime;
            parkCount++;
        }
        // 停车场满，候车厂没满
        else if (!waitisFull())
        {
            waitQueue->EnQueue(carId);
        }
        // 停车场满，候车厂满
        else
        {
            cout << "Parking lot is full, please wait!" << endl;
        }
    }

    void Leave(int carId)
    {
        // 停车场没车
        if (parkStack->IsEmpty())
        {
            cout << "No car in parking lot!" << endl;
            return;
        }
        // 停车场有车且最后一辆车是最后停车的车
        if (carId == parkStack->getTop())
        {
            parkStack->Pop();
            parkCount--;
            cout << "Car " << carId << " has left the parking lot." << endl;
            putwaitQueuetoparkStack();
        }
        // 停车场有车但不是最后一辆车
        else
        {
            int index = -1;
            for (int i = 0; i < parkCount; i++)
            {
                if (c.carId[i] == carId)
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
            {
                cout << "Car " << carId << " is not in the parking lot!" << endl;
                return;
            }
            // 将parkStack中从index开始的车暂时放入waitStack
            for (int i = index; i < parkCount - 1; i++)
            {
                waitStack->Push(c.carId[i]);
                c.carId[i] = -1;
                c.carTime[i] = -1;
            }
            parkStack->Pop();
            parkCount--;
            cout << "Car " << carId << " has left the parking lot." << endl;
            // 将waitStack中的车放回parkStack
            for (int i = 0; !waitStack->IsEmpty(); i++)
            {
                parkStack->Push(waitStack->Pop());
            }
            // 将parkStack中后面的车前移
            // moveCar(index);
            putwaitQueuetoparkStack();
        }
    }

    // 将空位后面的车前移
    void moveCar(int index)
    {
        for (int i = index; i < parkCount - 1; i++)
        {
            c.carId[i] = c.carId[i + 1];
            c.carTime[i] = c.carTime[i + 1];
        }
        c.carId[parkCount - 1] = -1;
        c.carTime[parkCount - 1] = -1;
    }

    void putwaitQueuetoparkStack()
    {
        while (!parkisFull() && !waitQueue->isEmpty())
        {
            parkStack->Push(waitQueue->DeQueue());
        }
    }

    int parkPrice(int carId)
    {
        int price = 0;
        bool carExists = false;
        for (int i = 0; i < parkCount; i++)
        {
            if (c.carId[i] == carId)
            {
                price = unitPrice * c.carTime[i];
                carExists = true;
                break;
            }
        }
        if (!carExists)
        {
            cout << "Car " << carId << " is not in the parking lot!" << endl;
            return -1;
        }
        return price;
    }

    void Menu()
    {
        int choice;
        do
        {
            cout << "1. Park" << endl;
            cout << "2. Leave" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                int carId, carTime;
                cout << "Enter car ID: ";
                cin >> carId;
                cout << "Enter car time: ";
                cin >> carTime;
                Park(carId, carTime);
                break;
            }
            case 2:
            {
                int carId;
                cout << "Enter car ID: ";
                cin >> carId;
                if (parkPrice(carId) != -1)
                {
                    cout << "Car " << carId << " pays " << parkPrice(carId) << " yuan." << endl;
                }
                Leave(carId);
                break;
            }
            case 3:
            {
                cout << "Exiting..." << endl;
                break;
            }
            default:
            {
                cout << "Invalid choice!" << endl;
                break;
            }
            }
        } while (choice != 3);
    }
};

int main()
{
    ParkingLot lot;
    lot.Menu();
    return 0;
}
