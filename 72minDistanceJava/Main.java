public class Main {
}

class Solution {
    public int minDistance(String word1, String word2) {
//        String min = word1.length() > word2.length() ? word2 : word1;
//        String max = word1.length() > word2.length() ? word1 : word2;
        //dpij -> 将i-1转换成j-1所需的步数
        //如果i-1==j-1 等于dpi-1j-1
        //dpi-1j就是增加min,dpij-1是增加max,dpi-1j-1是替换
        int max = 0x3f3f3f3f;
        int[][] dp = new int[word1.length() + 1][word2.length() + 1];
        if (word1.isEmpty() && word2.isEmpty()) {
            return 0;
        } else if (word1.isEmpty()) return word2.length();
        else if (word2.isEmpty()) return word1.length();
        dp[0][0] = 0;
        for (int i = 1; i <= word1.length(); ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= word2.length(); ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= word1.length(); ++i) {
            for (int j = 1; j <= word2.length(); ++j) {
//                int min = max;
//                min = Math.min(min, dp[i - 1][j] + 1);
//                min = Math.min(min, dp[i][j - 1] + 1);
////                min = Math.min(min, dp[i - 1][j - 1] + 1);
//                min = Math.min(min, word1.charAt(i - 1) == word2.charAt(j - 1) ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1);
                int left = dp[i - 1][j] + 1;
                int up = dp[i][j - 1] + 1;
                int left_up = dp[i - 1][j - 1];
                if (word1.charAt(i - 1) != word2.charAt(j - 1)) left_up++;

                dp[i][j] = Math.min(left, Math.min(up, left_up));

            }
        }
        return dp[word1.length()][word2.length()];
    }
}