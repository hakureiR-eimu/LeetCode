#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int rob( vector<int> &nums ) {
        int dp1[ 105 ], dp2[ 105 ];
        if ( nums.size() == 1 ) {
            return nums[ 0 ];
        } else if ( nums.size() == 2 ) {
            return max( nums[ 0 ], nums[ 1 ] );
        }
        for ( int i = 0; i < nums.size() - 1; ++i ) {
            if ( i == 0 ) {
                dp1[ 0 ] = nums[ 0 ];
            } else if ( i == 1 ) {
                dp1[ 1 ] = max( nums[ 0 ], nums[ 1 ] );
            } else {
                dp1[ i ] = max( dp1[ i - 2 ] + nums[ i ], dp1[ i - 1 ] );
            }
        }
        for ( int i = 1; i < nums.size(); ++i ) {
            if ( i == 1 ) {
                dp2[ 1 ] = nums[ 1 ];
            } else if ( i == 2 ) {
                dp2[ 2 ] = max( nums[ 1 ], nums[ 2 ] );
            } else {
                dp2[ i ] = max( dp2[ i - 2 ] + nums[ i ], dp2[ i - 1 ] );
            }
        }
        int res = max( dp1[ nums.size() - 2 ], dp2[ nums.size() - 1 ] );
        return res;
    }
};

int main( int argc, char **argv ) {
    vector<int> input = { 2, 3, 2 };
    cout << "hello world!" << endl;
    return 0;
}
