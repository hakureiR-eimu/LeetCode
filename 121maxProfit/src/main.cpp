#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min = prices[0], max = 0;
        for(int pri:prices){
            if(pri < min) min = pri;
            if(pri > max) max = pri;
        }
        res = max - min;
        return res;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
