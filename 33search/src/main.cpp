#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int search( vector<int> &nums, int target ) {
        int left = 0, right = nums.size() - 1;
        while ( left <= right ) {
            int mid = ( left + right ) / 2;
            if ( nums[ mid ] == target ) {
                return mid;
            }
            if ( nums[ left ] <= nums[ mid ] ) {
                ( target >= nums[ left ] && target < nums[ mid ] )
                    ? right = mid - 1
                    : left = mid + 1;
            } else {
                ( target > nums[ mid ] && target <= nums[ right ] )
                    ? left = mid + 1
                    : right = mid - 1;
            }
        }
        return -1;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
