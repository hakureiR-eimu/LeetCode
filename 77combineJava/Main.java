import java.util.*;

public class Main {
    public static void main(String[] args) {
        int n = 4, k = 2;
        Solution sol = new Solution();
        sol.combine(4, 2);
        System.out.println(sol.results.toString());
    }
}

class Solution {
    LinkedList<Integer> path = new LinkedList<>();
    List<List<Integer>> results = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        backTrace(n, k, 1);
        return results;
    }

    void backTrace(int n, int k, int index) {
        if (path.size() == k) {
            results.add(new ArrayList<>(path));
            return;
        }
        for (int i = index; i <= n; ++i) {
            path.addLast(i);
            backTrace(n, k, i + 1);
            path.removeLast();
        }

    }
}