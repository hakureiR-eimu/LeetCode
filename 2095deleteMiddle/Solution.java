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
    public ListNode deleteMiddle(ListNode head) {
        if (head.next == null) {
            return null;
        }
        ListNode l = head, r = head.next.next;
        while (r != null && r.next != null) {
            l = l.next;
            r = r.next.next;
        }
        l.next = l.next.next;
        return head;
    }
}