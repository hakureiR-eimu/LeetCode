#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    static bool isSubsequence(string s, string t) {
        int m = s.length(),n = t.length();
        int i = 0,j= 0;
        while(i<m&&j<n){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==m;
    }
};
int main(int argc, char** argv)
{
    string s ="abc",t ="ahbgdc";
    cout << Solution::isSubsequence(s,t) <<endl;
    cout << "hello world!" << endl;
    return 0;
}
