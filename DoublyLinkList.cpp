#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkList
{
private:
    Node *head;

public:
    DoublyLinkList()
    {
        head = nullptr;
    }

    // ��ӽ�㵽˫����
    void appendNode(int value)
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

    // ��ȡ˫�����еĽ������
    int getNodeCount()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void swapLastTwoNodes()
    {
        if (head == nullptr || head->next == nullptr)
        {
            std::cout << "˫�������������㣬�޷����н�������" << std::endl;
            return;
        }

        Node *secondLast = head;
        Node *last = head->next;

        while (last->next != nullptr)
        {
            secondLast = last;
            last = last->next;
        }

        // ���������������λ��
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
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkList L;
    L.appendNode(1);
    L.appendNode(2);
    L.appendNode(3);

    cout << "˫�����еĽ������: " << L.getNodeCount() << endl;
    L.printList();

    L.swapLastTwoNodes();
    cout << "�������˫����: ";
    L.printList();

    system("pause");
    return 0;
}
