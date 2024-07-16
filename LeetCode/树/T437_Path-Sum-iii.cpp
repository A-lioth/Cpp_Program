#include <iostream>
#include <unordered_map>

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

unordered_map<long, int> prefix;

void DFS(TreeNode *root, int targetSum, long sum, int &res)
{
    if (root == nullptr)
        return;

    sum += root->val;
    if (prefix.find(sum - targetSum) != prefix.end())
        res += prefix[sum - targetSum];

    prefix[sum]++;
    DFS(root->left, targetSum, sum, res);
    DFS(root->right, targetSum, sum, res);
    prefix[sum]--;
}

int pathSum(TreeNode *root, int targetSum)
{
    int res = 0; 
    prefix[0] = 1;
    long sum = 0;
    DFS(root, targetSum, sum, res);
    return res;
}
void deleteTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    TreeNode *root = new TreeNode(10, new TreeNode(5, new TreeNode(3, new TreeNode(3), new TreeNode(-2)), new TreeNode(2, new TreeNode(1), new TreeNode(1))), new TreeNode(-3, NULL, new TreeNode(11)));
    int targetSum = 8;
    cout << pathSum(root, targetSum) << endl;
    deleteTree(root);
    return 0;
}
