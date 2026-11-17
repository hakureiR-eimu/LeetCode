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
    public boolean isPalindrome(ListNode head) {
        //先找到中点 然后反转后半部分 最后挨个比较
        ListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        boolean res;
        if (fast == null) {
            ListNode nextHead = reverse(slow);
            res = check(head, nextHead);
            //偶数个节点 slow后面的节点一样多
        } else {
            //奇数个节点 slow后面的节点多一个
            ListNode nextHead = reverse(slow.next);
            res = check(head, nextHead);
        }
        return res;
        //这里1 2 3 fast=null slow=2
        // 1 2 3 4 slow=3
    }

    private boolean check(ListNode head, ListNode nextHead) {
        while (head != null && nextHead != null) {
            if (head.val != nextHead.val) return false;
            head = head.next;
            nextHead = nextHead.next;
        }
        return true;
    }

    private ListNode reverse(ListNode head) {
        //pre表示已反转的最后一个节点 cur表示反转的头
        ListNode pre = null, cur = head;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
}