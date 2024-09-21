#include <iostream>
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
    ListNode *detectCycle( ListNode *head ) {
        unordered_map<ListNode *, int> map;
        int pos = 0;
        ListNode *cur = head;
        while ( cur ) {
            if ( map.find( cur ) == map.end() ) {
                map[ cur ] = pos;
                pos++;
            } else {
                return cur;
            }
            cur = cur->next;
        }
        return NULL;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
