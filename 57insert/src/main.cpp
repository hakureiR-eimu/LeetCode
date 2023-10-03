#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval)
    {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (auto&& x : intervals)
        {
            if (x[0] <= ans.back()[1])
            {
                ans.back()[1] = max(ans.back()[1], x[1]);
            }
            else
                ans.push_back(x);
        }
        return ans;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
