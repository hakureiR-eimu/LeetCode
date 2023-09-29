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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        vector<vector<TreeNode *>> resN;
        if (root == nullptr) return res;
        queue<TreeNode *> floor;
        floor.push(root);
        while (!floor.empty())
        {
            int n = floor.size();
            vector<int> arrFloor;
            for (int i = 0; i < n; ++i)
            {
                TreeNode *tmp = floor.front();
                floor.pop();
                arrFloor.push_back(tmp->val);
                if (tmp->left)
                {
                    floor.push(tmp->left);
                }
                if (tmp->right)
                {
                    floor.push(tmp->right);
                }
            }
            res.push_back(arrFloor);
        }
        return res;
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
