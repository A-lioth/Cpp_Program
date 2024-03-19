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

int main()
{
    SeqList L;
    CreateSeqList(L);
    OutputSeqList(L);
    system("pause");
    return 0;
}