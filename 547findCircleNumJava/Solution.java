class Solution {
    private void dfs(int[] visited, int[][] isConnected, int tar) {
        visited[tar] = 1;
        for (int i = 0; i < isConnected.length; ++i) {
            if (isConnected[tar][i] == 1 && visited[i] == 0) {
                dfs(visited, isConnected, i);
            }
        }

    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int[] A = new int[n];
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                cnt++;
                dfs(A, isConnected, i);
            }
        }
        return cnt;
    }
}