import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[][] points = {{-2147483646, -2147483645}, {2147483646, 2147483647}};
        int[][] points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
        int[][] points2 = {{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10}, {2, 9}, {0, 9}, {3, 9}, {0, 6}, {2, 8}};
        int[][] points7 = {{9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};
        Solution sol = new Solution();
        int ans = sol.findMinArrowShots(points7);
        System.out.println(ans);
    }
}

class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points.length == 0) return 0;
        int[][] copy = points.clone();
        //按照开始区间升序
        Arrays.sort(copy, (a, b) -> {
            if (a[0] == b[0]) return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });
        int pos = copy[0][1];
        int ans = 1;

        for (int i = 1; i < copy.length; ++i) {
            if (copy[i][0] > pos) {
                pos = copy[i][1];
                ans++;
            } else {
                pos = Math.min(pos, copy[i][1]);
            }
        }
        return ans;
    }
}