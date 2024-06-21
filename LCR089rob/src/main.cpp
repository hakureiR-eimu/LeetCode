#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int rob( vector<int> &nums ) {
        int dp[ 105 ];
        for ( int i = 0; i < nums.size(); ++i ) {
            if ( i == 0 ) {
                dp[ i ] = nums[ i ];
            } else if ( i == 1 ) {
                dp[ i ] = max( dp[ 0 ], nums[ 1 ] );
            } else {
                dp[ i ] = max( dp[ i - 1 ], nums[ i ] + dp[ i - 2 ] );
            }
        }
        return dp[ nums.size() - 1 ];
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
