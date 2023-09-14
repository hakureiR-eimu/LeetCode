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

class Solution
{
private:
    bool dfs(TreeNode *root, int tar, int val)
    {
        val += root->val;
        if (val == tar && !root->left && !root->right)
            return true;
        else if (root->left && root->right)
            return dfs(root->left, tar, val) || dfs(root->right, tar, val);
        else if (root->left && !root->right)
            return dfs(root->left, tar, val);
        else if (root->right && !root->left)
            return dfs(root->right, tar, val);
        return false;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int val = 0;
        if (root)
            return dfs(root, targetSum, val);
        else
            return false;
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
