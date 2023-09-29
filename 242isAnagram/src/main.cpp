#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int s26[26] = {0}, t26[26] = {0};
        if (s.length() != t.length()) return false;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            s26[s[i] - 'a']++;
            t26[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (s26[i] != t26[i]) return false;
        }
        return true;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
