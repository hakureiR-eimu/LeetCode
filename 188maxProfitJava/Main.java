import java.util.*;

public class Main {
}

class Solution {
    public int maxProfit(int k, int[] prices) {
        k = Math.min(k, prices.length / 2);
        int nop;
        int[][] buys = new int[prices.length][k];
        int[][] sells = new int[prices.length][k];

        if (prices.length == 0 || k == 0) return 0;
        nop = 0;
        Arrays.fill(buys[0], -prices[0]);
        //buy0,buy1,sell0,sell1
        //
        for (int i = 1; i < prices.length; ++i) {
            buys[i][0] = Math.max(buys[i - 1][0], -prices[i]);
            sells[i][0] = Math.max(sells[i - 1][0], buys[i - 1][0] + prices[i]);
            for (int j = 1; j < k; ++j) {
                buys[i][j] = Math.max(buys[i - 1][j], sells[i - 1][j - 1] - prices[i]);
                sells[i][j] = Math.max(sells[i - 1][j], buys[i - 1][j] + prices[i]);
            }
        }
        int max = -1;
        for (int i = 0; i < k; ++i) {
            max = Math.max(sells[prices.length - 1][i], max);
        }
        return max;
    }
}