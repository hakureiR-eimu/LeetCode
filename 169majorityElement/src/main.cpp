#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    static int majorityElement(vector<int>& nums) {
        stack<int> s;
        for(const auto& elem:nums){
            if(s.empty()||s.top() == elem){
                s.push(elem);
            }
            else {
                s.pop();
            }
        } 
        int res = s.top();
        return res;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    vector<int> nums={3,3,4};
    cout << Solution::majorityElement(nums) << endl;
    return 0;
}
