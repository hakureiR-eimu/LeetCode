#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> item;
    vector<vector<int>> res;
    void pushItem( int n, int k, int index ) {
        if ( item.size() == k ) {
            res.push_back( item );
            return;
        }
        for ( int i = index; i <= n; ++i ) {
            item.push_back( i );
            pushItem( n, k, i + 1 );
            item.pop_back();
        }
    }

  public:
    vector<vector<int>> combine( int n, int k ) {
        if ( n < k ) return res;
        pushItem( n, k, 1 );
        return res;
    }
};

int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
