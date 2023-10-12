#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ret = 0;
        while (n)
        {
            n &= n - 1;
            ret++;
        }
        return ret;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
