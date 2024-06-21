#include <iostream>
#include <string>
using namespace std;
class Solution {
  public:
    int longestCommonSubsequence( string text1, string text2 ) {
        int n = text1.size(), m = text2.size();
        int dp[ text1.size() + 1 ][ text2.size() + 1 ];

        // dp[0][0]....dp[0][m]
        //  ...
        // dp[n][0]... dp[n][m]
        for ( int i = 0; i <= m; ++i ) {
            dp[ 0 ][ i ] = 0;
        }
        for ( int i = 0; i <= n; ++i ) {
            dp[ i ][ 0 ] = 0;
        }
        for ( int i = 1; i <= n; ++i ) {
            char ch1 = text1[ i - 1 ];
            for ( int j = 1; j <= m; ++j ) {
                char ch2 = text2[ j - 1 ];
                if ( ch1 == ch2 ) {
                    dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ] + 1;
                } else {
                    dp[ i ][ j ] = max( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] );
                }
            }
        }
        int res = dp[ n ][ m ];
        return res;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
