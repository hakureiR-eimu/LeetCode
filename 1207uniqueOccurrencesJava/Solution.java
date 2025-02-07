import java.util.*;

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int[][] dp = new int[triangle.size()][];
        for (int i = 0; i < triangle.size(); ++i) {
            dp[i] = new int[triangle.get(i).size()];
            if (i == 0) dp[0][0] = triangle.get(i).get(0);
            else {
                for (int j = 0; j < dp[i].length; ++j) {
                    if (j == 0) dp[i][j] = dp[i - 1][j] + triangle.get(i).get(j);
                    else if (j == dp[i].length - 1) {
                        dp[i][j] = dp[i - 1][j - 1] + triangle.get(i).get(j);
                    } else dp[i][j] = Math.min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle.get(i).get(j);
                }
            }

        }
        int minPath = (int) 1e5 + 5;
        for (int i = 0; i < dp[triangle.size() - 1].length; ++i) {
            if (minPath > dp[triangle.size() - 1][i]) minPath = dp[triangle.size() - 1][i];
        }
        return minPath;
    }
}