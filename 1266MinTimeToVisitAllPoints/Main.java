public class Main {

}

class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        if (points.length == 1)
            return 0;
        int sum = 0;
        for (int i = 1; i < points.length; ++i) {
            sum += minLen(points[i - 1], points[i]);
        }
        return sum;
    }

    private int minLen(int[] pre, int[] cur) {
        int x1 = pre[0], y1 = pre[1], x2 = cur[0], y2 = cur[1];
        int x = Math.abs(x1 - x2);
        int y = Math.abs(y1 - y2);
        int chang = x >= y ? x : y;
        int kuan = x <= y ? x : y;
        return kuan + chang - kuan;
    }
}