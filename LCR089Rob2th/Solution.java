class Solution {
    public int rob(int[] nums) {
        int[][] dp = new int[nums.length][2];
        //dp i 0 表示偷第i家的最大值
        //dp i 1 表示不偷第i家的最大值
        for (int i = 0; i < nums.length; ++i) {
            dp[i][0] = i - 2 < 0 ? nums[i] : Math.max(dp[i - 2][0], dp[i - 2][1]) + nums[i];
            dp[i][1] = i - 1 < 0 ? 0 : Math.max(dp[i - 1][0], dp[i - 1][1]);
        }
        return Math.max(dp[nums.length - 1][0], dp[nums.length-1][1]);
    }
}