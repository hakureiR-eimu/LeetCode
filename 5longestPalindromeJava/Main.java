public class Main {
}

class Solution {
    public String longestPalindrome(String s) {
        if (s.length() == 1) return s;
        int n = s.length();
        int[][] dp = new int[n][n];
        int ans = 1;
        int loc = 0;
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (s.charAt(i + 1) == s.charAt(i)) {
                dp[i][i + 1] = 2;
                if (ans < 2) {
                    ans = 2;
                    loc = i;
                }
            }
        }
        for (int i = n - 3; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (j == i + 1) {
                    if (s.charAt(i) == s.charAt(j)) {
                        dp[i][j] = 2;
                        if (ans < 2) {
                            ans = 2;
                            loc = i;
                        }
                    } else dp[i][j] = 0;
                } else if (j == i + 2) {
                    if (s.charAt(i) == s.charAt(j)) {
                        dp[i][j] = 3;
                        if (ans < 3) {
                            ans = 3;
                            loc = i;
                        }
                    } else {
                        dp[i][j] = 0;
                    }
                } else {
                    if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1] != 0) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                        if (ans < dp[i][j]) {
                            ans = dp[i][j];
                            loc = i;
                        }
                    }
                }
            }
        }
//        for (int i = 0; i < n; ++i) {
//            for (int j = i; j < n; ++j) {
//                if (i == j) {
//                    dp[i][i] = 1;
//                    if (ans < 1) {
//                        ans = 1;
//                        loc = i;
//                    }
//                } else if (j == i + 1) {
//                    if (s.charAt(i) == s.charAt(j)) {
//                        dp[i][j] = 2;
//                        if (ans < 2) {
//                            ans = 2;
//                            loc = i;
//                        }
//                    } else {
//                        dp[i][j] = 0;
//                    }
//                } else {
//                    if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1] != 0) {
//                        dp[i][j] = dp[i + 1][j - 1] + 2;
//                        if (ans < dp[i][j]) {
//                            ans = dp[i][j];
//                            loc = i;
//                        }
//                    } else {
//                        dp[i][j] = 0;
//                    }
//                }
//            }
//        }
        return s.substring(loc, loc + ans);
    }
}
