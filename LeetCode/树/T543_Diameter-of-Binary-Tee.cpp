#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode *root, int &prev)
{
    if (root == nullptr)
        return 0;
    int left = height(root->left, prev);
    int right = height(root->right, prev);
    prev = max(prev, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int prev = 0;
    height(root, prev);
    return prev;
}

int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(6)));
    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}