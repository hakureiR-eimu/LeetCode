#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution
{
private:
    int         maxDepth = 0;
    vector<int> res;
    void        dfs(TreeNode* root, int high)
    {
        if (root == nullptr) return;
        if (maxDepth < high)
        {
            res.push_back(root->val);
            maxDepth = high;
        }
        dfs(root->right, high + 1);
        dfs(root->left, high + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root)
    { // rightView,
        dfs(root, 1);
        return res;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
