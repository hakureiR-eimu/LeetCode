#include <iostream>

using namespace std;

class Solution
{
private:
    int s;
    double sqrts(double x)
    {
        double res = (x + s / x) / 2;
        if (res == x)
            return x;
        else
            return sqrts(res);
    }

public:
    int mySqrt(int x)
    {
        s = x;
        if (x == 0) return 0;
        return ((int)(sqrts(x)));
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
