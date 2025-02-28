import java.util.*;

public class Main {
    public static void main(String[] args){
        int[] ratings={1,2,2};
        Solution sol=new Solution();
        int ans=sol.candy(ratings);
    }
}

class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] dp = new int[n];

        for (int i = 0; i < n; ++i) {
            if (i != 0 && ratings[i] > ratings[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i != n - 1 && ratings[i] > ratings[i + 1]) {
                dp[i] = Math.max(dp[i + 1] + 1, dp[i]);

            }
            ans += dp[i];
        }
        return ans;
    }
}