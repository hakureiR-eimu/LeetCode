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


    public int rob(TreeNode root) {
        if (root == null) return 0;
        Node nodeRoot = postorder(root);
        postorderRob(nodeRoot);
        return Math.max(nodeRoot.rob, nodeRoot.notRob);
    }

    private Node postorder(TreeNode root) {
        if (root == null) return null;

        Node left = postorder(root.left);
        Node right = postorder(root.right);

        return new Node(root.val, left, right);
    }

    private void postorderRob(Node root) {
        if (root.left == null && root.right == null) {
            root.notRob = 0;
            root.rob = root.val;

        } else if (root.left == null) {
            postorderRob(root.right);
            root.notRob = Math.max(root.right.notRob, root.right.rob);
            root.rob = root.val + root.right.notRob;

        } else if (root.right == null) {
            postorderRob(root.left);
            root.notRob = Math.max(root.left.notRob, root.left.rob);
            root.rob = root.val + root.left.notRob;

        } else {
            postorderRob(root.left);
            postorderRob(root.right);
            root.notRob = Math.max(root.left.rob, root.left.notRob) + Math.max(root.right.rob, root.right.notRob);
            root.rob = root.val + root.left.notRob + root.right.notRob;
        }
    }

    static class Node {
        int val;
        Node left, right;
        int notRob = 0;
        int rob = 0;

        Node(int val, Node left, Node right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}