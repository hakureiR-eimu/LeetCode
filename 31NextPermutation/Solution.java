class Solution {
    public void nextPermutation(int[] nums) {
        //1. 从右向左找出第一个升序对 i,i+1
        //2, 从右向左找到一个大于i的下标j 交换i和j使得字典序扩大
        //3, 翻转i+1: 使得字典序降低 使得字典序严格恰好大于
        if (nums.length == 1) {
            return;
        }
        int i = nums.length - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) {
                //找到i右侧第一个大于i的 交换使得字典序增加
                //反转i+1到结尾 使得字段序减少
                int j = nums.length - 1;
                while (nums[j] <= nums[i]) {
                    j--;
                }
                swap(nums, i, j);
                reverse(nums, i + 1);
                return;
            } else {
                i--;
            }
        }
        reverse(nums, 0);
        return;
    }

    private void reverse(int[] nums, int i) {
        int j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}