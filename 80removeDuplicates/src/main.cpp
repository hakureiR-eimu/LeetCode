#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeKDuplicates(vector<int>& nums, int k)
    {
        int len = 0;
        for (auto x : nums)
        {
            if (len < k || nums[len - k] != x)
            {
                nums[len] = x;
                len++;
            }
        }
        return len;
    }
    int removeDuplicates(vector<int>& nums)
    {
        return removeKDuplicates(nums, 2);
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
