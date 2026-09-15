class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int aLen = 0, bLen = 0;
        ListNode cur = headA;
        while (cur != null) {
            aLen++;
            cur = cur.next;
        }
        cur = headB;
        while (cur != null) {
            bLen++;
            cur = cur.next;
        }
        // a由a+s组成，b由b+s组成 得到
        ListNode nodeA = headA, nodeB = headB;
        if (aLen > bLen) {
            int gap = aLen - bLen;
            for (int i = 0; i < gap; ++i) {
                nodeA = nodeA.next;
            }
        } else {
            int gap = bLen - aLen;
            for (int i = 0; i < gap; ++i) {
                nodeB = nodeB.next;
            }
        }
        while (nodeA != null && nodeB != null) {
            if (nodeA == nodeB) return nodeA;
            nodeA = nodeA.next;
            nodeB = nodeB.next;
        }
        return null;
    }
}