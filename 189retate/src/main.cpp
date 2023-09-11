#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start],nums[end]);
            start ++;
            end --;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = k % nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,n-1);
        reverse(nums,n,nums.size()-1);
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
