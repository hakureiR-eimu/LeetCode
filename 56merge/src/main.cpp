#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> merged;
        if (! intervals.size()) return merged;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); ++i)
        {
            int l = intervals[i][0], r = intervals[i][1];
            if (! merged.size() || merged.back()[1] < l)
            {
                merged.push_back({l, r});
            }
            else
            {
                merged.back()[1] = max(r, merged.back()[1]);
            }
        }
        return merged;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
