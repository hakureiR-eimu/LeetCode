#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    void getNext(string needle, int* next)
    {
        next[0] = -1;
        int i = 0, j = -1;
        while (i < needle.length() - 1)
        {
            if (j == -1 || needle[i] == needle[j])
            {
                ++i;
                ++j;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
    }

public:
    int strStr(string haystack, string needle)
    { // hatstack:long needle:short
        if (!haystack.length() || !needle.length()) return -1;
        int n = haystack.length(), m = needle.length();
        int next[m];
        getNext(needle, next);
        /*         for (int i = 0; i < m; ++i)
                {
                    cout << next[i] << endl;
                } */
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == needle.length())
        {
            return i - j;
        }
        else
        {
            return -1;
        }
    }
};

int main(int argc, char** argv)
{
    Solution sol = *new Solution();
    string haystack = "leetcode";
    string needle = "leet";
    int res = sol.strStr(haystack, needle);
    cout << res << endl;
    return 0;
}
