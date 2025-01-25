
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
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return null;
        boolean flag = true;

        ListNode l1Head = new ListNode(0);
        ListNode l1 = l1Head;
        ListNode l2Head = new ListNode(0);
        ListNode l2 = l2Head;

        ListNode p = head;
        while (p != null) {
            ListNode temp = p;
            p = p.next;
            if (flag) {
                l1.next = temp;
                l1 = l1.next;
                l1.next = null;
            } else {
                l2.next = temp;
                l2 = l2.next;
                l2.next = null;
            }
            flag = !flag;
        }
        l1.next = l2Head.next;
        return l1Head.next;
    }
}
