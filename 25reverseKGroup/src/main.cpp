#include <iostream>
#include <stack>
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
    ListNode *reverseKGroup( ListNode *head, int k ) {
        ListNode *head_pre = new ListNode( 0, head );
        ListNode *p = head_pre;
        ListNode *preNode;
        ListNode *preNode_temp;
        ListNode *nextNode;
        ListNode *tmp;
        int count = 0;
        stack<ListNode *> stk;
        while ( p != nullptr ) {
            if ( count == 0 ) {
                preNode = p;
            }
            if ( count == k ) {
                count = 0;
                nextNode = p->next;
                int flag = 0;
                while ( !stk.empty() ) {
                    flag++;
                    tmp = stk.top();
                    if ( flag == 1 ) {
                        preNode->next = tmp;
                    }
                    stk.pop();
                    tmp->next = stk.empty() ? nextNode : stk.top();
                    if ( stk.empty() ) {
                        preNode = tmp;
                        p = preNode;
                    }
                }
            }
            p = p->next;
            count++;
            stk.push( p );
        }
        return head_pre->next;
    }
};

int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
