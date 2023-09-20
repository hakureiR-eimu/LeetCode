#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> l(nums.size(), 1);
        vector<int> r(nums.size(), 1);
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            l[i] = l[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            r[i] = r[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            res[i] = l[i] * r[i];
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
