#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findPeakElement( vector<int> &nums ) {
        int l = 0, r = nums.size() - 1, m;
        while ( l < r ) {
            m = l + ( r - l ) / 2;
            if ( nums[ m ] > nums[ m + 1 ] ) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
