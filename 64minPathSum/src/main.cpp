#include <iostream>
#include <utility>
#include <vector>
using namespace std;
class Solution {
  public:
    int minPathSum( vector<vector<int>> &grid ) {
        int rows = grid.size();
        int cols = grid[ 0 ].size();
        for ( int x = 0; x < rows; x++ ) {
            for ( int y = 0; y < cols; y++ ) {
                if ( x == 0 && y == 0 ) {
                    continue;
                } else if ( x == 0 ) {
                    grid[ x ][ y ] = grid[ x ][ y - 1 ] + grid[ x ][ y ];
                    continue;
                } else if ( y == 0 ) {
                    grid[ x ][ y ] = grid[ x - 1 ][ y ] + grid[ x ][ y ];
                } else {
                    grid[ x ][ y ] =
                        min( grid[ x - 1 ][ y ], grid[ x ][ y - 1 ] ) +
                        grid[ x ][ y ];
                }
            }
        }
        return grid[ rows - 1 ][ cols - 1 ];
    };
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
