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

int height(TreeNode *root)
{
    return root == nullptr ? 0 : max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(TreeNode *root)
{
    return root == nullptr ? true : isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
}

int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}