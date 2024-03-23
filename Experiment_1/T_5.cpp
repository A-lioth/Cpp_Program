#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkList
{

public:
    Node *head1;
    Node *head2;
    LinkList()
    {
        head1 = nullptr;
        head2 = nullptr;
    }

    void Insert(int value)
    {
        Node *p = new Node;
        p->data = value;
        p->next = nullptr;

        if (value % 2 == 0)
        {
            if (head1 == nullptr)
            {
                head1 = p;
            }
            else
            {
                Node *temp = head1;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = p;
            }
        }
        else
        {
            if (head2 == nullptr)
            {
                head2 = p;
            }
            else
            {
                Node *temp = head2;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = p;
            }
        }
    }

    void Output(Node *head)
    {
        Node *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void Separate(LinkList &A, LinkList &B)
    {
        Node *p = head1;
        while (p != nullptr)
        {
            A.Insert(p->data);
            p = p->next;
        }

        p = head2;
        while (p != nullptr)
        {
            B.Insert(p->data);
            p = p->next;
        }
    }
};

int main()
{
    LinkList L;
    L.Insert(2);
    L.Insert(2);
    L.Insert(3);
    L.Insert(4);
    L.Insert(5);

    LinkList evenList;
    LinkList oddList;

    L.Separate(evenList, oddList);

    cout << "A单链表（偶数结点）: ";
    L.Output(evenList.head1);
    cout << "B单链表（奇数结点）: ";
    L.Output(oddList.head2);

    system("pause");

    return 0;
}
