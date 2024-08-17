#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {

  public:
    vector<int> topKFrequent( vector<int> &nums, int k ) {
        unordered_map<int, int> hash;
        for ( auto &item : nums ) {
            if ( hash[ item ] ) {
                hash[ item ]++;
            } else {
                hash[ item ] = 1;
            }
        }
        auto cmp = [ &hash ]( int a, int b ) { return hash[ a ] > hash[ b ]; };
        priority_queue<int, vector<int>, decltype( cmp )> pq( cmp );

        for ( auto &[ num, count ] : hash ) {
            if ( pq.size() < k ) {
                pq.push( num );
            } else if ( count > hash[ pq.top() ] ) {
                pq.pop();
                pq.push( num );
            }
        }
        vector<int> res;
        while ( !pq.empty() ) {
            res.emplace_back( pq.top() );
            pq.pop();
        }
        return res;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
