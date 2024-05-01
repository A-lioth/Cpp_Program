#include <iostream>
#include <queue>
#include <string>
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
    // 创建哈夫曼树并计算哈夫曼编码
    void createHaffmanTree(Node *&root, int n)
    {
        ;
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
            return (Height(root->left) > Height(root->right)) ? (Height(root->left) + 1) : (Height(root->right) + 1);
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

    // 以广义表形式输出先序遍历二叉树
    void GTable(Node *&root)
    {
        cout << "( ";
        if (root == nullptr)
            cout << "# ";
        else
        {
            cout << root->data << ", ";
            GTable(root->left);
            GTable(root->right);
        }
        cout << ") ";
    }

    void Menu()
    {
        int choice;
        do
        {
            cout << "1. Create a binary tree" << endl;
            cout << "2. Pre-order traversal" << endl;
            cout << "3. In-order traversal" << endl;
            cout << "4. Post-order traversal" << endl;
            cout << "5. Level-order traversal" << endl;
            cout << "6. Height of the binary tree" << endl;
            cout << "7. Number of nodes in the binary tree" << endl;
            cout << "8. Number of leaves in the binary tree" << endl;
            cout << "9. Output the binary tree in G-table format" << endl;
            cout << "10. Destroy the binary tree" << endl;
            cout << "11. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                Create(root);
                cout << "Binary tree created successfully." << endl;
                break;
            case 2:
                PreOrder(root);
                cout << endl;
                break;
            case 3:
                InOrder(root);
                cout << endl;
                break;
            case 4:
                PostOrder(root);
                cout << endl;
                break;
            case 5:
                LevelOrder(root);
                break;
            case 6:
                cout << "Height of the binary tree: " << Height(root) << endl;
                break;
            case 7:
                cout << "Number of nodes in the binary tree: " << NodeCount(root) << endl;
                break;
            case 8:
                cout << "Number of leaves in the binary tree: " << LeafCount(root) << endl;
                break;
            case 9:
                cout << "Binary tree in G-table format: ";
                GTable(root);
                cout << endl;
                break;
            case 10:
                Destroy(root);
                cout << "Binary tree destroyed successfully." << endl;
                break;
            case 11:
                cout << "Creating Haffman Tree..." << endl;
                cout << "Enter the number of nodes: ";
                int n;
                cin >> n;
                createHaffmanTree(root, n);
            case 12:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 12);
    }
};

int main()
{
    BTree root;
    root.Menu();
    return 0;
}

// abc##d##ef##g##
//     a
//
//   b   e
//
// c  d f  g