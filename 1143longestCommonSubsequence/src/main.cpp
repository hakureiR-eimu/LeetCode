#include <iostream>
#include <string>
using namespace std;
class Solution {
  public:
    int longestCommonSubsequence( string text1, string text2 ) {
        int dp[ text1.length() + 1 ][ text2.length() + 1 ];
        dp[ 0 ][ 0 ] = 0;
        for ( int i = 0; i < text1.length() + 1; ++i ) {
            dp[ i ][ 0 ] = 0;
        }
        for ( int i = 0; i < text2.length() + 1; ++i ) {
            dp[ 0 ][ i ] = 0;
        }
        for ( int i = 1; i <= text1.length(); ++i ) {
            char ch1 = text1.at( i - 1 );
            for ( int j = 1; j <= text2.length(); ++j ) {
                char ch2 = text2.at( j - 1 );
                if ( ch1 == ch2 ) {
                    dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ] + 1;
                } else {
                    dp[ i ][ j ] = max( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] );
                }
            }
        }
        return dp[ text1.length() ][ text2.length() ];
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
