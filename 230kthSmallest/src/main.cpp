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
    vector<int> index;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        index.push_back(root->val);
        inorder(root->right);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root);
        return index[k - 1];
    }
};

int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
