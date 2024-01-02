#include <algorithm>
#include <iostream>
#include <queue>
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
    ListNode *mergeKLists( vector<ListNode *> &lists ) {
        lists.erase( remove_if( lists.begin(), lists.end(),
                                []( auto p ) { return !p; } ),
                     lists.end() );
        priority_queue q{ []( auto &a, auto &b ) { return a->val > b->val; },
                          lists };
        ListNode head;
        for ( auto p = &head; !q.empty(); q.pop() ) {
            p = p->next = q.top();
            if ( p->next ) q.push( p->next );
        }
        return head.next;
    }
};
int main( int argc, char **argv ) {
    vector<ListNode *> lists;
    ListNode *node;
    ListNode *head = new ListNode( 1 );
    node = head;
    node->next = new ListNode( 4 );
    node = node->next;
    node->next = new ListNode( 5 );
    lists.push_back( head );

    ListNode *head2 = new ListNode( 1 );
    node = head2;
    node->next = new ListNode( 3 );
    node = node->next;
    node->next = new ListNode( 4 );
    lists.push_back( head2 );

    ListNode *head3 = new ListNode( 2 );
    node = head3;
    node->next = new ListNode( 6 );
    node = node->next;
    lists.push_back( head3 );

    Solution().mergeKLists( lists );
    cout << "hello world!" << endl;
    return 0;
}
