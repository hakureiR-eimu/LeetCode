#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode()
        : val( 0 )
        , next( nullptr ) {}
    ListNode( int x )
        : val( x )
        , next( nullptr ) {}
    ListNode( int x, ListNode *next )
        : val( x )
        , next( next ) {}
};

class Solution {
  public:
    ListNode *swapPairs( ListNode *head ) {
        ListNode *dummyNode = new ListNode( -1, head );
        ListNode *cur = dummyNode;
        while ( cur && cur->next && cur->next->next ) {
            ListNode *pre = cur->next->next;
            ListNode *in = cur->next;
            ListNode *post = cur->next->next->next;
            cur->next = pre;
            pre->next = in;
            in->next = post;
            cur = in;
        }
        return dummyNode->next;
    }
};
int main( int argc, char **argv ) {
    vector<ListNode> list{ ListNode( 0 ), ListNode( 2 ), ListNode( 3 ),
                           ListNode( 4 ), ListNode( 5 ) };
    for ( int i = 0; i < list.size() - 1; ++i ) {
        list[ i ].next = &list[ i + 1 ];
    }
    Solution sol;
    sol.swapPairs( &list[ 0 ] );
    cout << "hello world!" << endl;
    return 0;
}
