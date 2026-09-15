class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int[][] dp = new int[target + 1][nums.length];
        //dp[tar][i]代表范围[0,i],运算结果是tar的表达式的个数
        //初始化[0][i]
        //dp[tar][i]=dp[tar-nums[i]][i-1]+dp[tar+nums[i][i-1]
        for (int i = 0; i < nums.length; ++i) {
            dp[0][i] = 0;
        }
        for(int tar=1;tar<=target)
    }
}