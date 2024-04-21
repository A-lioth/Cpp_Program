#include <iostream>
using namespace std;

const int parkMax = 3;
const int waitMax = 4;
const int unitPrice = 5;

class SeqStack
{
private:
    int *arr;
    int top;

public:
    SeqStack()
    {
        arr = new int[parkMax];
        top = -1;
    }

    void Output()
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

    bool isElemExist(int val)
    {
        for (int i = 0; i <= top; i++)
        {
            if (arr[i] == val)
            {
                return true;
            }
        }
        return false;
    }

    bool isFull()
    {
        return (top == parkMax - 1);
    }

    int getSize()
    {
        return top + 1;
    }

    bool IsEmpty()
    {
        return (top == -1) ? true : false;
    }

    void Push(int val)
    {
        if (isFull())
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
        arr = nullptr;
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
                cout << "Size of stack: " << getSize() << endl;
                break;
            }
            case 5:
            {
                Output();
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

class SeqQueue
{
private:
    int *arr;
    int front, rear;

public:
    SeqQueue()
    {
        arr = new int[waitMax];
        front = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        return (front == rear);
    }

    bool isFull()
    {
        return ((rear + 1) % waitMax == front);
    }

    void EnQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % waitMax;
    }

    int DeQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % waitMax;
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
        return (rear - front + waitMax) % waitMax;
    }

    ~SeqQueue()
    {
        front = 0;
        rear = 0;
        delete[] arr;
        arr = nullptr;
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

class ParkingLot
{
private:
    SeqStack *parkIdStack;
    SeqStack *parkTimeStack;
    SeqStack *waitIdStack;
    SeqStack *waitTimeStack;
    SeqQueue *waitIdQueue;
    SeqQueue *waitTimeQueue;
    int parkCount;
    int waitCount;

public:
    ParkingLot()
    {
        parkIdStack = new SeqStack;
        parkTimeStack = new SeqStack;
        waitIdStack = new SeqStack;
        waitTimeStack = new SeqStack;
        waitIdQueue = new SeqQueue;
        waitTimeQueue = new SeqQueue;
        parkCount = 0;
        waitCount = 0;
    }

    bool parkIsFull()
    {
        return (parkCount == parkMax);
    }

    bool waitIsFull()
    {
        return (waitCount == waitMax);
    }

    bool isCarInParkingLot(int carId)
    {
        if (parkIdStack->isElemExist(carId))
        {
            cout << "Car " << carId << " is in parking lot!" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    void Park(int carId, int carTime)
    {
        // 停车场没满且没有重复的车
        if (!parkIsFull() && !isCarInParkingLot(carId))
        {
            parkIdStack->Push(carId);
            parkTimeStack->Push(carTime);
            parkCount++;
        }
        // 停车场满，候车厂没满
        else if (!waitIsFull())
        {
            waitIdQueue->EnQueue(carId);
            waitTimeQueue->EnQueue(carTime);
            waitCount++;
        }
        // 停车场满，候车厂满
        else
        {
            cout << "Parking lot is full, please wait!" << endl;
        }
    }

    void Leave(int carId)
    {
        if (parkIdStack->isElemExist(carId))
        {
            // 停车场没车
            if (parkIdStack->IsEmpty())
            {
                cout << "No car in parking lot!" << endl;
                return;
            }
            // 停车场有车且最后一辆车是最后停车的车
            if (carId == parkIdStack->getTop())
            {
                parkPrice(parkIdStack->Pop(), parkTimeStack->Pop());
                parkCount--;
                cout << "Car " << carId << " leaves the parking lot." << endl;
                putwaitQueuetoparkStack();
            }
            // 停车场有车但不是最后一辆车
            else
            {
                int count = 0;
                while (parkIdStack->getTop() != carId)
                {
                    waitIdStack->Push(parkIdStack->Pop());
                    waitTimeStack->Push(parkTimeStack->Pop());
                    parkCount--;
                    count++;
                }
                parkPrice(parkIdStack->Pop(), parkTimeStack->Pop());
                parkCount--;
                cout << "Car " << carId << " leaves the parking lot." << endl;
                while (count > 0)
                {
                    parkIdStack->Push(waitIdStack->Pop());
                    parkTimeStack->Push(waitTimeStack->Pop());
                    parkCount++;
                    count--;
                }
                putwaitQueuetoparkStack();
            }
        }
        else
        {
            cout << "Car " << carId << " is not in parking lot!" << endl;
        }
    }

    void putwaitQueuetoparkStack()
    {
        if (waitCount > 0)
        {
            parkIdStack->Push(waitIdQueue->DeQueue());
            parkTimeStack->Push(waitTimeQueue->DeQueue());
            parkCount++;
            waitCount--;
        }
    }

    void parkPrice(int carId, int carTime)
    {
        // if (parkIdStack->isElemExist(carId))
        {
            cout << "Car " << carId << " parking price: " << carTime * unitPrice << " yuan." << endl;
        }
        // else
        {
            return;
        }
    }

    void showParkingLot()
    {
        if (parkCount < 1)
        {
            cout << "No car in parking lot!" << endl;
            return;
        }
        cout << "Parking lot status:" << endl;
        cout << "Parking lot ID: ";
        parkIdStack->Output();
        cout << "Parking lot time: ";
        parkTimeStack->Output();
    }

    void showWaitLot()
    {
        if (waitCount < 1)
        {
            cout << "No car in waiting lot!" << endl;
            return;
        }
        cout << "Wait lot status:" << endl;
        cout << "Wait lot ID: ";
        waitIdQueue->Output();
        cout << "Wait lot time: ";
        waitTimeQueue->Output();
    }

    ~ParkingLot()
    {
        delete parkIdStack;
        delete parkTimeStack;
        delete waitIdStack;
        delete waitTimeStack;
        delete waitIdQueue;
        delete waitTimeQueue;
        parkCount = 0;
        waitCount = 0;
        parkIdStack = nullptr;
        parkTimeStack = nullptr;
        waitIdStack = nullptr;
        waitTimeStack = nullptr;
        waitIdQueue = nullptr;
        waitTimeQueue = nullptr;
        cout << "Parking lot is destroyed!" << endl;
    }

    void Menu()
    {
        int choice;
        do
        {
            cout << "1. Park" << endl;
            cout << "2. Leave" << endl;
            cout << "3. Parking lot status" << endl;
            cout << "4. Wait lot status" << endl;
            cout << "5. Exit" << endl;

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
                Leave(carId);
                break;
            }
            case 3:
            {
                showParkingLot();
                break;
            }
            case 4:
            {
                showWaitLot();
                break;
            }
            case 5:
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
        } while (choice != 5);
    }
};

int main()
{
    ParkingLot lot;
    lot.Menu();
    return 0;
}
