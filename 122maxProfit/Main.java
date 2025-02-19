public class Main {
    public static void main(String[] args) {

    }
}

class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;
        //0代表没有股票，1代表有股票
        int[][] dp = new int[prices.length][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.length; ++i) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[prices.length - 1][0];

    }
}
