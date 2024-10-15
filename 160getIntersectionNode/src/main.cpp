#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode( int x )
        : val( x )
        , next( NULL ) {}
};

class Solution {
  public:
    ListNode *getIntersectionNode( ListNode *headA, ListNode *headB ) {
        set<ListNode *> map;
        ListNode *p1 = headA;
        while ( p1 != nullptr ) {
            map.insert( p1 );
            p1 = p1->next;
        }
        ListNode *p2 = headB;
        while ( p2 != nullptr ) {
            if ( map.find( p2 ) != map.end() ) {
                return p2;
            } else {
                p2 = p2->next;
            }
        }
        return NULL;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
