#include <iostream>

using namespace std;
class Solution {
  public:
    string convert( string s, int numRows ) {
        if ( numRows == 1 ) {
            return s;
        }
        char matrix[ 1001 ][ 1001 ];
        int base = 2 * numRows - 2;
        int index;
        int couple;
        int len = s.length();
        string res = "";
        for ( int i = 0; i < numRows; ++i ) {
            if ( i == 0 ) {
                int index = base * 0;
                while ( index < len ) {

                    res.push_back( s[ index ] );

                    //cout << index << endl;

                    index += base;
                }
            } else if ( i == numRows - 1 ) {
                int index = numRows - 1;
                while ( index < len ) {
                    res.push_back( s[ index ] );

                    //cout << index << endl;

                    index += base;
                }
            } else {
                int index1 = base * 0 + i;
                int index2 = base * 0 + base - i;
                while ( 1 ) {
                    int flag = 0;
                    if ( index1 < len ) {
                        res.push_back( s[ index1 ] );

                        flag++;
                    }
                    index1 += base;
                    if ( index2 < len ) {
                        res.push_back( s[ index2 ] );
                        flag++;
                    }
                    index2 += base;
                    if ( flag == 0 ) {
                        break;
                    }
                }
            }
        }
        //cout << res << endl;
        return res;
    }
};

int main( int argc, char **argv ) {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    Solution *p = new Solution;
    string res = p->convert( s, numRows );

    cout << res << endl;
    return 0;
}
