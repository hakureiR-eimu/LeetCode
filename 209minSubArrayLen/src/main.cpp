#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int start = 0, end = 0;
        int ans = INT32_MAX;
        int sum = 0;
        while (end < nums.size())
        {
            sum += nums[end];
            while (sum >= target)
            {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
