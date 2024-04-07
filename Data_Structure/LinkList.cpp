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

    void CreateSortedList(LinkList &L, int MaxSize)
    {
        for (int i = 0; i < MaxSize; i++)
        {
            Node *p = new Node;
            cin >> p->data;
            Node *prev = L.head;
            Node *current = L.head->next;
            while (current != nullptr && current->data < p->data)
            {
                prev = current;
                current = current->next;
            }
            prev->next = p;
            p->next = current;
        }
    }

    void Menu()
    {
        cout << "1.Init" << endl;
        cout << "2.IsEmpty" << endl;
        cout << "3.HeadCreate" << endl;
        cout << "4.TailCreate" << endl;
        cout << "5.Output" << endl;
        cout << "6.Insert" << endl;
        cout << "7.SearchLocate" << endl;
        cout << "8.Delete" << endl;
        cout << "9.Destroy" << endl;
        cout << "10.CreateSortedList" << endl;
        cout << "0.Exit" << endl;
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

void test4()
{
    LinkList L;
    L.Init(L);
    L.CreateSortedList(L, 10);
    L.Output(L);
}

int main()
{
    int input;
    LinkList L;
    do
    {
        L.Menu();
        cout << "请输入功能编号：" << endl;
        cin >> input;
        switch (input)
        {
        case 1:
            L.Init(L);
            break;
        case 2:
            if (L.IsEmpty(L))
                cout << "The list is empty." << endl;
            else
                cout << "The list is not empty." << endl;
            break;
        case 3:
            cout << "请输入头结点个数：" << endl;
            int n;
            cin >> n;
            L.HeadCreate(L, n);
            break;
        case 4:
            cout << "请输入尾结点个数：" << endl;
            int m;
            cin >> m;
            L.TailCreate(L, m);
            break;
        case 5:
            L.Output(L);
            cout << endl;
            break;
        case 6:
            cout << "请输入插入位置：" << endl;
            int pos;
            cin >> pos;
            cout << "请输入插入值：" << endl;
            int val;
            cin >> val;
            L.Insert(L, pos, val);
            break;
        case 7:
            cout << "请输入查找位置：" << endl;
            int pos2;
            cin >> pos2;
            L.SearchLocate(L, pos2);
            break;
        case 8:
            cout << "请输入删除位置：" << endl;
            int pos3;
            cin >> pos3;
            L.Delete(L, pos3);
            break;
        case 9:
            L.Destroy(L);
            break;
        case 10:
            cout << "请输入最大值：" << endl;
            int max;
            cin >> max;
            L.CreateSortedList(L, max);
            break;
        case 0:
            break;
        default:
            cout << "输入错误，请重新输入！" << endl;
            break;
        }
    } while (input != 0);

    system("pause");
    return 0;
}