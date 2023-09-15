#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > k)
                return false;
            else
                k = max(k, i + nums[i]);
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
