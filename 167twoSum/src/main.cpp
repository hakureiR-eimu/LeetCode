#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum( vector<int> &numbers, int target ) {
        vector<int> res;
        int index1 = 0;
        int index2 = numbers.size() - 1;
        // cout << "index1:" << index1 << " index2:" << index2 << endl;
        // cout << numbers[ index1 ] << numbers[ index2 ] << endl;
        while ( 1 ) {
            if ( index1 > index2 ) {
                return res;
            }
            if ( numbers[ index1 ] + numbers[ index2 ] == target ) {
                res.push_back( index1 + 1 );
                res.push_back( index2 + 1 );
                // cout << "index1:" << index1 << " index2:" << index2 << endl;
                return res;
            }
            if ( numbers[ index1 ] + numbers[ index2 ] < target ) {
                index1++;
                // cout << "index1:" << index1 << " index2:" << index2 << endl;
            } else {
                index2--;
                // cout << "index1:" << index1 << " index2:" << index2 << endl;
            }
        }
    }
};

int main( int argc, char **argv ) {
    vector<int> numbers = { 2, 7, 11, 15 };
    int tar = 9;
    Solution *p = new Solution;
    p->twoSum( numbers, tar );

    cout << "hello world!" << endl;
    return 0;
}
