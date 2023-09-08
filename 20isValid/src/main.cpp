#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> m ={
            { ')','('},
            { '}','{'},
            { ']','['},
            { '"','"'}
        };
        for (char ch:s){
            if(stk.empty()){
                stk.push(ch);
            }
            else if(stk.top() == m[ch]){
                stk.pop();
            }
            else stk.push(ch);
        }
        if(stk.empty()) return true;
        return false;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
