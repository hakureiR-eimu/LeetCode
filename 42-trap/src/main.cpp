#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int trap( vector<int> &height ) {
        int n = height.size();
        if ( n == 0 ) {
            return 0;
        }
        vector<int> maxL( n );
        vector<int> maxR( n );

        maxL[ 0 ] = height[ 0 ];
        maxR[ n - 1 ] = height[ n - 1 ];

        for ( int i = 1; i < n; ++i ) { // 1-n-2
            maxL[ i ] = max( maxL[ i - 1 ], height[ i ] );
        }
        for ( int i = n - 2; i >= 0; --i ) {
            maxR[ i ] = max( maxR[ i + 1 ], height[ i ] );
        }

        int ans = 0;
        for ( int i = 0; i < n; ++i ) {
            ans += min( maxL[ i ], maxR[ i ] ) - height[ i ];
        }
        return ans;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
