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
    TreeNode *buildTreeR(vector<int> &preorder, vector<int> &inorder, int preLeft, int preRight, int inLeft, int inRight)
    {
        if (preLeft > preRight || inLeft > inRight)
            return nullptr;
        int preRoot = preLeft;
        int rootVal = preorder[preRoot];
        int inRoot = index[rootVal];
        TreeNode *root = new TreeNode(rootVal);

        int lNum = inRoot - inLeft;
        root->left = buildTreeR(preorder, inorder, preLeft + 1, preLeft + lNum, inLeft, inRoot - 1);
        root->right = buildTreeR(preorder, inorder, preRoot + lNum + 1, preRight, inRoot + 1, inRight);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    { // stack push(pre)
        for (int i = 0; i < inorder.size(); ++i)
        {
            index[inorder[i]] = i;
        }
        return buildTreeR(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
