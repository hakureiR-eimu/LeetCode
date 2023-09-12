#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length()-1;
        while(s[end] == ' '){
            end --;
        }
        int start = end;
        while(s[start] != ' '){
            if(start == 0){
                start --;
                break;
            }
            start --;
        }
        return end - start;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
