#include <iostream>
#include <vector>
#include <queue>
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
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        queue<TreeNode *> que;
        if (root == nullptr)
            return res;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            double sum = 0;
            for (int i = 0; i < n; ++i)
            {
                TreeNode *p = que.front();
                que.pop();
                sum += (double)p->val;
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
            }
            res.push_back(sum / n);
        }
        return res;
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
