public class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        /**
         * 在target不存在的情况下，为什么l代表了插入位置
         * 假设l=k r=k+1 nums[l]<target<nums[r] mid=k 应该返回k+1 在循环结束以后 l=k+1 r=k+1 应该返回l
         * 假设l=k r=k mid=k nums[k]<target  则应该返回k+1 在循环结束以后 l=k+1 r=k 应该返回l
         * 假设l=k r=k mid=k nums[k]>target 则应该返回k    在循环结束以后 l=k r=k-1 应该返回l
         * 综上，应该返回l
         */
        return l;
    }
}