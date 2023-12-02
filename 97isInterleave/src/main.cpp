#include <iostream>
#include <stack>

using namespace std;

class Solution {
  private:
  public:
    bool isInterleave( string s1, string s2, string s3 ) {
        int m = s1.length(), n = s2.length();
        if ( s3.length() != m + n ) return false;
        // 动态规划，dp[i,j]表示s1前i字符能与s2前j字符组成s3前i+j个字符；
        bool dp[ 101 ][ 101 ] = { false };
        dp[ 0 ][ 0 ] = true;
        for ( int i = 1; i <= m && s1[ i - 1 ] == s3[ i - 1 ]; i++ )
            dp[ i ][ 0 ] = true; // 不相符直接终止
        for ( int j = 1; j <= n && s2[ j - 1 ] == s3[ j - 1 ]; j++ )
            dp[ 0 ][ j ] = true; // 不相符直接终止
        for ( int i = 1; i <= m; i++ ) {
            for ( int j = 1; j <= n; j++ ) {
                dp[ i ][ j ] =
                    ( dp[ i - 1 ][ j ] && s3[ i + j - 1 ] == s1[ i - 1 ] ) ||
                    ( dp[ i ][ j - 1 ] && s3[ i + j - 1 ] == s2[ j - 1 ] );
            }
        }
        return dp[ m ][ n ];
    }
};

int main( int argc, char **argv ) {
    string s1 = "a";
    string s2 = "";
    string s3 = "c";
    Solution *p = new Solution;
    bool res = p->isInterleave( s1, s2, s3 );

    cout << res << endl;
    return 0;
}
