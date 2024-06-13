#include <iostream>
#include <vector>
class Solution {
  public:
    int minOperationsMaxProfit( std::vector<int> &customers, int boardingCost,
                                int runningCost ) {
        int maxProfitEach = 4 * boardingCost - runningCost;
        if ( maxProfitEach <= 0 ) {
            return -1;
        }
    }
};
int main( int argc, char **argv ) { return 0; }
