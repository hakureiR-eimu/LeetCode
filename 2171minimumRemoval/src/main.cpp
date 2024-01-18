#include <algorithm>
#include <iostream>
#include <vector>

#include <algorithm>

class Solution {
  public:
    long long minimumRemoval( std::vector<int> &beans ) {
        int length = beans.size();
        std::sort( beans.begin(), beans.end() );
        long long sum = 0;
        long long res = 0;
        // return min(sum-(length-index)*x_index)
        // find max(length-index)*x_index
        for ( int index = 0; index < length; index++ ) {
            sum += beans[ index ];
            res = std::max( ( ( (long long) length - index ) * beans[ index ] ),
                            res );
        }
        res = sum - res;
        return res;
    }
};
int main( int argc, char **argv ) {
    std::cout << "hello world!" << std::endl;
    return 0;
}
