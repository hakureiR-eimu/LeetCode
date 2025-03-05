import java.util.*;

public class Main {
}

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        boolean[][] graph = new boolean[numCourses][numCourses];
        int[] vecs = new int[numCourses];
        for (int i = 0; i < prerequisites.length; ++i) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            //先学b再学a
            graph[a][b] = true;
            vecs[b]++;
        }

        Deque<Integer> que = new LinkedList<>();
        for (int i = 0; i < numCourses; ++i) {
            if (vecs[i] == 0) que.addLast(i);
        }
        int ans = 0;
        while (!que.isEmpty()) {
            for (int i = 0; i < que.size(); ++i) {
                ans++;
                int node = que.removeFirst();
                boolean[] item = graph[node];
                for (int j = 0; j < numCourses; ++j) {
                    if (graph[node][j]) {
                        graph[node][j] = false;
                        vecs[j]--;
                        if (vecs[j] == 0) que.addLast(j);
                    }
                }
            }
        }
        if (ans == numCourses) return true;
        else return false;
    }
}