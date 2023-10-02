#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int plus(vector<int>& digits, int num, int cf)
    {
        if (cf == 0) return 0;
        if (cf == 1)
        {
            int& k = digits[num];
            if (k != 9)
            {
                k++;
                return 0;
            }
            else if (k == 9 && num == 0)
            {
                k = 0;
                digits.insert(digits.begin(), 1);
            }
            else
            {
                k = 0;
                num--;
                return 1;
            }
        }
        return 0;
    }

public:
    vector<int> plusOne(vector<int>& digits)
    {
        int num = digits.size() - 1;
        int cf = 1;
        while (cf == 1 && num >= 0)
        {
            cf = plus(digits, num, cf);
            num--;
        }
        return digits;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
