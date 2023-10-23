#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int       val;
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

class BSTIterator {
  private:
    queue<TreeNode *> stk;
    void              midOrder( TreeNode *root ) {
                     if ( root->left ) {
                         midOrder( root->left );
        }
                     stk.push( root );
                     if ( root->right ) {
                         midOrder( root->right );
        }
    }

  public:
    BSTIterator( TreeNode *root ) { midOrder( root ); }

    int next() {
        int n = stk.front()->val;
        stk.pop();
        return n;
    }

    bool hasNext() { return !stk.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
