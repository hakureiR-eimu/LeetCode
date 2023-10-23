#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int candy( vector<int> &ratings ) {
        const int n = ratings.size();
        if ( n == 0 ) return 0;
        if ( n == 1 ) return 1;
        int *result = new int[ n ]{ 1 };
        for ( int i = 0; i < n; ++i ) {
            result[ i ] = 1;
        }
        int ans = 0;
        // int  pre    = ratings[ 0 ];
        for ( int i = 1; i < n; ++i ) {
            if ( ratings[ i ] > ratings[ i - 1 ] ) {
                result[ i ] = result[ i - 1 ] + 1;
            }
            // pre = ratings[ i ];
        }
        // pre = ratings[ n - 1 ];
        for ( int i = n - 2; i >= 0; --i ) {
            if ( ratings[ i ] > ratings[ i + 1 ] &&
                 result[ i ] <= result[ i + 1 ] ) {
                result[ i ] = result[ i + 1 ] + 1;
            }
            // pre = ratings[ i ];
        }
        for ( int i = 0; i < n; ++i ) {
            ans += result[ i ];
        }
        return ans;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
