#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int cf = 0;
        string res = "";
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0;
             --i, --j)
        {
            int sum = cf;
            if (i >= 0) sum += a[i] - '0';
            if (j >= 0) sum += b[j] - '0';
            res += to_string(sum % 2);
            cf = sum / 2;
        }
        if (cf != 0) res += to_string(cf);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
