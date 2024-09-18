#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int evalRPN( vector<string> &tokens ) {
        stack<int> stk;
        for ( auto &item : tokens ) {
            if ( item == "+" ) {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push( a + b );
            } else if ( item == "-" ) {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push( b - a );
            } else if ( item == "*" ) {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push( a * b );
            } else if ( item == "/" ) {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push( b / a );
            } else {
                int a = stoi( item );
                stk.push( a );
            }
        }
        int res = stk.top();
        return res;
    }
};
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
