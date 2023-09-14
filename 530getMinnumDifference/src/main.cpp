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
    vector<int> arr;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
        return;
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT32_MAX;
        dfs(root);
        for (int i = 0; i < arr.size(); ++i)
        {
            if (i + 1 < arr.size())
                ans = min(arr[i + 1] - arr[i], ans);
        }
        return ans;
    }
};

int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
