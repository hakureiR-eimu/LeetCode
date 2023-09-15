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
    TreeNode *sortR(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right) / 2;
        int val = nums[mid];
        TreeNode *node = new TreeNode(val);
        node->left = sortR(nums, left, mid - 1);
        node->right = sortR(nums, mid + 1, right);
        return node;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortR(nums, 0, nums.size() - 1);
    }
};
int main(int argc, char **argv)
{
    vector<int> nums = {-10, -3, 0, 5, 9};

    cout << "hello world!" << endl;
    return 0;
}
