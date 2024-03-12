#include <iostream>
using namespace std;
#define Datatype int
#define MaxSize 20

class SeqList
{
public:
    void Menu()
    {
        cout << "1.插入" << endl;
        cout << "2.删除" << endl;
        cout << "3.查找" << endl;
        cout << "4.修改" << endl;
        cout << "5.输出" << endl;
        cout << "6.退出" << endl;
    }

    void Init(SeqList &L)
    {
        L.length = 0;
        for (int i = 0; i < MaxSize; i++)
            L.data[i] = 0;
    }

    int Insert(SeqList &L, int pos, Datatype x)
    {
        if (pos < 0 || pos > length + 1)
            return -1;
        for (int i = length; i >= pos - 1; i--)
            data[i + 1] = data[i];
        data[pos - 1] = x;
        length++;
        return 1;
    }

    void Create01()
    {
    }

    void Create02()
    {
    }

    Datatype Search(int pos)
    {
        if (pos >= 0 && pos <= length)
        {
            return data[pos - 1];
        }
        else
            return -1;
    }

    void Output()
    {
        for (int i = 0; i < length; i++)
            cout << data[i] << " ";
        cout << endl;
    }

private:
    Datatype data[MaxSize];
    int length;
};

int main()
{
    SeqList L;
    L.Init(L);
    int ret = L.Insert(L, 1, 1);
    L.Output();

    system("pause");
    return 0;
}
