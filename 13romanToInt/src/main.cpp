#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static int romanToInt(string s) {
        unordered_map<char, int> map = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans = 0;
        int n = s.length();
        for(int i=0; i<n ; ++i){
            int value = map[s[i]];
            //cout << value << endl;
            if(i < n-1 && value < map[s[i+1]] ){
                ans -=value;
                //cout << map[s[i+1]] << endl;
            }
            else ans += value;
        }
        return ans;
    }
};

int main(int argc, char** argv)
{
    cout << Solution::romanToInt("III") << endl;
    return 0;
}
