public class Main {
    public static void main(String[] args) {
        char[][] matrix = {
                {'1', '0', '1', '0', '0'},
                {'1', '0', '1', '1', '1'},
                {'1', '1', '1', '1', '1'},
                {'1', '0', '0', '1', '0'}};
        Solution sol = new Solution();
        int ans = sol.maximalSquare(matrix);
    }
}

class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[][] dp = new int[rows][cols];
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    if (ans == 0) ans = 1;
                } else dp[i][j] = 0;
            }
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (dp[i][j] == 1 && dp[i - 1][j - 1] > 0 && dp[i - 1][j] > 0 && dp[i][j - 1] > 0) {
                    //dp_i_j=dp
                    int up = Math.min(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
                    int left = Math.min(dp[i - 1][j - 1], dp[i][j - 1]) + 1;
                    int num = Math.min(up, left);
                    dp[i][j] = num;
                    ans = Math.max(ans, num);
//                    int left_up = dp[i - 1][j - 1];
//                    int left = 0, up = 0;
//                    while (i - up >= 0 && dp[i - up][j] != 0) {
//                        up++;
//                    }
//                    while (j - left >= 0 && dp[i][j - left] != 0) {
//                        left++;
//                    }
//                    int num = Math.min(left, Math.min(up, left_up + 1));
//                    dp[i][j] = num;
//                    ans = Math.max(ans, num);
                }
            }
        }
        return ans * ans;
    }
}