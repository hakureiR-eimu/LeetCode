import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {6, 5, 3, 2, 7, 6, 2};
        List<Integer> ans = sol.replaceNonCoprimes(nums);
        //System.out.println(lcd);
    }
}

// 6 4 3 2 7 6 2
// 6
// 12
// 12
// 12
// 12 7
// 12 7 6
// 12 7 6
class Solution {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        for (int x : nums) {
            while (!ans.isEmpty() && lcd(x, ans.getLast()) > 1) {
                x = lcm(x, ans.getLast());
                ans.removeLast();
            }
            ans.add(x);
        }
        return ans;
    }

    //最大公约数
    public int lcd(int a, int b) {
        while (a != 0) {
            int temp = a;
            a = b % temp;
            b = temp;
        }
        return b;
    }

    //最小公倍数 最小公倍数乘以最大公约数等于两数相乘
    public int lcm(int a, int b) {
        return a / lcd(a, b) * b;
    }
}