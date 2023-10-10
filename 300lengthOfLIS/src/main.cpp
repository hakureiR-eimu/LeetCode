#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int dp[nums.size()];
        dp[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = 1;

            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int maxR = dp[0];
        for (int i = 0; i < nums.size(); ++i)
        {
            maxR = max(maxR, dp[i]);
        }
        return maxR;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
