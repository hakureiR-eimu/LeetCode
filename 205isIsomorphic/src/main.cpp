#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static bool isIsomorphic(string s, string t) {
        int asciiS[256] = {0};
        int asciiT[256] = {0};
        if(s.length() != t.length()){
            return false;
        }
        for(int i = 0; i < s.length(); ++i){
            if(asciiS[s[i]] != asciiT[t[i]]) return false;
            asciiS[s[i]] = i+1;
            asciiT[t[i]] = i+1;
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    string s = "bbbaaaba" , t = "aaabbbba";
    bool res = Solution::isIsomorphic(s,t);
    cout << "res" << res <<endl; 
    return 0;
}
