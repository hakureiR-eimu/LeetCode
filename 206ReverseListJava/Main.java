public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        sol.reverseList(node1);
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
    /**
     * 1->2->3
     * pre,cur,next
     * 1<-2<-3
     * return 3
     */
    public ListNode reverseList(ListNode head) {
        return iteration(head);
    }

    /**
     * 迭代法
     *
     * @param head
     * @return
     */
    private ListNode iteration(ListNode head) {
        if (head == null) {
            return null;
        }
        return recursion(head);
    }

    private ListNode recursion(ListNode head) {
        if (head == null) {
            return null;
        }

        return recur(null, head);
    }

    private ListNode recur(ListNode pre, ListNode cur) {
        if (cur == null) {
            return pre;
        }
        ListNode next = cur.next;
        cur.next = pre;
        return recur(cur, next);
    }
}