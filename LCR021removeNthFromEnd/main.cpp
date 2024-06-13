#include <iostream>
#include <stack>
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
    ListNode *removeNthFromEnd( ListNode *head, int n ) {
        if ( head == nullptr ) {
            return nullptr;
        }
        ListNode *dummy = new ListNode( 0, head );
        std::stack<ListNode *> stk;
        ListNode *cur = dummy;
        while ( cur != nullptr ) {
            stk.push( cur );
            cur = cur->next;
        }
        for ( int i = 0; i < n; ++i ) {
            if ( stk.empty() ) {
                return nullptr;
            }
            stk.pop();
        }
        ListNode *pre = stk.top();
        ListNode *remove = pre->next;
        pre->next = pre->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        delete remove;
        return ans;
    }
};

int main() { std::cout << "hello world" << std::endl; }