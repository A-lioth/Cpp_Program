#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data, Node *left = nullptr, Node *right = nullptr) : data(data), left(left), right(right){};
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }

    void Insert(int data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
            return;
        }
        Node *p = root;
        Node *leafptr = nullptr;

        while (p != nullptr)
        {
            if (p->data == data)
            {
                cout << "Value already exists in the tree." << endl;
                return;
            }
            leafptr = p;

            if (p->data > data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }

        Node *s = new Node(data);
        if (leafptr->data > data)
        {
            leafptr->left = s;
        }
        else
        {
            leafptr->right = s;
        }
    }

    bool Search(int data)
    {
        if (root == nullptr)
        {
            return false;
        }
        Node *p = root;
        while (p != nullptr)
        {
            if (p->data > data)
            {
                p = p->left;
            }
            else if (p->data < data)
            {
                p = p->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    void inorder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    ~BST()
    {
        if (root != nullptr)
        {
            delete root;
            root = nullptr;
        }
    }

    void Menu(vector<int> &nums)
    {
        int choice;
        do
        {
            cout << "1. Insert" << endl;
            cout << "2. Search" << endl;
            cout << "3. Inorder Traversal" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                for (int i = 0; i < nums.size(); i++)
                {
                    Insert(nums[i]);
                }
                break;
            }
            case 2:
            {
                int data;
                cout << "Enter the value to be searched: ";
                cin >> data;
                if (Search(data))
                {
                    cout << "Value found in the tree." << endl;
                }
                else
                {
                    cout << "Value not found in the tree." << endl;
                }
                break;
            }
            case 3:
            {
                inorder(root);
                cout << endl;
                break;
            }
            case 4:
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
            }
        } while (choice != 4);
    }
};

void shellSort(vector<int> &arr)
{
    int n = arr.size();
    int gap = n / 2;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

void Init(vector<int> &nums)
{
    srand((unsigned)time(nullptr));
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = rand() % 10000;
    }
}

void Print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 20 == 0)
        {
            cout << endl;
        }
        printf("%4d ", nums[i]);
    }
    cout << endl;
}

int main()
{
    BST bst;
    vector<int> nums(1000);
    Init(nums);
    shellSort(nums);
    Print(nums);
    bst.Menu(nums);
    return 0;
}