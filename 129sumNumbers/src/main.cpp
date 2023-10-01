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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{
private:
    vector<int> sumArr;
    void dfs(TreeNode *root, int num)
    {
        num = num * 10 + root->val;
        if (root->left) dfs(root->left, num);
        if (root->right) dfs(root->right, num);
        if (!root->left && !root->right) sumArr.push_back(num);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        dfs(root, 0);
        for (int num : sumArr)
        {
            sum += num;
        }
        return sum;
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}