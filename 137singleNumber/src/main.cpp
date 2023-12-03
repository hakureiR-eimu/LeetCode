#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    int singleNumber( vector<int> &nums ) {
        // vector<int> cnts( 32, 0 );
        // for ( int num : nums ) {
        //     for ( int i = 0; i < 32; i++ ) {
        //         cnts[ i ] += ( num >> i ) & 1;
        //     }
        // }
        // int ans = 0;
        // for ( int i = 0; i < 32; i++ ) {
        //     if ( cnts[ i ] % 3 != 0 ) {
        //         ans |= 1 << i;
        //     }
        // }
        // return ans;
        vector<int> cnt( 32, 0 );
        for ( int num : nums ) {
            for ( int i = 0; i < 32; ++i ) {
                cnt[ i ] += ( num >> i ) & 1;
            }
        }
        int ans = 0;
        for ( int i = 0; i < 32; ++i ) {
            if ( cnt[ i ] % 3 != 0 ) {
                ans = ans | 1 << i;
            }
        }
        return ans;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
