#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int maxPoints( std::vector<std::vector<int>> &points ) {
        std::vector<std::vector<int>> lines;

        if ( points.size() == 0 ) {
            return 0;
        }
        if ( points.size() == 1 ) {
            return 1;
        }

        for ( int i = 0; i < points.size(); ++i ) {
            for ( int j = i + 1; j < points.size(); ++j ) {
                std::vector<int> item;
                item.push_back( points[ i ][ 0 ] );
                item.push_back( points[ i ][ 1 ] );
                item.push_back( points[ j ][ 0 ] );
                item.push_back( points[ j ][ 1 ] );
                item.push_back( 0 );
                lines.push_back( item );
                // std::cout << "x0:" << item[ 0 ] << "y0:" << item[ 1 ] << "x1"
                //           << item[ 2 ] << "y2" << item[ 3 ] << std::endl;
            }
        }
        int maxRes = 0;
        for ( int i = 0; i < lines.size(); ++i ) {
            for ( int j = 0; j < points.size(); ++j ) {
                std::vector<int> &item = lines[ i ];
                int x2 = points[ j ][ 0 ], y2 = points[ j ][ 1 ],
                    x0 = item[ 0 ], y0 = item[ 1 ], x1 = item[ 2 ],
                    y1 = item[ 3 ];
                if ( ( y1 - y0 ) * ( x2 - x0 ) == ( y2 - y0 ) * ( x1 - x0 ) ) {
                    item[ 4 ] = item[ 4 ] + 1;
                    // std::cout << item[ 4 ] << std::endl;
                    maxRes = std::max( item[ 4 ], maxRes );
                }
            }
        };
        return maxRes;
    }
};
int main( int argc, char **argv ) { return 0; }
