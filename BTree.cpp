#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

class BTree
{
private:
    Node *root;

public:
    BTree()
    {
        root = nullptr;
    }

    void Create(Node *&root)
    {
        char ch;
        cout << "Enter the data for root node: ";
        cin >> ch;
        if (ch == '#')
            root = nullptr;
        else
        {
            root = new Node;
            root->data = ch;
            Create(root->left);
            Create(root->right);
        }
    }

    void PreOrder(Node *root)
    {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void InOrder(Node *root)
    {
        if (root == nullptr)
            return;
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }

    void PostOrder(Node *root)
    {
        if (root == nullptr)
            return;
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }

    void LevelOrder(Node *root)
    {
        if (root == nullptr)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *s = q.front();
            q.pop();
            cout << s->data << " ";
            if (s->left != nullptr)
                q.push(s->left);
            if (s->right != nullptr)
                q.push(s->right);
        }
        cout << endl;
    }

    int Height(Node *root)
    {
        if (root == nullptr)
            return 0;
        else
        {
            int lh = Height(root->left);
            int rh = Height(root->right);
            return (lh > rh) ? (lh + 1) : (rh + 1);
        }
    }

    int NodeCount(Node *root)
    {
        if (root == nullptr)
            return 0;
        else
        {
            int lc = NodeCount(root->left);
            int rc = NodeCount(root->right);
            return (lc + rc + 1);
        }
    }

    int LeafCount(Node *root)
    {
        if (root == nullptr)
            return 0;
        else if (root->left == nullptr && root->right == nullptr)
            return 1;
        else
        {
            int lc = LeafCount(root->left);
            int rc = LeafCount(root->right);
            return (lc + rc);
        }
    }

    void Destroy(Node *&root)
    {
        if (root != nullptr)
        {
            Destroy(root->left);
            Destroy(root->right);
            delete root;
            root = nullptr;
        }
    }

    void Menu()
    {
        int choice;
        do
        {
            cout << "\n1. Create\n2. Pre-Order Traversal\n3. In-Order Traversal\n4. Post-Order Traversal\n5. Level-Order Traversal\n6. Height\n7. Node Count\n8. Leaf Count\n9. Destroy\n10. Exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                Create(root);
                break;
            case 2:
                PreOrder(root);
                break;
            case 3:
                InOrder(root);
                break;
            case 4:
                PostOrder(root);
                break;
            case 5:
                LevelOrder(root);
                break;
            case 6:
                cout << "Height of the tree is " << Height(root) << endl;
                break;
            case 7:
                cout << "Number of nodes in the tree is " << NodeCount(root) << endl;
                break;
            case 8:
                cout << "Number of leaves in the tree is " << LeafCount(root) << endl;
                break;
            case 9:
                Destroy(root);
                break;
            case 10:
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
        } while (choice != 10);
    }
};

int main()
{
    BTree root;
    root.Menu();
    return 0;
}