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
    void Init(LinkList &L)
    {
        L.head = new Node;
        L.head->next = nullptr;
    }

    int IsEmpty(LinkList &L)
    {
        if (L.head->next == nullptr)
            return 1;
        else
            return 0;
    }

    void HeadCreate(LinkList &L, int n)
    {
        Node *Thead = L.head;
        Thead->data = 0;
        Thead->next = nullptr;
        for (int i = 0; i < n; i++)
        {
            Node *s = new Node;
            s->data = i;
            s->next = Thead->next;
            Thead->next = s;
        }
    }

    void TailCreate(LinkList &L, int n)
    {
        Node *Thead = L.head;
        Node *Ttail = Thead;
        Thead->data = 0;
        Thead->next = nullptr;
        for (int i = 0; i < n; i++)
        {
            Node *s = new Node;
            s->data = i;
            s->next = nullptr;
            Ttail->next = s;
            Ttail = s;
        }
        Ttail->next = nullptr;
    }

    void Output(LinkList &L)
    {
        Node *p = L.head->next;
        while (p != nullptr)
        {
            cout << p->data << ' ';
            p = p->next;
        }
    }

    void Insert(LinkList &L, int pos, int n)
    {
        if (pos < 1)
        {
            return;
        }
        Node *s = new Node;
        s->data = n;
        s->next = nullptr;

        Node *p = L.head;
        for (int i = 0; i < pos - 1 && p != nullptr; i++)
        {
            p = p->next;
        }

        if (p == nullptr)
        {
            // 处理插入位置超出链表长度的情况
            delete s; // 释放新节点的内存
            return;
        }

        s->next = p->next;
        p->next = s;
    }

    void SearchLocate(LinkList &L, int pos)
    {
        if (pos < 1)
        {
            cout << "The position is invalid." << endl;
            return;
        }

        Node *p = L.head->next;
        for (int i = 0; i < pos - 1 && p != nullptr; i++)
        {
            p = p->next;
        }

        if (p == nullptr)
        {
            cout << "The position is out of range." << endl;
            return;
        }
        cout << p->data << endl;
    }

    void Delete(LinkList &L, int pos)
    {
        if (IsEmpty(L))
        {
            cout << "The list is empty." << endl;
            return;
        }
        Node *p = L.head->next;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        Node *q = p->next;
        p->next = q->next;
        delete q;
    }

    void Destroy(LinkList &L)
    {
        Node *p = L.head->next;
        while (p != nullptr)
        {
            Node *q = p;
            p = p->next;
            delete q;
        }
        delete L.head;
        L.head = nullptr;
    }

private:
    Node *head;
};

void test()
{
    LinkList L;
    L.Init(L);
    L.Insert(L, 1, 10);
    L.Insert(L, 2, 20);
    L.Output(L);
    L.Delete(L, 1);
    L.Output(L);
}

void test2()
{
    LinkList L;
    L.Init(L);
    L.TailCreate(L, 10);
    L.Output(L);
    L.HeadCreate(L, 5);
    L.Output(L);
    L.Destroy(L);
    L.Output(L); // 输出空链表
}

void test3()
{
    LinkList L;
    L.Init(L);
    L.Insert(L, 1, 10);
    L.Insert(L, 2, 20);
    L.SearchLocate(L, 2);
}

int main()
{
    test2();
    system("pause");
    return 0;
}