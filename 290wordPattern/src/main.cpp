#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> patternToString;
        unordered_map<string, char> stringToPattern;
        vector<string> arrS;
        string tmp = "";
        s += ' ';
        for (char ch : s)
        {
            if (ch == ' ')
            {
                arrS.push_back(tmp);
                tmp = "";
            }
            else
            {
                tmp += ch;
            }
        }

        // cout << arrS.size() << endl;
        // for (string tmp : arrS)
        // {
        //     cout << tmp << endl;
        // }
        if (pattern.length() != arrS.size())
        {
            return false;
        }
        int n = arrS.size();
        for (int i = 0; i < n; ++i)
        {
            if (patternToString.count(pattern[i]) &&
                patternToString[pattern[i]] != arrS[i])
                return false;
            if (stringToPattern.count(arrS[i]) &&
                stringToPattern[arrS[i]] != pattern[i])
                return false;
            patternToString[pattern[i]] = arrS[i];
            stringToPattern[arrS[i]] = pattern[i];
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    string pattern = "abba", s = "dog cat cat dog";
    Solution* p = new Solution();
    bool res = p->wordPattern(pattern, s);
    cout << res << endl;
    return 0;
}
