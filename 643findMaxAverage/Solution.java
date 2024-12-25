class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int l = 0, r = k;
        int cur = 0, maxCur = 0;
        double ans;
        for (int i = 0; i < k; ++i) {
            cur += nums[i];
        }
        maxCur = cur;
        if (nums.length == k) {
            ans = (double) cur / k;
            return ans;
        }
        while (r < nums.length) {
            cur = cur + nums[r] - nums[l];
            maxCur = Math.max(cur, maxCur);
            l++;
            r++;
        }
        ans = (double)maxCur / k;
        return ans;
    }
}