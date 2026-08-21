import java.util.Arrays;

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        if (cost.length == 1) return 0;
        int[] dp = new int[cost.length + 1];
        int maxInt = Integer.MAX_VALUE;
        Arrays.fill(dp, maxInt);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 0; i < cost.length; ++i) {
            if (i + 1 <= cost.length) {
                dp[i + 1] = Math.min(dp[i + 1], dp[i] + cost[i]);
            }
            if (i + 2 <= cost.length) {
                dp[i + 2] = Math.min(dp[i + 2], dp[i] + cost[i]);
            }
        }
        return dp[cost.length];
    }
}