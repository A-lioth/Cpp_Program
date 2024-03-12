#include <iostream>
using namespace std;
#define Datatype int

struct LNode
{
    Datatype data;
    LNode* next;
};

class LinkList
{
public:
    void Init()
    {
        head = new LNode;
        head->next = NULL;
        length = 0;
    }
    void Output()
    {
        LNode* p = head->next;
        for (int i = 0; i < length; i++)
        {
            cout << p->data << ',';
            p = p->next;
        }
    }
    void Insert(int pos, int n)
    {
        LNode* s = new LNode;
        s->data = n;
        LNode* p = head->next;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        s->next = p->next;
        p->next = s;
    }

private:
    LNode* head;
    int length;

};


int main()
{
    //LinkList L;
    cout << "hello world" << endl;
    system("pause");
    return 0;
}