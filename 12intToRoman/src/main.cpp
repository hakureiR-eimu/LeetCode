#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> map = {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };
        
        return "11";
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
