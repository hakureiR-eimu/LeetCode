#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static bool isIsomorphic(string s, string t) {
        int asciiS[256] = {0};
        int asciiT[256] = {0};
        int cnt = 0;
        for (char ch : s){
            asciiS[ch] = 1;
        }
        for(char ch : t){
            asciiT[ch] = 1;
        }
        for(int i = 0; i<256; ++i){
            if(asciiS[i] == 1) cnt++;
            if(asciiT[i] == 1) cnt--;
        }
        cout << cnt <<endl;
        if(cnt == 0) return true;
        else return false;
    }
};

int main(int argc, char** argv)
{
    string s = "bbbaaaba" , t = "aaabbbba";
    bool res = Solution::isIsomorphic(s,t);
    cout << res <<endl; 
    return 0;
}
