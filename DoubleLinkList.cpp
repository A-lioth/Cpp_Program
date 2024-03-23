#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DoubleLinkList
{
private:
    Node *head;

public:
    DoubleLinkList()
    {
        head = nullptr;
    }

    void CreateNode(int value)
    {
        Node *p = new Node;
        p->data = value;
        p->next = nullptr;

        if (head == nullptr)
        {
            p->prev = nullptr;
            head = p;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = p;
            p->prev = temp;
        }
    }

    void swapLastTwoNodes()
    {
        if (head == nullptr || head->next == nullptr)
        {
            cout << "双链表结点数量不足，无法进行交换操作" << endl;
            return;
        }

        Node *secondLast = head;
        Node *last = head->next;

        while (last->next != nullptr)
        {
            secondLast = last;
            last = last->next;
        }

        // 交换最后两个结点的位置
        Node *tempPrev = secondLast->prev;
        Node *tempNext = last->next;

        secondLast->prev = last;
        secondLast->next = tempNext;

        last->prev = tempPrev;
        last->next = secondLast;

        if (tempNext != nullptr)
        {
            tempNext->prev = secondLast;
        }
        if (tempPrev != nullptr)
        {
            tempPrev->next = last;
        }
    }

    void printList()
    {
        Node *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    DoubleLinkList L;
    L.CreateNode(1);
    L.CreateNode(2);
    L.CreateNode(3);
    L.printList();
    L.swapLastTwoNodes();
    cout << "交换后的双链表: ";
    L.printList();

    system("pause");
    return 0;
}
