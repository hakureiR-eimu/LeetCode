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
    public ListNode reverseKGroup(ListNode head, int k) {
        //每次持有headPre节点，遍历接下来的k个节点拿到下一个head节点

        ListNode dummyNode = new ListNode(-1, head);
        ListNode pre = dummyNode;
        ListNode tail, nextHead;
        //每次找到head和pre，如果包含head有k个节点，则断开head:k链，再反转链表，最后把pre指向新头，把新尾指向下一个head，再处理下一个head
        while (true) {
            tail = getKNode(head, k);
            if (tail != null) {
                nextHead = tail.next;
                tail.next = null;
                reverse(head);
                //头部是tail。尾部是head
                pre.next = tail;
                head.next = nextHead;
                pre = head;
                head = nextHead;
            } else {
                break;
            }
        }
        return dummyNode.next;
    }

    //是否存在包含head在内的k个节点，如果存在，返回最后一个节点
    private ListNode getKNode(ListNode head, int k) {
        ListNode cur = head;
        while (cur != null && k != 1) {
            cur = cur.next;
            k--;
        }
        return cur;
    }

    private ListNode reverse(ListNode head) {
        ListNode pre = null, cur = head;
        while (cur != null) {
            ListNode nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    //单纯反转链表，拿着已经反转的pre，拿cur和post，把cur指向tail，再把tail设置成cur，cur设置成post，post
}