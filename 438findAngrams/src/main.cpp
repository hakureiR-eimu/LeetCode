#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
    void refresh( int letters[], int A[] ) {
        for ( int i = 0; i < 26; ++i ) {
            A[ i ] = letters[ i ];
        }
    }

  public:
    vector<int> findAnagrams( string s, string p ) {
        vector<int> res;

        int letters[ 26 ] = { 0 };
        int A[ 26 ];
        for ( int i = 0; i < p.size(); ++i ) {
            int offset = p[ i ] - 'a';
            letters[ offset ]++;
        }

        for ( int i = 0; i < s.size(); ++i ) {
            refresh( letters, A );
            int flag = 1;
            int len = 0;
            for ( int j = 0; j < p.size() && i + j < s.size(); ++j ) {
                int offset = s[ i + j ] - 'a';
                if ( A[ offset ] <= 0 ) {
                    break;
                    flag = 0;
                } else {
                    A[ offset ]--;
                    ++len;
                }
            }
            // cout << len << endl;
            if ( flag == 1 && len == p.length() ) {
                res.push_back( i );
            }
        }
        return res;
    }
};
int main( int argc, char **argv ) {
    string s( "cbaebabacd" ), p( "abc" );
    Solution sol;
    auto res = sol.findAnagrams( s, p );
    for ( int i = 0; i < res.size(); ++i ) {
        cout << res[ i ] << " ";
    }
    return 0;
}
