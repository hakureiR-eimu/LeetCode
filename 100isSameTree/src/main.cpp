#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p!=nullptr && q==nullptr)||(q!=nullptr && p==nullptr)){
            return false;
        }else if(p == nullptr && q == nullptr){
            return true;
        }else if(p->val != q->val){
            return false;
        }
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
