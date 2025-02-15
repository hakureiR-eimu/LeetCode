import java.util.Arrays;

public class Main {

}

class Solution {
    public int maxProfit(int[] prices) {
        int[][] dp = new int[prices.length][2];
        if (prices.length == 0) return 0;
        //0持有股票的资金 1不持有股票的资金
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.length; ++i) {
            dp[i][0] = Math.max(dp[i - 1][0], -prices[i]);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        System.out.println(Arrays.deepToString(dp));
        return dp[prices.length - 1][1];
    }
}
