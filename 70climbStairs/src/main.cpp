#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    int dp[50] = {0};

public:
    int climbStairs(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                dp[i] = 1;
            else if (i == 2)
                dp[i] = 2;
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
