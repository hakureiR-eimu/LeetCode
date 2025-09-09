public class Main {
    public static void main(String[] args){
        Solution sol=new Solution();
        int ans=sol.peopleAwareOfSecret(4,1,3);
        System.out.println(ans);
    }
}

class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        //n=6 delay=2 forget=4
        //dp[i] --第i天增加的人数
        //1 0 1 1 1 2
        long[] dp = new long[n + 1];
        if (forget == 0) return 0;
        dp[1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int day = i + delay; day <= n && day < i + forget; ++day) {
                dp[day] += (long) (dp[i] % (1e9 + 7));
            }
        }
        long ans = 0;
        for (int i = n - forget + 1 < 1 ? 1 : n - forget + 1; i <= n; ++i) {
            ans += dp[i];
        }
        //1 2
        return (int) (ans % (1e9 + 7));
    }
}