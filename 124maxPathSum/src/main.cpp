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
  private:
    int sum = INT32_MIN;
    int getGain( TreeNode *root ) {
        if ( root == nullptr ) return 0;
        int leftGain = max( getGain( root->left ), 0 );
        int rightGain = max( getGain( root->right ), 0 );

        int price = leftGain + rightGain + root->val;
        sum = max( sum, price );
        return root->val + max( leftGain, rightGain );
    }

  public:
    int maxPathSum( TreeNode *root ) {
        getGain( root );
        return sum;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
