// 283MoveZerosCpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::cout << "Hello World!\n";
}

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int zeroNum = 0;
        for (int i = 0;i < nums.size();++i) {
            nums[index] = nums[i];
            if (nums.at(i) != 0) {
                index++;
            }
            else {
                zeroNum++;
            }
        }
        for (int i = nums.size() - zeroNum;i < nums.size();++i) {
            nums[i] = 0;
        }
        
    }
};
