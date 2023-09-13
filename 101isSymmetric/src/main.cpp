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
    bool dfs(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if ((!left) || (!right))
            return false;
        if (left->val != right->val)
            return false;
        return dfs(left->right, right->left) && dfs(left->left, right->right);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return dfs(root->left, root->right);
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
