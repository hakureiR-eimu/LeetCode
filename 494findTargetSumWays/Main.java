public class Main {
}
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int sum=0;
        for(int i=0;i<nums.length;++i){
            sum+=nums[i];
        }
        if(target<0&&target<-sum) return 0;
        if(target>sum||(target+sum)%2!=0) return 0;
        int left=(target+sum)/2;
        int[][] dp=new int[nums.length][left+1];
        dp[0][0]=1;
        if(nums[0]==0) dp[0][0]=2;
        else if(nums[0]<=left) dp[0][nums[0]]=1;
        for(int i=1;i<nums.length;++i){
            for(int j=0;j<=left;++j){
                dp[i][j]+=dp[i-1][j];
                if(j>=nums[i]){
                    dp[i][j]+=dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[nums.length-1][left];
    }
}