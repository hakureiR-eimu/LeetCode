class Solution {
    public int singleNonDuplicate(int[] nums) {
        //0-1 2-3 。。。 2k-2k+1 2k+2 2k+3-2k+4
        //我们希望通过left mid right一次性排除掉一半的范围，当left==right就是答案
        //如果mid是偶数
        // mid==mid+1则target在mid+1的右边
        // mid==mid-1 则target在mid的左边
        // 都不是 则mid就是唯一

        //如果mid是奇数
        //mid==mid+1 则targer在mid左边
        //mid==mid-1 则targer在mid右边
        //都不是 mid就是唯一
        int left = 0, right = nums.length - 1;
        //我们希望target在[left,right]当中
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0) {
                if (mid + 1 < nums.length && nums[mid] == nums[mid + 1]) {
                    left = mid + 2;
                } else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                    right = mid - 2;
                } else {
                    return nums[mid];
                }
            } else {
                if (mid + 1 < nums.length && nums[mid] == nums[mid + 1]) {
                    right = mid - 1;
                } else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                } else {
                    return nums[mid];
                }
            }
        }
        return 0;
    }
}