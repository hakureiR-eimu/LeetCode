#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    int singleNumber( vector<int> &nums ) {
        int res = 0;
        for ( int i = 0; i < nums.size(); ++i ) {
            res ^= nums[ i ];
        }
        return res;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
