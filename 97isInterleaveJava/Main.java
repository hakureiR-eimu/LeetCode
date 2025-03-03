public class Main {
    public static void main(String[] args) {
        String s1 = "aabcc";
        String s2 = "dbbca";
        String s3 = "aadbbcbcac";
        Solution sol = new Solution();
        sol.isInterleave(s1, s2, s3);
    }
}

//求11，因为s3_2=s1_2&&dp_
/*
 * 1 0 0 0 0 0
 * 1
 * 1
 * 0
 * 0
 * 0
 * */
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1 + len2 != len3) return false;
        //dp_i_j 长度i+j能够组成s3的i+j部分
        boolean[][] dp = new boolean[len1 + 1][len2 + 1];
        dp[0][0] = true;
        for (int i = 1; i <= len1; ++i) {
            if (s1.charAt(i - 1) == s3.charAt(i - 1) && dp[i - 1][0]) {
                dp[i][0] = true;
            }
        }
        for (int i = 1; i <= len2; ++i) {
            if (s2.charAt(i - 1) == s3.charAt(i - 1) && dp[0][i - 1]) {
                dp[0][i] = true;
            }
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                int s3Len = i + j;
                if (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(s3Len - 1)) {
                    dp[i][j] = true;
                } else if (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(s3Len - 1)) {
                    dp[i][j] = true;
                } else dp[i][j] = false;
            }
        }
        return dp[len1][len2];
    }
}