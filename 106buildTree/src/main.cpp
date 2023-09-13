#include <iostream>
#include <vector>
#include <map>
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
    map<int, int> index;
    TreeNode *buildTreeR(vector<int> &inorder, vector<int> &postorder, int inLeft, int inRight, int postLeft, int postRight)
    {
        if (inLeft > inRight || postLeft > postRight)
            return nullptr;
        int rootPost = postRight;
        int rootVal = postorder[rootPost];
        int rootIn = index[rootVal];
        TreeNode *root = new TreeNode(rootVal);
        int numL = rootIn - inLeft;
        root->left = buildTreeR(inorder, postorder, inLeft, rootIn - 1, postLeft, postLeft + numL - 1);
        root->right = buildTreeR(inorder, postorder, rootIn + 1, inRight, postLeft + numL, rootPost - 1);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0)
            return nullptr;
        for (int i = 0; i < inorder.size(); ++i)
        {
            index[inorder[i]] = i;
        }
        return buildTreeR(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
