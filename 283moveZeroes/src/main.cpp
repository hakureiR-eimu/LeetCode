#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
  public:
    void moveZeroes( vector<int> &nums ) {
        if ( nums.size() == 0 ) {
            return;
        }
        int i = 0, j = 0;
        int num = 0;
        while ( j < nums.size() ) {
            while ( j < nums.size() && nums[ j ] == 0 ) {
                num++;
                j++;
            }
            if ( j < nums.size() ) nums[ i ] = nums[ j ];
            i++;
            j++;
        }
        for ( int i = nums.size() - num; i < nums.size(); ++i ) {
            nums[ i ] = 0;
        }
    }
};
int main( int argc, char **argv ) {
    vector<int> qus = { 0, 1, 0, 3, 12 };
    Solution a;
    a.moveZeroes( qus );
    for ( auto item : qus ) {
        cout << item << endl;
    }
    cout << "hello world!" << endl;
    return 0;
}
