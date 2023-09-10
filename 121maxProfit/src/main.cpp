#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        int minP[100000] = {0};
        int max = 0;
        for(int i = 0; i < n; ++i){
            if(i == 0){
                minP[0] = prices[0];
                max = 0;;
            }
            else {
                minP[i] = min(minP[i-1],prices[i]);
                max = ( prices[i] - minP[i] )> max ? prices[i] - minP[i] : max;
            }
        }

        return max;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
