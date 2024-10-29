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
    int maxNum = 0;
    int dfs( TreeNode *root ) {
        if ( root == nullptr ) return 0;
        int l = dfs( root->left );
        int r = dfs( root->right );
        maxNum = max( maxNum, l + r );
        return max( l, r ) + 1;
    }
    int diameterOfBinaryTree( TreeNode *root ) {
        dfs( root );
        return maxNum;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
