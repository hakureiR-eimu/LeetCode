#include <iostream>
#include <vector>

class Solution {
  public:
    int uniquePathsWithObstacles(
        std::vector<std::vector<int>> &obstacleGrid ) {
        int rowLen = obstacleGrid.size();
        int colLen = obstacleGrid[ 0 ].size();
        int dp[ 105 ][ 105 ] = { 0 };
        for ( int i = 0; i < rowLen; ++i ) {
            for ( int j = 0; j < colLen; ++j ) {
                if ( obstacleGrid[ i ][ j ] ) {
                    dp[ i ][ j ] = 0;
                    continue;
                }

                if ( i == 0 && j == 0 ) {
                    dp[ i ][ j ] = 1;
                } else if ( i == 0 ) {

                    dp[ i ][ j ] = dp[ i ][ j - 1 ];

                } else if ( j == 0 ) {
                    dp[ i ][ j ] = dp[ i - 1 ][ j ];
                } else {
                    dp[ i ][ j ] = dp[ i - 1 ][ j ] + dp[ i ][ j - 1 ];
                }
            }
        }
        return dp[ rowLen - 1 ][ colLen - 1 ];
    }
};
int main( int argc, char **argv ) {
    std::cout << "hello world!" << std::endl;
    return 0;
}
