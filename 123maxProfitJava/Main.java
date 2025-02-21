import java.util.*;

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] prices = {3, 3, 5, 0, 0, 3, 1, 4};
        sol.maxProfit(prices);
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        //dp[i][j][k] i代表第i天 j代表正在进行第j次交易 k代表状态 0是不持有 1是持有 数组值代表当前金额
        //dp[i][j][k] j=1不需要考虑j
        //先算j=1再算j=2
        //在i-1天结束 存在以下状态
        //不曾买入，已第一次买入，以完成第一次交易，以第二次买入，以第二次完成
        int nop, buy1, sell1, buy2, sell2;
        if (prices.length == 0) return 0;
        nop = 0;
        buy1 = -prices[0];
        sell1 = 0;
        buy2 = -prices[0];
        sell2 = 0;
        for (int i = 1; i < prices.length; ++i) {
            sell2 = Math.max(sell2, buy2 + prices[i]);
            buy2 = Math.max(sell1 - prices[i], buy2);
            sell1 = Math.max(sell1, buy1 + prices[i]);
            buy1 = Math.max(buy1, -prices[i]);

        }
        return sell2;
    }
}