import java.util.*;

class Solution {
    public static void main(String[] args) {
        int[] input = {-2, -1, 1, 2};
        Solution sol = new Solution();
        int[] ans = sol.asteroidCollision(input);
    }

    public int[] asteroidCollision(int[] asteroids) {
        int[] stk = new int[asteroids.length];
        int top = -1;
        for (int num : asteroids) {
            if (top < 0) {
                top++;
                stk[top] = num;
            } else {
                if (num > 0) {
                    top++;
                    stk[top] = num;
                } else {
                    boolean isAlive = true;
                    while (isAlive) {
                        if (top >= 0 && stk[top] > 0) {
                            if (stk[top] < Math.abs(num)) {
                                top--;
                            } else if (stk[top] == Math.abs(num)) {
                                top--;
                                isAlive = false;
                            } else if (stk[top] > Math.abs(num)) {
                                isAlive = false;
                            }
                        } else {
                            break;
                        }
                    }
                    if (isAlive) {
                        top++;
                        stk[top] = num;
                    }
                }
            }
        }
        return Arrays.copyOf(stk, top + 1);
    }
}