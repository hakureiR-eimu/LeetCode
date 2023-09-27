#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s2 = to_string(x);
        string s = to_string(x);
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != s2[i]) return false;
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
