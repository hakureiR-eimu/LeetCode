import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<List<Integer>> ans;
        Solution sol = new Solution();
        int[] candidates = {2, 3, 6, 7};
        int target = 7;
        ans = sol.combinationSum(candidates, target);
        System.out.println(ans);
    }
}

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        LinkedList<Integer> path = new LinkedList<>();
        backTrace(candidates,ans,path,target,0);
        return ans;
    }

    private void backTrace(int[] candidates, List<List<Integer>> ans, LinkedList<Integer> path, int target, int index) {
        if (target == 0) {
            ans.add(new ArrayList<>(path));
            return;
        }
        if (index >= candidates.length) return;
        backTrace(candidates, ans, path, target, index + 1);
        if (target >= candidates[index]) {
            path.add(candidates[index]);
            backTrace(candidates, ans, path, target - candidates[index], index);
            path.removeLast();
        }
    }
}