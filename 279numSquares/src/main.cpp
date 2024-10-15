#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int numSquares( int n ) {
        vector<int> f( n + 1 );
        f[ 0 ] = 0;
        for ( int i = 1; i <= n; ++i ) {
            int minN = INT8_MAX;
            for ( int j = 1; j * j <= i; ++j ) {
                minN = min( minN, f[ i - j * j ] + 1 );
            }
            f[ i ] = minN;
        }
        return f[ n ];
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
