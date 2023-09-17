#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution
{
private:
    vector<TreeNode*> arr;
    void              preOrder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        arr.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }

public:
    void flatten(TreeNode* root)
    {
        preOrder(root);
        for (int i = 0; i < arr.size(); ++i)
        {
            if (i != arr.size() - 1)
            {
                arr[i]->left  = nullptr;
                arr[i]->right = arr[i + 1];
            }
            else
            {
                arr[i]->left  = nullptr;
                arr[i]->right = nullptr;
            }
        }
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
