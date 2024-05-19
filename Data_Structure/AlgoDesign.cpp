#include "BTree.cpp"

// 交换左右子树节点
void Swap(Node *&l, Node *&r)
{
    Node *temp = l;
    l = r;
    r = temp;
}

// 判断是否为二叉排序树
bool isBST(Node *root)
{
    if (root == NULL)
        return true;
    return isBST(root->left) && isBST(root->right) && (root->left == NULL || root->left->data < root->data) && (root->right == NULL || root->right->data > root->data);
}

void test()
{
    BTree bt;
    bt.Menu();
    // Swap(bt.root->left, bt.root->right);
    /*
    if (isBST(bt.root))
        cout << "This is a binary search tree." << endl;
    else
        cout << "This is not a binary search tree." << endl;
    */
    bt.Menu();
}

int main()
{
    test();
    return 0;
}