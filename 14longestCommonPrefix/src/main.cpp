#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        string tar = strs[0];
        for(string mat:strs){
            if(mat == tar) continue;
            else tar = longestCommonPrefix(tar,mat);
        }
        return tar;
    }
    string longestCommonPrefix(string s1,string s2){
        int len = min(s1.length(),s2.length());
        int index = 0;
        if(s1[0]!=s2[0]){
            return "";
        }
        while(index < len && s1[index] == s2[index]){
            index ++;
        }
        return s1.substr(0,index);
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
