#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> generate( int numRows ) {
        vector<vector<int>> ans;
        for ( int i = 0; i < numRows; ++i ) {
            vector<int> row;
            for ( int j = 0; j < i + 1; ++j ) {
                int val;
                if ( j == 0 || j == i ) {
                    val = 1;
                } else {
                    val = ans[ i - 1 ][ j - 1 ] + ans[ i - 1 ][ j ];
                }
                row.emplace_back( val );
            }
            ans.emplace_back( row );
        }
        return ans;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
