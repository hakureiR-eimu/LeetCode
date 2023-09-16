#include <iostream>
#include <vector>
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
    vector<int> midorder;
    void midOrder(TreeNode *root)
    {
        if (root->left)
            midOrder(root->left);
        midorder.push_back(root->val);
        if (root->right)
            midOrder(root->right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return false;
        midOrder(root);
        for (int i = 0; i < midorder.size() - 1; ++i)
        {
            if (midorder[i + 1] <= midorder[i])
                return false;
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
