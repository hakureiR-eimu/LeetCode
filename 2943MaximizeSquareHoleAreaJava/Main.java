import java.util.*;

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] hBars = { 2, 3 };
        int[] vBars = { 2, 4 };
        int res = sol.maximizeSquareHoleArea(2, 3, hBars, vBars);
        System.out.println(res);
    }
}

class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        int large = n >= m ? n : m;
        int small = n <= m ? n : m;
        // 最大是small*small,最小是1
        // 求数组的从下标1到下标最长连续长度
        int len1 = minLength(hBars) + 1;
        int len2 = minLength(vBars) + 1;
        int len = Math.min(len1, len2);
        return len * len;
    }

    private int minLength(int[] arr) {
        // key=item value=len
        Map<Integer, Integer> map = new HashMap<>();
        for (int item : arr) {
            map.put(item, 1);
        }
        Arrays.sort(arr);
        int res = 1;
        for (int i = 0; i < arr.length; ++i) {
            int cur = arr[i];
            int len = 1;
            while (map.containsKey(cur + 1)) {
                cur++;
                len++;
            }
            res = Math.max(res, len);
        }
        return res;
    }
}