#include <iostream>
#include <unordered_map>

using namespace std;
class Solution
{
private:
    int getNext(int n)
    {
        int nextN = 0;
        while (n)
        {
            int bit = n % 10;
            n /= 10;
            nextN += bit * bit;
        }
        return nextN;
    }

public:
    bool isHappy(int n)
    {
        unordered_map<int, bool> caled;
        caled[n] = true;
        while (n != 1)
        {
            n = getNext(n);
            if (caled[n] == true)
                return false;
            else
                caled[n] = true;
        }
        return true;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
