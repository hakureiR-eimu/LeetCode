#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int p1 = 0, p2 = height.size() - 1;
        int area = 0;
        while (p1 != p2)
        {
            int h = min(height[p1], height[p2]);
            area = max(area, h * (p2 - p1));
            if (height[p1] > height[p2])
            {
                p2--;
            }
            else
            {
                p1++;
            }
        }
        return area;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
