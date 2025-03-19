public class Main {
    public static void main(String[] args) {
        String[] strs = {"10", "0001", "111001", "1", "0"};
        int m = 5;
        int n = 3;

        Solution sol = new Solution();
        int ans = sol.findMaxForm(strs, m, n);
        System.out.println(ans);
    }
}

class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        //m是0的数量，n是1的数量
        //dpij 代表i个0j个1的最大子集数量
        int[][] dp = new int[m + 1][n + 1];

        for (int k = 0; k < strs.length; ++k) {
            int num0 = 0, num1 = 0;
            for (int i = 0; i < strs[k].length(); ++i) {
                if (strs[k].charAt(i) == '0') num0++;
                else num1++;
            }
            for (int i = m; i >= 0; i--) {
                for (int j = n; j >= 0; j--) {
                    if (i - num0 >= 0 && j - num1 >= 0)
                        dp[i][j] = Math.max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
        }
        return dp[m][n];

    }
}