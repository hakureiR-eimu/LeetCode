#include <iostream>
#include <vector>
#include <deque>
#include < algorithm>
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        deque<TreeNode *> deq;
        vector<vector<int>> res;
        if (root != nullptr) deq.push_back(root);
        int isOdd = 1;
        while (!deq.empty())
        {
            vector<int> resLevel;
            int n = deq.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode *p = deq.back();
                deq.pop_back();
                resLevel.push_back(p->val);
                if (p->left) deq.push_front(p->left);
                if (p->right) deq.push_front(p->right);
            }
            if (isOdd == -1)
            {
                reverse(resLevel.begin(), resLevel.end());
            }
            res.push_back(resLevel);
            isOdd = -isOdd;
        }
        return res;
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
