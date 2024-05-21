#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int val, Node *left = nullptr, Node *right = nullptr) : val(val), left(left), right(right){};
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

    void Insert(int val)
    {
        if (root == nullptr)
        {
            root = new Node(val);
            return;
        }
        Node *p = root;
        Node *leafPtr = nullptr;

        while (p != nullptr)
        {
            if (val == p->val)
            {
                cout << "Value already exists in the tree." << endl;
                return;
            }
            leafPtr = p;

            if (val < p->val)
            {
                p = p->left;
            }
            else if (val > p->val)
            {
                p = p->right;
            }
        }

        Node *s = new Node(val);
        if (val < leafPtr->val)
        {
            leafPtr->left = s;
        }
        else if (val > leafPtr->val)
        {
            leafPtr->right = s;
        }
    }

    bool Search(int val)
    {
        if (root == nullptr)
        {
            return false;
        }
        Node *p = root;
        while (p != nullptr)
        {
            if (val < p->val)
            {
                p = p->left;
            }
            else if (val > p->val)
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
    /*
        void Delete(int val)
        {
            if (root == nullptr)
            {
                return;
            }
            Node *p = root;
            Node *leafPtr = nullptr;
            while (p != nullptr)
            {
                if (p->val == val)
                {
                    break;
                }
                leafPtr = p;
                if (val < p->val)
                {
                    p = p->left;
                }
                else if (val > p->val)
                {
                    p = p->right;
                }
            }
            if (p == nullptr)
            {
                cout << "Value not found in the tree." << endl;
                return;
            }
        }
     */
    void inorder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void Destroy(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        Destroy(root->left);
        Destroy(root->right);
        delete root;
        root = nullptr;
    }

    ~BST()
    {
        Destroy(root);
        root = nullptr;
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
                int val;
                cout << "Enter the value to be searched: ";
                cin >> val;
                if (Search(val))
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