import java.util.*;

public class Main {
}

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

class Solution {
    public void flatten(TreeNode root) {
        List<TreeNode> list = new ArrayList<>();
        preorder(root, list);
        for (int i = 0; i < list.size(); ++i) {
            if (i == list.size() - 1) {
                list.get(i).left = null;
                list.get(i).right = null;
            } else {
                list.get(i).left = null;
                list.get(i).right = list.get(i + 1);
            }
        }
    }

    private void preorder(TreeNode root, List<TreeNode> list) {
        if (root == null) return;
        list.add(root);
        preorder(root.left, list);
        preorder(root.right, list);
    }
}