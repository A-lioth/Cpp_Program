#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkList
{
private:
    Node *head;

public:
    LinkList()
    {
        head = new Node;
        head->data = 0;
        head->next = nullptr;
    }

    bool IsEmpty()
    {
        return head->next == nullptr;
    }

    void HeadCreate(int val)
    {
        Node *s = new Node;
        s->data = val;
        s->next = head->next;
        head->next = s;
    }

    void TailCreate(int val)
    {
        Node *s = new Node;
        s->data = val;
        s->next = nullptr;

        Node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = s;
    }

    void Output()
    {
        Node *p = head->next;
        while (p != nullptr)
        {
            cout << p->data << ' ';
            p = p->next;
        }
        cout << endl;
    }

    void Insert(int pos, int val)
    {
        if (pos < 1)
        {
            return;
        }
        Node *s = new Node;
        s->data = val;
        s->next = nullptr;

        Node *p = head;
        for (int i = 0; i < pos - 1 && p != nullptr; i++)
        {
            p = p->next;
        }

        if (p == nullptr)
        {
            delete s;
            return;
        }
        s->next = p->next;
        p->next = s;
    }

    void SearchLocate(int pos)
    {
        if (pos < 1)
        {
            cout << "The position is invalid." << endl;
            return;
        }

        Node *p = head->next;
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

    void Delete(int pos)
    {
        if (IsEmpty())
        {
            cout << "The list is empty." << endl;
            return;
        }
        Node *p = head;
        for (int i = 0; i < pos - 1 && p != nullptr; i++)
        {
            p = p->next;
        }

        if (p->next == nullptr)
        {
            cout << "The position is out of range." << endl;
            return;
        }

        Node *q = p->next;
        p->next = q->next;
        delete q;
    }

    void CreateSortedList(int MaxSize)
    {
        for (int i = 0; i < MaxSize; i++)
        {
            Node *s = new Node;
            cin >> s->data;
            Node *prev = head;
            Node *current = head->next;
            while (current != nullptr && current->data < s->data)
            {
                prev = current;
                current = current->next;
            }
            prev->next = s;
            s->next = current;
        }
    }

    ~LinkList()
    {
        Node *p = head->next;
        while (p != nullptr)
        {
            Node *q = p;
            p = p->next;
            delete q;
        }
        delete head;
    }

    void Menu()
    {
        int choice;
        do
        {
            cout << "1. Create a head list" << endl;
            cout << "2. Create a tail list" << endl;
            cout << "3. Output the list" << endl;
            cout << "4. Insert a node" << endl;
            cout << "5. Search a node" << endl;
            cout << "6. Delete a node" << endl;
            cout << "7. Create a sorted list" << endl;
            cout << "0. Exit" << endl;
            cout << "Please enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                int n;
                cout << "Enter the number of nodes: ";
                cin >> n;
                HeadCreate(n);
                break;
            }
            case 2:
            {
                int n;
                cout << "Enter the number of nodes: ";
                cin >> n;
                TailCreate(n);
                break;
            }
            case 3:
            {
                Output();
                break;
            }
            case 4:
            {
                int pos, n;
                cout << "Enter the position to insert: ";
                cin >> pos;
                cout << "Enter the value to insert: ";
                cin >> n;
                Insert(pos, n);
                break;
            }
            case 5:
            {
                int pos;
                cout << "Enter the position to search: ";
                cin >> pos;
                SearchLocate(pos);
                break;
            }
            case 6:
            {
                int pos;
                cout << "Enter the position to delete: ";
                cin >> pos;
                Delete(pos);
                break;
            }
            case 7:
            {
                int MaxSize;
                cout << "Enter the maximum size of the list: ";
                cin >> MaxSize;
                CreateSortedList(MaxSize);
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                cout << "Invalid choice." << endl;
                break;
            }
            }
        } while (choice != 0);
    }
};

int main()
{
    LinkList L;
    L.Menu();
    return 0;
}