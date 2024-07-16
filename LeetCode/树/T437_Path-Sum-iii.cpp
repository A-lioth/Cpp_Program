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

void DFS(TreeNode *root, int targetSum, int currentSum, unordered_map<int, int> &prefixSumCount, int &count)
{
    if (root == nullptr)
        return;

    currentSum += root->val;

    if (prefixSumCount.find(currentSum - targetSum) != prefixSumCount.end())
    {
        count += prefixSumCount[currentSum - targetSum];
    }
    prefixSumCount[currentSum]++;
    DFS(root->left, targetSum, currentSum, prefixSumCount, count);
    DFS(root->right, targetSum, currentSum, prefixSumCount, count);

    prefixSumCount[currentSum]--;
}

int pathSum(TreeNode *root, int targetSum)
{
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;
    int count = 0;
    DFS(root, targetSum, 0, prefixSumCount, count);
    return count;
}

int main()
{
    TreeNode *root = new TreeNode(10, new TreeNode(5, new TreeNode(3, new TreeNode(3), new TreeNode(-2)), new TreeNode(2, new TreeNode(1), new TreeNode(1))), new TreeNode(-3, NULL, new TreeNode(11)));
    int targetSum = 8;
    cout << pathSum(root, targetSum) << endl;
    return 0;
}
