#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        if (points.size() == 1) return 1;
        // vector<vector<int>> ans;
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        // sort(points.begin(), points.end());
        int ans = 1;
        int pos = points[0][1];
        for (auto&& x : points)
        {
            if (x[0] > pos)
            {
                pos = x[1];
                ans += 1;
            }
        }
        return ans;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
