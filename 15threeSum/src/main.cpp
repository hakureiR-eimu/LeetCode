#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum( vector<int> &nums ) {
        sort( nums.begin(), nums.end() );
        vector<vector<int>> res;
        int len = nums.size();
        for ( int i = 0; i < len; ++i ) {
            if ( nums[ i ] > 0 ) {
                break;
            }
            if ( i > 0 && nums[ i ] == nums[ i - 1 ] ) continue; // 去重
            int left = i + 1;
            int right = len - 1;
            while ( left < right ) {
                int sum = nums[ i ] + nums[ left ] + nums[ right ];
                if ( sum == 0 ) {
                    vector<int> index = { nums[ i ], nums[ left ],
                                          nums[ right ] };
                    res.push_back( index );
                    while ( left < right && nums[ left ] == nums[ left + 1 ] )
                        left++; // 去重
                    while ( left < right && nums[ right ] == nums[ right - 1 ] )
                        right--; // 去重
                    left++;
                    right--;

                } else if ( sum < 0 ) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
