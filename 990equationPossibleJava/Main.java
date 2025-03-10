public class Main {
}

class Solution {
    public boolean equationsPossible(String[] equations) {
        int[] parent = new int[26];
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < equations.length; ++i) {
            if (equations[i].charAt(1) == '=') {
                int a = equations[i].charAt(0) - 'a';
                int b = equations[i].charAt(3) - 'a';
                union(parent, a, b);
            }
        }
        for (int i = 0; i < equations.length; ++i) {
            if (equations[i].charAt(1) == '!') {
                int a = equations[i].charAt(0) - 'a';
                int b = equations[i].charAt(3) - 'a';
                if (find(parent, a) == find(parent, b)) return false;
            }
        }
        return true;
    }

    private void union(int[] parent, int index1, int index2) {
        parent[find(parent, index1)] = parent[find(parent, index2)];
    }

    private int find(int[] parent, int index) {
        while (parent[index] != index) {
            parent[index] = parent[parent[index]];
            index = parent[index];
        }
        return index;
    }
}