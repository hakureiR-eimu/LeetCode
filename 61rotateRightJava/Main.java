public class Main {
    public static void main(String[] args) {

        ListNode node2 = new ListNode(2);
        ListNode node1 = new ListNode(1, node2);
        Solution sol = new Solution();
        sol.rotateRight(node1, 2);
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (k == 0 || head == null || head.next == null) return head;
        int len = 0;
        ListNode node = head;
        ListNode tail = null;
        while (node != null) {
            tail = node;
            node = node.next;
            len++;
        }
        tail.next = head;
        int stepLen = len - k % len;
        ListNode dummy = new ListNode(0, head);
        node = dummy;
        for (int i = 0; i < stepLen; i++) {
            node = node.next;
        }
        dummy.next = node.next;
        node.next = null;
        return dummy.next;

    }
}