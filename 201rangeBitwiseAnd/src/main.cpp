#include <iostream>

using namespace std;

class Solution {
  public:
    int rangeBitwiseAnd( int left, int right ) {
        int shift = 0;
        while ( left < right ) {
            right = right & ( right - 1 );
        }
        return right;
    }
};

int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
