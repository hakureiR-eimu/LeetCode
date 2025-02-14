import java.lang.invoke.DelegatingMethodHandle$Holder;
import java.util.*;

public class Main {

}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    Map<Integer, TreeNode> fa = new HashMap<>();
    Set<Integer> vis = new HashSet<>();

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        dfs(root);
        while (p != null) {
            vis.add(p.val);
            p = fa.get(p.val);
        }
        while (q != null) {
            if (vis.contains(q.val)) return q;
            q = fa.get(q.val);
        }
        return null;
    }

    void dfs(TreeNode root) {

        if (root.left != null) {
            fa.put(root.left.val, root);
            dfs(root.left);
        }
        if (root.right != null) {
            fa.put(root.right.val, root);
            dfs(root.right);
        }
    }
}
