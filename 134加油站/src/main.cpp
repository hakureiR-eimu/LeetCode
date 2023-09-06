#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int gasSum = 0;
        int costSum = 0;
        
        int loc = start;
        for (int i:gas){
            gasSum += i ;
        }
        for(int i:cost){
            costSum += i;
        }
        if(gasSum < costSum){
            return -1;
        }
        if(n==1&&gasSum > costSum){
            return 0;
        }
        gasSum = 0;
        while(true){
            //cout <<"loc:" << loc;
            gasSum += gas[loc];
            gasSum -= cost[loc];
            if(gasSum < 0){
                //cout <<"start:" << start;
                start = (loc+1)%n;
                loc = start;
                gasSum = 0;
                continue;
            }
            loc = (loc+1)%n;
            if(loc == start) return loc;
        }
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    vector<int> gas={1,2,3,4,5};
    vector<int> cost={3,4,5,1,2};
    int res = Solution::canCompleteCircuit(gas,cost);
    cout << res;
    return 0;
}
