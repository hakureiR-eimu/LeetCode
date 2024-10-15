#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void backtrace( vector<string> &ans, string item, int left, int right ) {
        if ( left == 0 && right == 0 ) {
            ans.push_back( item );
            return;
        }
        if ( left > right ) {
            return;
        }
        if ( left > 0 ) {
            backtrace( ans, item + "(", left - 1, right );
        }
        if ( right > 0 ) {
            backtrace( ans, item + ")", left, right - 1 );
        }
    }

  public:
    vector<string> generateParenthesis( int n ) {
        vector<string> ans;
        if ( n == 0 ) {
            return ans;
        }
        string item = "";
        backtrace( ans, item, n, n );
        return ans;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
