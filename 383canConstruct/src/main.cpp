#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length()){
            return false;
        }
        int cnt[26]={0};
        for(char ch:magazine){
            cnt[ch-'a'] ++;
        }
        for(char ch:ransomNote){
            cnt[ch-'a']--;
            if(cnt[ch-'a']<0){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
