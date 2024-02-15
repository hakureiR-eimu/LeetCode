#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
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
    vector<vector<int>> levelOrderBottom( TreeNode *root ) {
        queue<TreeNode *> que;
        vector<vector<int>> res;

        if ( root == nullptr ) {
            return res;
        }

        que.push( root );
        int depth = 0;
        while ( !que.empty() ) {
            vector<int> item;
            int size = que.size();
            for ( int i = 0; i < size; i++ ) {
                TreeNode *node = que.front();
                que.pop();
                item.push_back( node->val );
                if ( node->left != nullptr ) {
                    que.push( node->left );
                }
                if ( node->right != nullptr ) {
                    que.push( node->right );
                }
            }
            res.push_back( item );
            depth++;
        }
        std::reverse( res.begin(), res.end() );
        return res;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
