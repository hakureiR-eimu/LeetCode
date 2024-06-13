#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val( 0 )
        , left( nullptr )
        , right( nullptr ) {}
    TreeNode( int x )
        : val( x )
        , left( nullptr )
        , right( nullptr ) {}
    TreeNode( int x, TreeNode *left, TreeNode *right )
        : val( x )
        , left( left )
        , right( right ) {}
};

class Solution {
  public:
    TreeNode *findMinPre( TreeNode *root ) {
        TreeNode *cur = root;
        if ( cur == nullptr ) {
            return nullptr;
        }
        while ( cur->left != nullptr ) {
            cur = cur->left;
        }
        return cur;
    }

    TreeNode *deleteNode( TreeNode *root, int key ) {
        if ( root == nullptr ) {
            return root;
        }
        TreeNode *cur = root, *pre = nullptr;

        while ( cur != nullptr ) {
            if ( key == cur->val ) {
                break;
            }
            pre = cur;
            if ( key > cur->val ) {
                cur = cur->right;
            } else if ( key < cur->val ) {
                cur = cur->left;
            }
        }
        if ( cur == nullptr ) {
            return root;
        }
        if ( cur->left == nullptr || cur->right == nullptr ) {
            TreeNode *child = cur->left != nullptr ? cur->left : cur->right;
            if ( cur == root ) {
                root = child;
                return root;
            } else {
                if ( pre->left == cur ) {
                    pre->left = child;
                } else {
                    pre->right = child;
                }
            }

            return root;
        } else {
            TreeNode *tmp = cur->right;
            while ( tmp->left != nullptr ) {
                tmp = tmp->left;
            }
            tmp->left = cur->left;
            if ( cur == root ) {
                return cur->right;
            } else {
                pre->left == cur ? pre->left = cur->right
                                 : pre->right = cur->right;
                return root;
            }
        }
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
