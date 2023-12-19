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
    ListNode *rotateRight( ListNode *head, int k ) {
        if ( head == nullptr ) {
            return nullptr;
        }
        ListNode *p = head;
        ListNode *pre;
        ListNode *res;
        int len = 0;
        while ( p != nullptr ) {
            pre = p;
            p = p->next;
            len++;
        }
        pre->next = head;
        int offset = len - ( k % len );
        p = head;
        while ( offset > 1 ) {
            p = p->next;
            offset--;
        }
        res = p->next;
        p->next = nullptr;
        return res;
    }
};

int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
