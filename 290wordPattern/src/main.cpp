#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> patternToS;
        unordered_map<string, char> sToPattern;
        if(pattern.length() != s.length()){
            return false;
        }
        


    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
