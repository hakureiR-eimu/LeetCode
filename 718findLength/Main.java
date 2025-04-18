public class Main {
}

class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        int ans = 0;
        int[][] dp = new int[nums1.length + 1][nums2.length + 1];
        for (int i = 0; i < nums2.length + 1; ++i) dp[0][i] = 0;
        for (int i = 0; i < nums1.length + 1; ++i) dp[i][0] = 0;

        for (int i = 1; i <= nums1.length; ++i) {
            for (int j = 1; j <= nums2.length; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                ans = Math.max(dp[i][j], ans);
            }
        }
        return ans;
    }
}