#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int target;
    int partition( vector<int> &arr, int l, int r ) {
        int mid = arr[ l ];
        while ( l < r ) {
            while ( l < r && arr[ r ] >= mid )
                r--;
            arr[ l ] = arr[ r ];
            while ( l < r && arr[ l ] <= mid )
                l++;
            arr[ r ] = arr[ l ];
        }
        arr[ l ] = mid;
        return l;
    }
    int sort( vector<int> &arr, int l, int r ) {
        if ( l < r ) {
            int mid = partition( arr, l, r );
            sort( arr, l, mid - 1 );
            sort( arr, mid + 1, r );
        } else {
            return l;
        }
        return -1;
    }
    void print( vector<int> &arr ) {
        for ( int it : arr ) {
            cout << it << " ";
        }
        cout << endl;
    }

    /// @brief 如果没找到,返回最接近的左指针
    /// @return
    int find( const vector<int> &arr, int target ) {
        int l = 0, r = arr.size() - 1;
        while ( l < r ) {
            int mid = ( l + r ) / 2;
            if ( arr[ mid ] > target ) {
                r = mid - 1;
            } else if ( arr[ mid ] < target ) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        cout << "l " << l << "r " << r << endl;
        return l;
    }

  public:
    bool searchMatrix( vector<vector<int>> &matrix, int target ) {
        for ( const auto &row : matrix ) {
            auto it = lower_bound( row.begin(), row.end(), target );
            if ( it != row.end() && *it == target ) {
                return true;
            }
        }
        return false;
    }
};
int main( int argc, char **argv ) {
    vector<vector<int>> matrix = { { 1, 4, 7, 11, 15 },
                                   { 2, 5, 8, 12, 19 },
                                   { 3, 6, 9, 16, 22 },
                                   { 10, 13, 14, 17, 24 },
                                   { 18, 21, 23, 26, 30 } };
    vector<int> sort{ 5, 4, 3, 2, 1 };
    Solution sol;
    bool res = sol.searchMatrix( matrix, 5 );
    cout << res << endl;
    // sol.sort( sort, 0, sort.size() - 1 );
    // sol.print( sort );
    return 0;
}
