import java.util.Arrays;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int ans = 0;
        Arrays.sort(intervals, (arr1, arr2) ->
                arr1[1] == arr2[1] ? arr1[0] - arr2[0] : arr1[1] - arr2[1]
        );
        int end = Integer.MIN_VALUE;
        for (int[] inter : intervals) {
            if (inter[0] < end) {
                ans++;
            } else {
                end = inter[1];
            }
        }
        return ans;
    }
}