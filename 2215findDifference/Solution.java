import java.util.*;

public class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>());
        ans.add(new ArrayList<>());

        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();

        for (Integer i : nums1) {
            set1.add(i);
        }
        for (Integer i : nums2) {
            set2.add(i);
        }

        List<Integer> ans0 = ans.get(0);
        List<Integer> ans1 = ans.get(1);
        for (Integer i : set1) {
            if (!set2.contains(i)) {
                ans0.add(i);
            }
        }
        for (Integer i : set2) {
            if (!set1.contains(i)) {
                ans1.add(i);
            }
        }
        return ans;
    }
}