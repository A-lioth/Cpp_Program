#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

long long count = 0;

long long DFS(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return 0;
    if (root->val == targetSum)
        count++;
    count += DFS(root->left, targetSum - root->val);
    count += DFS(root->right, targetSum - root->val);
    return count;
}

int pathSum(TreeNode *root, int targetSum)
{
    return root == nullptr ? 0 : (pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + DFS(root, targetSum));
}

int main()
{
    TreeNode *root = new TreeNode(10, new TreeNode(5, new TreeNode(3, new TreeNode(3), new TreeNode(-2)), new TreeNode(2, new TreeNode(1), new TreeNode(1))), new TreeNode(-3, NULL, new TreeNode(11)));
    int targetSum = 8;
    cout << pathSum(root, targetSum) << endl;
    return 0;
}