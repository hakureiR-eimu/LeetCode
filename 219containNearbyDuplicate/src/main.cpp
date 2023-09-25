#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> valToIndex;
        for (int i = 0; i < n; ++i)
        {
            if (valToIndex.count(nums[i]) && i - valToIndex[nums[i]] <= k)
                return true;
            valToIndex[nums[i]] = i;
        }
        return false;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
