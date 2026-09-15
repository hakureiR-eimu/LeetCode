public class Main {
}

class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length;
        //性质，nums[left]<nums[left+1];nums[right]>nums[right-1]并且以此类推。只存在唯一点index,nums[index-1]>nums[index]（也可能不存在）
        //二分查找，找到下标index。nums[index]>nums[left];nums[index]<

        //确保[left,right]包含最小值的下标，不断缩小left和right的范围，直到left=right，所得即为最小值
        while (left < right) {
            int mid = left + (right - left) >> 1;
            if (nums[left] < nums[mid] && nums[mid] < nums[right]) {
                right=mid;
            }
        }
        return 0;
    }
}