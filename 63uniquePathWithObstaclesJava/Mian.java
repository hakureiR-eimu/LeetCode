public class Mian {
}

class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int rows = obstacleGrid.length;
        int cols = obstacleGrid[0].length;
        int[][] dp = new int[rows][cols];
        if (obstacleGrid[0][0] == 1) return 0;
        else {
            dp[0][0] = 1;
            boolean hasRock = false;
            for (int i = 1; i < rows; ++i) {
                if (obstacleGrid[i][0] == 1) {
                    dp[i][0] = 0;
                    hasRock = true;
                }
                if (!hasRock) {
                    dp[i][0] = dp[i - 1][0];
                }
            }
            hasRock = false;
            for (int i = 1; i < cols; ++i) {
                if (obstacleGrid[0][i] == 1) {
                    dp[0][i] = 0;
                    hasRock = true;
                }
                if (!hasRock) {
                    dp[0][i] = dp[i - 1][0];
                }
            }
            for (int i = 1; i < rows; ++i) {
                for (int j = 1; j < cols; ++j) {
                    if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
            return dp[rows - 1][cols -  1];
        }
    }
}