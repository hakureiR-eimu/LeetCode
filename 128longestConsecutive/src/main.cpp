#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestConsecutive( vector<int> &nums ) {
        unordered_set<int> hash;
        // int hash[ 200005 ] = { 0 };
        for ( int num : nums ) {
            hash.insert( num );
        }
        int maxLength = 0;
        for ( int num : nums ) {
            if ( hash.find( num - 1 ) == hash.end() ) {
                int len = 0;
                while ( hash.find( num ) != hash.end() ) {
                    len++;
                    num++;
                }
                maxLength = max( maxLength, len );
            }
        }
        return maxLength;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
