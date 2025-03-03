import java.util.*;

public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        Solution sol = new Solution();
        sol.permute(nums);
    }
}

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        LinkedList<Integer> path = new LinkedList<>();
        dfs(ans, nums, path, set);
        return ans;
    }

    void dfs(List<List<Integer>> ans, int[] nums, LinkedList<Integer> path, Set<Integer> set) {
        if (path.size() == nums.length) {
            List<Integer> item = new ArrayList<>(path);
            ans.add(item);
        } else {
            for (int j = 0; j < nums.length; ++j) {
                if (!set.contains(nums[j])) {
                    set.add(nums[j]);
                    path.add(nums[j]);
                    dfs(ans, nums, path, set);
                    path.removeLast();
                    set.remove(nums[j]);
                }
            }
        }
    }
}
