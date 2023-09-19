#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static int trap(vector<int>& height)
    {
        int maxColl[height.size()];
        int maxColr[height.size()];
        for (int i = 0; i < height.size(); ++i)
        {
            if (i == 0) maxColl[i] = 0;
            else
            {
                int maxl   = max(maxColl[i - 1], height[i - 1]);
                maxColl[i] = maxl;
            }
        }
        for (int i = height.size() - 1; i >= 0; --i)
        {
            if (i == height.size() - 1) maxColr[i] = 0;
            else
            {
                int maxr   = max(maxColr[i + 1], height[i + 1]);
                maxColr[i] = maxr;
            }
        }
        int sum = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            int sumc = min(maxColl[i], maxColr[i]) - height[i];
            if (sumc >= 0) sum += sumc;
        }
        return sum;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
