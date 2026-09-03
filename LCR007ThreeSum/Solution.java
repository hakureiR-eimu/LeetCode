import java.util.*;

class Solution {
    public static void main(String[] args) {
        int[] nums = {-1, 0, 1, 2, -1, -4};
        Solution sol = new Solution();
        List<List<Integer>> ans = sol.threeSum(nums);
        System.out.println(ans);
    }

    public List<List<Integer>> threeSum(int[] nums) {
        int[] copy = Arrays.copyOf(nums, nums.length);
        Arrays.sort(copy);
        nums = copy;
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; ++i) {
            //寻找nums[i],nums[j],nums[k]使得nums[i]+nums[j]+nums[k]==0
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.length - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    List<Integer> item = new ArrayList<>();
                    item.add(nums[i]);
                    item.add(nums[j]);
                    item.add(nums[k]);
                    ans.add(item);
                    while (j < k && nums[j + 1] == nums[j]) j++;
                    while (j < k && nums[k - 1] == nums[k]) k--;
                    j++;
                    k--;
                }

            }
        }
        return ans;
    }
}