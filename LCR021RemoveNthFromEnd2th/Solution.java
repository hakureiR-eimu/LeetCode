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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // 1 2 3 4 null
        // n=2 pre=3 cur=null pre=1 cur=3
        //设置快慢指针，快指针需要先走n步 然后两个指针一起走 慢指针指向要删除节点的前驱
        ListNode dummy = new ListNode(0, head);
        ListNode fast = head, slow = dummy;

        for (int i = 0; i < n; ++i) {
            fast = fast.next;
        }
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode deleteNode = slow.next;
        ListNode nextNode = slow.next.next;
        slow.next = nextNode;
        return dummy.next;
    }

}