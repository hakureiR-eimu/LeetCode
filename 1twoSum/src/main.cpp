#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (map.count(nums[i]))
            {
                res.push_back(i);
                res.push_back(map[nums[i]]);
                return res;
            }
            map[target - nums[i]] = i;
        }
        return res;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
