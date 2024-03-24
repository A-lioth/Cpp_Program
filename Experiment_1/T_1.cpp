#include <iostream>
using namespace std;

const int MaxSize = 5;

// T_1
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

// T_2
typedef struct Node
{
    int data;
    struct Node *next;
} LinkList;

LinkList *CreateLinkList(LinkList *head)
{
    for (int i = 0; i < MaxSize; i++)
    {
        LinkList *p = new LinkList;
        cin >> p->data;
        LinkList *prev = head;
        LinkList *current = head->next;
        while (current != nullptr && current->data < p->data)
        {
            prev = current;
            current = current->next;
        }
        prev->next = p;
        p->next = current;
    }
    return head;
}

void OutputLinkList(LinkList *head)
{
    LinkList *p = head;
    while (p != nullptr)
    {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
}

// T_3
int IsOrdered(LinkList *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return 0;
    }
    LinkList *p = head->next;
    while (p != nullptr && p->next != nullptr)
    {
        if (p->data > p->next->data)
            return -1;
        p = p->next;
    }
    return 1;
}

int main()
{
    // T_1
    //  SeqList L;
    //   CreateSeqList(L);
    //   OutputSeqList(L);
    // T_2
    LinkList L2;
    LinkList *head = new LinkList;
    head->next = nullptr;
    head->data = 0;
    CreateLinkList(head);
    // OutputLinkList(head);
    // T_3
    // cout << IsOrdered(head) << endl;
    system("pause");
    return 0;
}