#include <iostream>

using namespace std;

class Solution {
  public:
    int trailingZeroes( int n ) {
        int ans = 0;
        for ( int i = 5; i <= n; i += 5 ) {
            int j = i;
            while ( j % 5 == 0 ) {
                j /= 5;
                ans++;
            }
        }
        return ans;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
