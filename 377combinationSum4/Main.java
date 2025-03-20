public class Main {
}

class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[][] dp = new int[nums.length + 1][target + 1];
        for (int i = 0; i <= nums.length; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= target; ++j) {
            for (int i = 1; i <= nums.length; ++i) {
                dp[i][j] = dp[i - 1][j];
                if (j - nums[i - 1] >= 0) {
                    dp[i][j] += dp[nums.length][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.length][target];
    }
}