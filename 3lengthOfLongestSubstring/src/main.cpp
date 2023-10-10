#include <cstdint>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = 0, max = INT32_MIN;
        int length;
        int letters[26] = {0};
        if (s.length() == 0) return 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (letters[s[i]] == 0)
            {
                letters[s[i]]++;
                r = i;
                length = r - l + 1;
                if (length > max) max = length;
            }
            else if (letters[s[i]] == 1)
            {
                letters[s[i]] = 0;
                r = i;
                l++;
                length
            }
        }
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
