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

    // 添加结点到双链表
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

    // 获取双链表中的结点数量
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
            std::cout << "双链表结点数量不足，无法进行交换操作" << std::endl;
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

    cout << "双链表中的结点数量: " << L.getNodeCount() << endl;
    L.printList();

    L.swapLastTwoNodes();
    cout << "交换后的双链表: ";
    L.printList();

    system("pause");
    return 0;
}
