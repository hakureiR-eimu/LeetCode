import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> nums_set = new HashSet<>();
        for (int num : nums) {
            nums_set.add(num);
        }
        int maxLen = 0;
        for (int num : nums_set) {

            if (!nums_set.contains(num - 1)) {
                int len = 0;
                int numT = num;
                while (nums_set.contains(numT)) {
                    len++;
                    numT++;
                }
                maxLen = Math.max(maxLen, len);
            }

        }
        return maxLen;
    }
}

class Node {
    int val;
    int len;

    Node(int val, int len) {
        this.val = val;
        this.len = len;
    }
}