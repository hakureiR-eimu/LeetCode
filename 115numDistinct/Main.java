import java.util.*;

class Solution {
    public int numDistinct(String s, String t) {
        //s的子序列t出现的次数
        int lenS = s.length(), lenT = t.length();
        long[][] dp = new long[lenT + 1][lenS + 1];
        for (int i = 0; i <= lenS; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= lenT; ++i) {
            for (int j = 1; j <= lenS; ++j) {

                if (s.charAt(j - 1) == t.charAt(i - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else dp[i][j] = dp[i][j - 1];
            }
        }
        return (int) dp[lenT][lenS] % 1000000007;
    }
}

public class Main {
    public static void main(String[] args) {
        String s = "babgbag";
        String t = "bag";
        Solution sol = new Solution();
        int ans = sol.numDistinct(s, t);
        System.out.println(ans);
    }
}