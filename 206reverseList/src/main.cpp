#include <iostream>

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
    ListNode *reverseList( ListNode *head ) {
        ListNode *dummy = new ListNode( 0, head );
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;
        while ( cur != nullptr ) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
