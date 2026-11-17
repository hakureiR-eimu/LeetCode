import java.util.Arrays;

public class Solution {
    public boolean canPartition(int[] nums) {
        if (Arrays.stream(nums).sum() % 2 != 0) return false;
        int target = Arrays.stream(nums).sum() / 2;
        int[] sortedNum = nums.clone();
        Arrays.sort(sortedNum);
        nums = sortedNum;

        //问题 nums中是否存在子集 和为target
        //dp[i][j]表示nums[0:i]中存在子集 和为j
        //dp[i][j]=true if dp[i-1][j-i]=true

        //dp[j] 表示nums[0:i]中是否存在子集和为j
        //如果nums[i-j]=true 那么nums[i]=true
        //init
        if (nums.length == 0) return false;
        boolean[] dp = new boolean[target + 1];
        Arrays.fill(dp, false);
        if (nums[0] <= target) {
            dp[nums[0]] = true;
        } else {
            return false;
        }
        for (int i = 1; i < nums.length && nums[i] <= target; ++i) {
            for (int j = target; j >= 0; --j) {
                if (j - nums[i] >= 0 && dp[j - nums[i]]) {
                    dp[j] = true;
                }
            }
        }
        return dp[target];
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 5};
        Solution sol = new Solution();
        sol.canPartition(nums);
    }
}
