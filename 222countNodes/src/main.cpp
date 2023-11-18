#include <algorithm>
#include <iostream>
#include <stack>
//导入可以计算次方的函数
#include <cmath>
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
    bool isNodeExist( int dep, int num, TreeNode *root ) {
        int bits = 1 << ( dep - 1 );
        TreeNode *p = root;
        while ( p != nullptr && bits > 0 ) {
            //检测第dep-1位，如果是1则为0进入else，否则进入true
            if ( bits & num ) {
                p = p->right;
            } else {
                p = p->left;
            }
            bits = bits >> 1;
        }
        return p != nullptr;
    }
    int countNodes( TreeNode *root ) {
        if ( root == nullptr ) return 0;
        int dep = 0;
        // stack<TreeNode *> stk;
        TreeNode *p = root;
        while ( p->left != NULL ) {
            dep++;
            // stk.push( p );
            p = p->left;
        }
        //范围是[2**dep,2**(dep+1)-1]
        int left = 1 << dep, right = ( 1 << ( dep + 1 ) ) - 1;
        while ( left < right ) {
            int mid = ( right - left + 1 ) / 2 + left;
            if ( isNodeExist( dep, mid, root ) ) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
