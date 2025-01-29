import java.util.*;

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stk = new Stack<>();
        for (int item : asteroids) {
            boolean flag = true;
            while (flag && !stk.isEmpty() && stk.peek() > 0 && item < 0) {
                int a = stk.peek(), b = -item;
                if (a <= b) {
                    stk.pop();
                }
                if (a >= b) flag = false;

            }
            if (flag) stk.push(item);
        }
        int sz = stk.size();
        int[] ans = new int[sz];
        while (!stk.isEmpty()) {
            ans[--sz] = stk.pop();
        }
        return ans;
    }
}