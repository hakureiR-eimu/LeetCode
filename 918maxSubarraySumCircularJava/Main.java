public class Main {
    public static void main(String[] args) {
        int[] nums = {1, -2, 3, -2};
        Solution sol = new Solution();
        int ans = sol.maxSubarraySumCircular(nums);
    }
}

class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        //[0,i]&&[j,n-1]
        int[] leftMax = new int[nums.length];
        leftMax[0] = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            sum += nums[i];
            leftMax[i] = Math.max(leftMax[i - 1], sum);
        }
        int res = Integer.MIN_VALUE;
        int right = 0;

        for (int i = nums.length - 1; i > 0; --i) {

            res = Math.max(res, right + leftMax[i - 1]);
            right += nums[i];
        }
        right += nums[0];
        res = Math.max(res, right);

        int res1 = Integer.MIN_VALUE;
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
            res1 = Math.max(res1, dp[i]);
        }
        res = Math.max(res, res1);
        return res;
    }
}