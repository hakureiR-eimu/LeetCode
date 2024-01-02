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
  private:
    void swap( ListNode *pre1, ListNode *pre2 ) {
        ListNode *node1 = pre1->next;
        ListNode *next1 = pre1->next->next;
        ListNode *node2 = pre2->next;
        ListNode *next2 = pre2->next->next;
    }
    ListNode *merge( ListNode *head1, ListNode *head2 ) {
        ListNode *dummyNode = new ListNode( 0 );
        ListNode *current = dummyNode;
        while ( head1 != nullptr && head2 != nullptr ) {
            if ( head1->val < head2->val ) {
                current->next = head1;
                head1 = head1->next;
            } else {
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }
        if ( head1 == nullptr ) {
            current->next = head2;
        } else {
            current->next = head1;
        }
        return dummyNode->next;
    }
    ListNode *split( ListNode *head, int step ) {
        if ( head == nullptr ) {
            return nullptr;
        }
        for ( int i = 1; i < step && head->next != nullptr; ++i ) {
            head = head->next;
        }
        ListNode *newHead = head->next;
        head->next = nullptr;
        return newHead;
    }

  public:
    void print( ListNode *head ) {
        ListNode *current = head;
        while ( current != nullptr ) {
            cout << current->val << endl;
            current = current->next;
        }
    }
    ListNode *sortList( ListNode *head ) {
        if ( head == nullptr || head->next == nullptr ) {
            return head;
        }
        ListNode *dummyNode = new ListNode( 0, head );
        ListNode *current = dummyNode;
        ListNode *pre = dummyNode;
        int len = 0;
        while ( current->next != nullptr ) {
            current = current->next;

            // cout << current->val << endl;

            len++;
        }
        current = dummyNode;
        for ( int step = 1; step <= len; step <<= 1 ) {
            pre = dummyNode;
            current = dummyNode->next;
            while ( current != nullptr ) {
                ListNode *head1 = current;

                // cout << head1->val << endl;
                ListNode *head2 = split( head1, step );

                // cout << head2->val << endl;
                current = split( head2, step );

                pre->next = merge( head1, head2 );

                while ( pre->next != nullptr ) {
                    pre = pre->next;
                }
            }
        }
        return dummyNode->next;
    }
};
int main( int argc, char **argv ) {
    ListNode *head = new ListNode( 4 );

    ListNode *node = head;
    node->next = new ListNode( 2 );
    node = node->next;
    node->next = new ListNode( 1 );
    node = node->next;
    node->next = new ListNode( 3 );

    head = Solution().sortList( head );
    Solution().print( head );
    cout << "hello world!" << endl;
    return 0;
}
