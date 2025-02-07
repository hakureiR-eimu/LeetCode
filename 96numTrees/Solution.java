class Solution {
    public int numTrees(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int[] dp = new int[n + 1];
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                //左边1~j-1,右边j+1~i
                if (j == 1) dp[i] += dp[i - 1];
                else if (j == i) dp[i] += dp[i - 1];
                else dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
}