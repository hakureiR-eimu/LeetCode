#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int current_max = nums[0], current_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            current_sum = nums[i] + max(current_sum, 0);
            current_max = max(current_max, current_sum);
        }
        return current_max;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
