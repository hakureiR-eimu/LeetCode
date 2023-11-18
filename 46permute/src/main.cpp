#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> item;
    vector<int> used;
    int numsLength;
    void dfs( vector<int> &nums, int idx ) {
        // idx == item.length();
        if ( idx == numsLength ) {
            res.push_back( item );
            return;
        }
        for ( int i = 0; i < numsLength; ++i ) {
            if ( used[ i ] ) {
                continue;
            }
            item.push_back( nums[ i ] );
            used[ i ] = 1;
            dfs( nums, idx + 1 );
            item.pop_back();
            used[ i ] = 0;
        }
    }

  public:
    vector<vector<int>> permute( vector<int> &nums ) {
        numsLength = nums.size();
        if ( numsLength == 0 ) {
            return res;
        }
        for ( int i = 0; i < numsLength; ++i ) {
            used.push_back( 0 );
        }
        dfs( nums, 0 );

        return res;
    }
};

int main( int argc, char **argv ) {
    vector<int> nums = { 1, 2, 3 };
    Solution *p = new Solution;
    vector<vector<int>> res = p->permute( nums );
    for ( int i = 0; i < res.size(); ++i ) {
        for ( int j = 0; j < res.size(); ++j ) {
            cout << res[ i ][ j ] << " ";
        }
        cout << endl;
    }
    cout << "hello world!" << endl;
    return 0;
}
