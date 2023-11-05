#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> searchRange( vector<int> &nums, int target ) {
        int left = 0, right = nums.size() - 1;
        int mid = ( left + right ) / 2;
        int pos;
        vector<int> res;
        while ( 1 ) {
            if ( left > right ) {
                res.push_back( -1 );
                res.push_back( -1 );
                return res;
            }
            int mid = ( left + right ) / 2;
            if ( nums[ mid ] == target ) {
                pos = mid;
                break;
            } else if ( nums[ mid ] > target ) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        left = pos;
        right = pos;
        while ( left - 1 >= 0 && nums[ left - 1 ] == target ) {
            left--;
        }
        while ( right + 1 < nums.size() && nums[ right + 1 ] == target ) {
            right++;
        }
        res.push_back( left );
        res.push_back( right );
        return res;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    vector<int> params = { 1, 2, 3, 4, 5, 6, 6, 6, 8, 10 };
    Solution *p = new Solution();
    vector<int> res = p->searchRange( params, 1 );
    cout << res[ 0 ] << "," << res[ 1 ] << endl;
    return 0;
}
