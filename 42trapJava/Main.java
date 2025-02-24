import java.util.*;

public class Main {
}

class Solution {
    public int trap(int[] height) {
        int[] left = new int[height.length];
        int[] right = new int[height.length];
        Stack<Integer> stack = new Stack<>();
        if (height.length == 0 || height.length == 1 || height.length == 2) return 0;
        stack.add(height[0]);
        for (int i = 1; i < height.length - 1; ++i) {
            if (stack.isEmpty()) {

            } else if (stack.peek() <= height[i]) {
                stack.add(height[i]);
                left[i] = height[i];
            } else {
                left[i] = stack.peek();
            }
        }
        stack.clear();
        stack.add(height[height.length - 1]);
        for (int i = height.length - 2; i > 0; --i) {
            if (stack.peek() <= height[i]) {
                stack.add(height[i]);
                right[i] = height[i];
            } else {
                right[i] = stack.peek();
            }
        }
        int ans = 0;
        for (int i = 1; i < height.length - 1; ++i) {
            int minHeight = Math.min(left[i], right[i]);
            ans += minHeight - height[i];
        }
        return ans;
    }
}