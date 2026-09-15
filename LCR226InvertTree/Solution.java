import com.sun.source.tree.Tree;

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return null;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            TreeNode left = node.left;
            TreeNode right = node.right;
            node.left = right;
            node.right = left;
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
        return root;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        TreeNode[] nodes = new TreeNode[num];
        for (int i = 0; i < num; ++i) {
            nodes[i] = new TreeNode(sc.nextInt());
        }
        for (int i = 0; i < num; ++i) {
            TreeNode node = nodes[i];
            if (i * 2 + 1 < num && nodes[i * 2 + 1].val != -1) {
                node.left = nodes[i * 2 + 1];
            }
            if (i * 2 + 2 < num && nodes[i * 2 + 2].val != -1) {
                node.right = nodes[i * 2 + 2];
            }
        }
        TreeNode root = nodes[0];
        Solution sol = new Solution();
        sol.invertTree(root);
        String[] ans = new String[num];
        sol.loadAns(ans, root, 0);
        System.out.println(String.join(" ", ans));
    }

    private void loadAns(String[] ans, TreeNode node, int index) {
        if (node == null || index >= ans.length) return;
        ans[index] = String.valueOf(node.val);
        if (node.right == null) {
            loadAns(ans, new TreeNode(-1), index * 2 + 2);
        } else {
            loadAns(ans, node.right, index * 2 + 2);
        }
        if (node.left == null) {
            loadAns(ans, new TreeNode(-1), index * 2 + 1);
        } else {
            loadAns(ans, node.left, index * 2 + 1);
        }
    }
}