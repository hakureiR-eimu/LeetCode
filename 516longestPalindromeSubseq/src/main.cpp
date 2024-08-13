#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
  public:
    int longestPalindromeSubseq( string s ) {
        if ( s.empty() ) {
            return 0;
        }
        if ( s.length() == 1 ) {
            return 1;
        }

        int dp[ 1005 ][ 1005 ] = { 0 };
        int maxLen = 1;
        for ( int i = 0; i < s.length(); ++i ) {
            dp[ i ][ i ] = 1;
        }
        for ( int i = s.length() - 1; i >= 0; --i ) {
            for ( int j = i + 1; j < s.length(); ++j ) {
                if ( s[ i ] != s[ j ] ) {
                    dp[ i ][ j ] = max( dp[ i + 1 ][ j ], dp[ i ][ j - 1 ] );
                } else {
                    if ( j - i == 0 ) {
                        dp[ i ][ j ] = 1;
                    } else if ( j - i == 1 ) {
                        dp[ i ][ j ] = 2;
                    } else {
                        dp[ i ][ j ] = dp[ i + 1 ][ j - 1 ] + 2;
                    }
                }
            }
        }
        return dp[ 0 ][ s.length() - 1 ];
    }
};
int main( int argc, char **argv ) {
    string s = "cbbd";
    Solution *sol = new Solution();
    Solution sol2;
    int res = sol2.longestPalindromeSubseq( s );
    cout << res << endl;
    cout << "hello world!" << endl;
    return 0;
}
