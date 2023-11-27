#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
  public:
    int lengthOfLongestSubstring( string s ) {
        if ( s.size() == 0 ) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for ( int i = 0; i < s.size(); i++ ) {
            while ( lookup.find( s[ i ] ) != lookup.end() ) {
                lookup.erase( s[ left ] );
                left++;
            }
            maxStr = max( maxStr, i - left + 1 );
            lookup.insert( s[ i ] );
        }
        return maxStr;
    }
};

int main( int argc, char **argv ) {
    string s = "tmmzuxt";
    Solution *p = new Solution;
    int len = p->lengthOfLongestSubstring( s );
    cout << len << endl;
    return 0;
}
