#include <iostream>

using namespace std;

class Solution {
  public:
    int minDistance( string word1, string word2 ) {
        int lenWord1 = word1.length(), lenWord2 = word2.length();
        int dp[ 501 ][ 501 ];
        dp[ 0 ][ 0 ] = { 0 };
        for ( int i = 1; i <= lenWord1; ++i ) {
            dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] + 1;
        }
        for ( int j = 1; j <= lenWord2; ++j ) {
            dp[ 0 ][ j ] = dp[ 0 ][ j - 1 ] + 1;
        }
        for ( int i = 1; i <= lenWord1; ++i ) {
            for ( int j = 1; j <= lenWord2; ++j ) {
                if ( word1[ i - 1 ] == word2[ j - 1 ] ) {
                    dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ];
                } else {
                    dp[ i ][ j ] =
                        min( dp[ i - 1 ][ j - 1 ],
                             min( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] ) ) +
                        1;
                }
            }
        }
        return dp[ lenWord1 ][ lenWord2 ];
    }
};

int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
