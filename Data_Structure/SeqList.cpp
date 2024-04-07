#include <iostream>
using namespace std;
#define Datatype int
#define MaxSize 20

Datatype Data[MaxSize] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
class SeqList
{
public:
    void Menu()
    {
        cout << "1.����" << endl;
        cout << "2.ɾ��" << endl;
        cout << "3.����" << endl;
        cout << "4.��λ" << endl;
        cout << "5.������1" << endl;
        cout << "6.������2" << endl;
        cout << "7.�˳�" << endl;
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
        for (int i = L.length; i >= pos - 1; i--)
            L.data[i + 1] = L.data[i];
        L.data[pos - 1] = x;
        L.length++;
        return 1;
    }

    void Create01(SeqList &L)
    {
        cout << "������Ԫ�ظ�����";
        cin >> L.length;
        cout << "������Ԫ�أ�" << endl;
        for (int i = 0; i < length; i++)
        {
            cin >> L.data[i];
        }
        return;
    }

    void Create02(SeqList &L, Datatype Data[])
    {
        //int len = sizeof(Data) / sizeof(Data[0]);
        //cout << len << endl;
        int len = 20;
        for (int i = 0; i < len; i++)
            L.data[i] = Data[i];
        L.length = len;
    }

    Datatype Search(SeqList &L, int pos)
    {
        if (pos >= 0 && pos <= L.length)
            return L.data[pos - 1];
        else
            return -1;
    }

    int Delete(SeqList &L, int pos)
    {
        if (pos < 0 || pos > L.length)
            return -1;
        for (int i = pos; i < L.length; i++)
            L.data[i - 1] = L.data[i];
        length--;
        return 1;
    }

    int Locate(SeqList &L, Datatype x)
    {
        if (L.length == 0)
            return -1;
        for (int i = 0; i < L.length; i++)
            if (L.data[i] == x)
                return i + 1;
        return -1;
    }

    void Output(SeqList &L)
    {
        for (int i = 0; i < L.length; i++)
            cout << L.data[i] << " ";
        cout << endl;
    }

private:
    Datatype data[MaxSize];
    int length;
};

int main()
{
    int input = 0;
    int pos = 0;
    int lot = 0;
    SeqList L;
    L.Init(L);

    do
    {
        L.Menu();
        cout << "������ѡ�";
        cin >> input;
        switch (input)
        {
        case 1:
            Datatype x;
            cout << "������Ҫ�����λ�ã�";
            cin >> pos;
            cout << "������Ҫ�����ֵ��";
            cin >> x;
            L.Insert(L, pos, x);
            L.Output(L);
            break;

        case 2:
            cout << "������Ҫɾ����λ�ã�";
            cin >> pos;
            L.Delete(L, pos);
            L.Output(L);
            break;

        case 3:
            cout << "������Ҫ���ҵ�λ�ã�";
            cin >> pos;
            cout << "���ҵ�Ԫ��Ϊ��" << L.Search(L, pos) << endl;
            break;

        case 4:
            cout << "������Ҫ��λ��Ԫ�أ�";
            cin >> lot;
            cout << "Ԫ�ص�λ��Ϊ��" << L.Locate(L, lot) << endl;
            break;

        case 5:
            L.Create01(L);
            L.Output(L);
            break;

        case 6:
            L.Create02(L, Data);
            L.Output(L);
            break;

        default:
            break;
        }
    } while (input!= 7);

    system("pause");
    return 0;
}
