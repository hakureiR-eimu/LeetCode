#include <iostream>
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

  private:
    class nodeList {
        TreeNode *node;
        TreeNode *row;
        int row;
        int col;
        nodeList( TreeNode *root ) { this->node = root; }
    };
    void preOrder( TreeNode *node, int row, int col ) {
        if ( node == nullptr ) {
            return;
        }
        preOrder( node->left, row + 1, col - 1 );
        preOrder( node->right, row + 1, col + 1 );
    }

  public:
    vector<vector<int>> verticalTraversal( TreeNode *root ) {}
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
