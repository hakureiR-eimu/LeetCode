import java.util.ArrayDeque;
import java.util.Deque;

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
    public void reorderList(ListNode head) {
        Deque<ListNode> dq = new ArrayDeque<>();
        ListNode node = head;
        while (node != null) {
            dq.add(node);
            node = node.next;
        }
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        while (!dq.isEmpty()) {
            ListNode left = dq.pollFirst();
            cur.next = left;
            if (!dq.isEmpty()) {
                ListNode right = dq.pollLast();
                left.next = right;
                cur = right;
            } else {
                cur = left;
            }
        }
        cur.next = null;
    }
}