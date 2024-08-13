#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
  public:
    string longestPalindrome( string s ) {
        int dp[ 1005 ][ 1005 ] = { 0 };
        int maxLen = 1;
        int maxL = 0, maxR = 0;
        if ( s.empty() || s.length() < 2 ) {
            return s;
        }
        for ( int i = 0; i < s.length(); ++i ) {
            dp[ i ][ i ] = 1;
        }
        for ( int j = 1; j < s.length(); ++j ) {
            for ( int i = 0; i < j; ++i ) {
                if ( s[ i ] != s[ j ] ) {
                    dp[ i ][ j ] = 0;
                } else {
                    if ( j - i == 1 || j - i == 0 ) {
                        dp[ i ][ j ] = 1;
                        if ( j - i + 1 > maxLen ) {
                            maxLen = j - i + 1;
                            maxL = i;
                            maxR = j;
                        }
                    } else {
                        dp[ i ][ j ] = dp[ i + 1 ][ j - 1 ];
                        if ( j - i + 1 > maxLen && dp[ i ][ j ] == 1 ) {
                            maxLen = j - i + 1;
                            maxL = i;
                            maxR = j;
                        }
                    }
                }
            }
        }
        // for ( int i = 0; i < s.length(); ++i ) {
        //     for ( int j = i; j < s.length(); ++j ) {
        //         if ( s[ i ] != s[ j ] ) {
        //             dp[ i ][ j ] = 0;
        //         } else {
        //             if ( i + 1 <= j - 1 ) {
        //                 dp[ i ][ j ] = dp[ i + 1 ][ j - 1 ];
        //             } else {
        //                 dp[ i ][ j ] = 1;
        //             }
        //             if ( j - i + 1 > maxLen ) {
        //                 maxLen = j - i + 1;
        //                 maxL = i;
        //                 maxR = j;
        //             }
        //         }
        //     }
        // }
        string res;
        for ( int i = maxL; i <= maxR; ++i ) {
            res.push_back( s[ i ] );
        }
        return res;
    }
};
int main( int argc, char **argv ) {
    string s = "aacabdkacaa";
    Solution *sol = new Solution();
    string res = sol->longestPalindrome( s );
    cout << res << endl;
    cout << "hello world!" << endl;
    return 0;
}
