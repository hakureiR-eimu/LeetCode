#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static vector<string> summaryRanges(vector<int>& nums){
        int p1 = 0;
        vector<string> res;
        int low = 0;
        while(low < nums.size()){
            int high = low;
            while(high + 1 < nums.size() && nums[high+1] == nums[high]+1){
                high++;
            }
            
            if(low == high){
                string temp = to_string(nums[low]);
                res.push_back(temp);
            }
            else {
                string temp = to_string(nums[low]) + "->" + to_string(nums[high]);
                res.push_back(temp);
            }
            low = high+1;
        }
        return res;
    }
};
int main(int argc, char** argv)
{
    vector<int> nums = {0,1,2,4,5,7};
    vector<string> res = Solution::summaryRanges(nums);
    for(string ch:res){    
        cout << ch << endl;
    }    
    return 0;
}
