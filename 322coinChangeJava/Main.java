import java.util.*;

public class Main {
}

class Solution {
    public int coinChange(int[] coins, int amount) {
        int max = 0x3f3f3f3f;
        int[][] dp = new int[coins.length][amount + 1];
        for (int i = 0; i < coins.length; ++i) {
            Arrays.fill(dp[i], -1);
        }
        for (int i = 0; i < coins.length; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < coins.length; ++i) {
            for (int j = 1; j <= amount; ++j) {

                int min = max;
                if (j - coins[i] >= 0 && dp[i][j - coins[i]] != -1) min = Math.min(min, dp[i][j - coins[i]] + 1);
                if (i != 0 && dp[i - 1][j] != -1) min = Math.min(min, dp[i - 1][j]);
                if (min == max) dp[i][j] = -1;
                else dp[i][j] = min;
            }
        }
        return dp[coins.length - 1][amount];
    }
}