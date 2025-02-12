import java.nio.file.Paths;

public class Main {

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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(-1, head);

        ListNode leftPreNode, rightNode;

        ListNode cur = dummy;
        for (int i = 0; i < left - 1; ++i) {
            cur = cur.next;
        }
        leftPreNode = cur;
        for (int i = 0; i < right - left + 1; ++i) {
            cur = cur.next;
        }
        rightNode = cur;

        ListNode leftNode = leftPreNode.next;
        ListNode rightNextNode = rightNode.next;

        leftPreNode.next = null;
        rightNode.next = null;
        reverse(leftNode);
        leftPreNode.next = rightNode;
        leftNode.next = rightNextNode;
        return dummy.next;
    }

    private ListNode reverse(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while (cur != null) {   //1 2 3 4
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
}