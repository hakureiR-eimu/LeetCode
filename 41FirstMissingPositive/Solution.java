import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int firstMissingPositive(int[] nums) {
        //给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
        //如果有哈希表
        //长度为n的nums 结果一定位于[1,n+1]当中 创建长度为n+2的哈希表 就可以得出结果了
        int n = nums.length;
        int[] numToIndex = new int[n + 2];
        Arrays.fill(numToIndex, -1);
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 1 && nums[i] <= n) {
                numToIndex[nums[i]] = i;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n + 1; ++i) {
            if (numToIndex[i] == -1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
}