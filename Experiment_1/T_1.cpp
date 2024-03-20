#include <iostream>
using namespace std;

#define MaxSize 5

typedef struct
{
    int data[MaxSize];
    int length = 0;
} SeqList;

void CreateSeqList(SeqList &L)
{
    int i = 0;
    int temp;
    cin >> L.data[0];
    L.length++;
    for (i = 0; i < MaxSize - 1; i++)
    {
        cin >> temp;
        for (int j = i; j > -1; j--)
        {
            if (temp < L.data[j])
            {
                L.data[j + 1] = L.data[j];
                L.data[j] = temp;
            }
            else
            {
                L.data[j + 1] = temp;
                break;
            }
        }
        L.length++;
    }
}

void OutputSeqList(SeqList &L)
{
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}

typedef struct Node
{
    int data;
    struct Node *next;
    int length = 0;
} LinkList;

void CreateLinkList(LinkList *&head)
{
    LinkList *q = new LinkList;
    q->next = NULL;
    head->next = q; // 将头指针指向第一个节点
    cin >> q->data;
    LinkList *r = head->next;
    for (int i = 0; i < MaxSize - 1; i++)
    {
        LinkList *p = new LinkList;
        p->next = NULL;
        cin >> p->data;
        r = head;
        while (!r)
        {
            if (p->data < r->data)
            {
                p->next = r->next;
                r->next = p;
            }
            else
            {
                r = r->next;
            }
        }

        p = NULL;

        head->length++; // 更新头指针的
    }
}

void OutputLinkList(LinkList &L, LinkList *head)
{
    LinkList *p = head;
    while (p != NULL)
    {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 随机输入一组数，创建一个元素递增有序的单链表
int main()
{
    //SeqList L;
    // CreateSeqList(L);
    // OutputSeqList(L);
    LinkList L2;
    LinkList *head = new LinkList;
    head->next = NULL;
    head->length = 0;
    head->data = 0;
    CreateLinkList(head);
    OutputLinkList(L2, head);
    system("pause");
    return 0;
}