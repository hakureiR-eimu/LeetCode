import java.util.*;

public class Main {
    public static void main(String[] args) {
        int[] arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
        Solution sol = new Solution();
        int ans = sol.minJumps(arr);
    }
}

class Solution {
    public int minJumps(int[] arr) {
        Map<Integer, List<Integer>> numToPos = new HashMap<>();
        for (int i = 0; i < arr.length; ++i) {
            if (numToPos.containsKey(arr[i])) {
                numToPos.get(arr[i]).add(i);
            } else {
                List<Integer> list = new ArrayList<>();
                list.add(i);
                numToPos.put(arr[i], list);
            }
        }

        int[] dp = new int[arr.length];
        Arrays.fill(dp, Integer.MAX_VALUE);
        int distance = 0;
        Queue<Integer> posQueue = new ArrayDeque<>();
        posQueue.add(0);
        boolean[] isVisited = new boolean[arr.length];
        while (!posQueue.isEmpty()) {
            int size = posQueue.size();
            for (int i = 0; i < size; ++i) {
                int pos = posQueue.poll();
                if (isVisited[pos]) {
                    continue;
                } else {
                    if (dp[pos] > distance) {
                        dp[pos] = distance;
                        if (pos - 1 >= 0) {
                            posQueue.add(pos - 1);
                        }
                        if (pos + 1 < arr.length) {
                            posQueue.add(pos + 1);
                        }
                        if (numToPos.containsKey(arr[pos])) {
                            List<Integer> list = numToPos.get(arr[pos]);
                            posQueue.addAll(list);
                            numToPos.remove(arr[pos]);
                        }
                        isVisited[pos] = true;
                    }
                }

            }
            distance++;
        }
        return dp[arr.length - 1];
    }
}