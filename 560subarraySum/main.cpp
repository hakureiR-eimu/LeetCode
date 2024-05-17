// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k
// 的子数组的个数 。

// 子数组是数组中元素的连续非空序列。

#include <algorithm>
#include <vector>

class Solution {
  public:
    int subarraySum( std::vector<int> &nums, int k ) {
        std::vector<int> copy;
        copy.assign( nums.begin(), nums.end() );
        return 0;
    }
};

int main( int argc, char *argv[] ) { return 0; }