#include <iostream>

using namespace std;

class Solution {
  public:
    double quickMul( double x, long long N ) {
        double ans = 1.0;
        double x_pow = x;
        while ( N > 0 ) {
            if ( N % 2 == 1 ) {
                ans *= x_pow;
            }
            x_pow *= x_pow;
            N /= 2;
        }
        return ans;
    }
    double myPow( double x, int n ) {
        long long N = n;
        return N >= 0 ? quickMul( x, N ) : 1.0 / quickMul( x, -N );
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
