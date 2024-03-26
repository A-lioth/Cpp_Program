#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    string phone;
    Node *next;
};

class Contact
{
private:
    Node *head;
    string name;
    string phone;
    int count;

public:
    void Init(Contact &con)
    {
        con.head = new Node;
        con.head->name = "";
        con.head->phone = "";
        con.head->next = NULL;
        con.count = 0;
    }

    void Display(Contact &con)
    {
        Node *temp = con.head->next;
        while (temp != NULL)
        {
            cout << "Name: " << temp->name << endl;
            cout << " Phone: " << temp->phone << endl;
            temp = temp->next;
        }
    }

    void Insert(Contact &con, string name, string phone)
    {
        Node *newNode = new Node;
        newNode->name = name;
        newNode->phone = phone;
        newNode->next = con.head->next;
        con.head->next = newNode;
        con.count++;
        cout << "Contact added successfully." << endl;
    }

    void Delete(Contact &con, string name)
    {
        Node *temp = con.head;
        Node *prev = NULL;
        while (temp != NULL && temp->name != name)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Contact not found." << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
        con.count--;
        cout << "Contact deleted successfully." << endl;
    }

    void Search(Contact &con, string name)
    {
        Node *temp = con.head->next;
        while (temp != NULL && temp->name != name)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Contact not found." << endl;
            return;
        }
        cout << "Name: " << temp->name << " Phone: " << temp->phone << endl;
    }

    void Destroy(Contact &con)
    {
        Node *temp = con.head;
        while (temp != NULL)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        con.count = 0;
        cout << "Contact destroyed successfully." << endl;
    }

    void Menu()
    {
        cout << "1. Init" << endl;
        cout << "2. Display" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Search" << endl;
        cout << "6. Destroy" << endl;
        cout << "0. Exit" << endl;
    }
};

int main()
{
    Contact con;
    int input;
    do
    {
        con.Menu();
        cout << "Enter your choice: ";
        cin >> input;
        switch (input)
        {
        case 1:
            con.Init(con);
            break;

        case 2:
            con.Display(con);
            break;

        case 3:
        {
            cout << "Enter name and phone number: ";
            string name, phone;
            cin >> name >> phone;
            con.Insert(con, name, phone);
            break;
        }

        case 4:
        {
            cout << "Enter name to delete: ";
            string name;
            cin >> name;
            con.Delete(con, name);
            break;
        }

        case 5:
        {
            cout << "Enter name to search: ";
            string name;
            cin >> name;
            con.Search(con, name);
            break;
        }

        case 6:
            con.Destroy(con);
            break;

        case 0:
            break;

        default:
            cout << "Invalid input." << endl;
            break;
        }
    } while (input != 0);
    system("pause");
    return 0;
}