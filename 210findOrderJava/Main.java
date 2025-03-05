import java.util.*;

public class Main {

}

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        boolean[][] graph = new boolean[numCourses][numCourses];
        int[] vecs = new int[numCourses];
        for (int i = 0; i < prerequisites.length; ++i) {
            int a = prerequisites[i][1];
            int b = prerequisites[i][0];
            graph[a][b] = true;
            //入度
            vecs[b]++;
        }
        List<Integer> ans = new ArrayList<>();
        Deque<Integer> que = new LinkedList<>();
        for (int i = 0; i < numCourses; ++i) {
            if (vecs[i] == 0) {
                que.add(i);
                ans.add(i);
            }
        }
        while (!que.isEmpty()) {
            for (int i = 0; i < que.size(); ++i) {
                int item = que.removeFirst();
                //ans.add(item);
                for (int j = 0; j < numCourses; ++j) {
                    if (graph[item][j]) {
                        vecs[j]--;
                        graph[item][j] = false;
                        if (vecs[j] == 0) {
                            que.addLast(j);
                            ans.add(j);
                        }
                    }
                }
            }
        }
        if (ans.size() != numCourses) {
            return new int[]{};
        }
        int[] res = new int[ans.size()];
        for (int i = 0; i < res.length; ++i) {
            res[i] = ans.get(i);
        }

        return res;
    }
}