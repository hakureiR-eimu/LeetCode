#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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
    std::queue<TreeNode *> que;
    int x_depth = 0, y_depth = 0;
    int x_parent, y_parent;

  private:
    bool bfs( TreeNode *root, int x, int y ) {
        int depth = 0;
        que.push( root );
        if ( x == root->val || y == root->val ) {
            return false;
        }
        while ( !que.empty() ) {
            int size = que.size();
            for ( int i = 0; i < size; ++i ) {
                TreeNode *node = que.front();
                que.pop();
                if ( node->left != nullptr && node->right != nullptr &&
                     ( ( node->left->val == x && node->right->val == y ) ||
                       ( node->left->val == y && node->right->val == x ) ) ) {
                    return false;
                }
                if ( node->left != nullptr ) {
                    que.push( node->left );
                    if ( node->left->val == x ) {
                        this->x_depth = depth + 1;
                    }
                    if ( node->left->val == y ) {
                        this->y_depth = depth + 1;
                    }
                    if ( x_depth != 0 && x_depth == y_depth ) {
                        return true;
                    }
                }
                if ( node->right != nullptr ) {
                    que.push( node->right );
                    if ( node->right->val == x ) {
                        this->x_depth = depth + 1;
                    }
                    if ( node->right->val == y ) {
                        this->y_depth = depth + 1;
                    }
                    if ( x_depth != 0 && x_depth == y_depth ) {
                        return true;
                    }
                }
            }
            depth++;
        }
        return false;
    }

  public:
    bool isCousins( TreeNode *root, int x, int y ) {
        if ( root == nullptr ) {
            return false;
        }
        return bfs( root, x, y );
    }
};

int main( int argc, char **argv ) { return 0; }
