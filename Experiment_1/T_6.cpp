#include <iostream>
using namespace std;

const int MaxSize = 20;

typedef struct
{
    int data[MaxSize];
    int length = 0;
} SeqList;

void Create(SeqList &L, int Data[])
{
    int len = 5;
    for (int i = 0; i < 5; i++)
        L.data[i] = Data[i];
    L.length = len;
}

void Combine(SeqList &L1, SeqList &L2, SeqList &L)
{
    for (int i = 0; i < L1.length; i++)
    {
        L.data[i] = L1.data[i];
    }
    int length = L1.length;
    for (int j = 0; j < L2.length; j++)
    {
        bool found = false;
        for (int i = 0; i < length; i++)
        {
            if (L.data[i] == L2.data[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            L.data[length] = L2.data[j];
            length++;
        }
    }
    L.length = length;
}

void Output(SeqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main()
{
    SeqList L1;
    SeqList L2;
    SeqList L;
    int A[] = {2, 3, 5, 1, 6};
    int B[] = {3, 9, 11, 6, 7};
    Create(L1, A);
    Create(L2, B);
    Combine(L1, L2, L);
    Output(L);

    system("pause");
    return 0;
}
