import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {

    }
}

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        boolean[] flags = new boolean[nums.length];
        backtracking(nums, list, ans, flags);
        return ans;
    }

    private void backtracking(int[] nums, List<Integer> list, List<List<Integer>> ans, boolean[] flags) {
        if (list.size() == nums.length) {
            ans.add(new ArrayList<>(list));
            return;
        } else {
            for (int i = 0; i < nums.length; ++i) {
                if (!flags[i]) {
                    list.add(nums[i]);
                    flags[i] = true;
                    backtracking(nums, list, ans, flags);
                    list.removeLast();
                    flags[i] = false;
                }
            }
        }
    }
}