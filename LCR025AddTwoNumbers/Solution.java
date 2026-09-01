import java.util.Stack;

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<ListNode> stk1 = new Stack<>();
        Stack<ListNode> stk2 = new Stack<>();
        ListNode tmp;
        for (tmp = l1; tmp != null; tmp = tmp.next) {
            stk1.add(tmp);
        }
        for (tmp = l2; tmp != null; tmp = tmp.next) {
            stk2.add(tmp);
        }

        int q = 0, mod = 0;
        tmp = null;
        while (!stk1.isEmpty() || !stk2.isEmpty() || q != 0) {
            ListNode node1 = null, node2 = null;
            if (!stk1.isEmpty()) {
                node1 = stk1.pop();
            }
            if (!stk2.isEmpty()) {
                node2 = stk2.pop();
            }
            int num = q + (node1 != null ? node1.val : 0) + (node2 != null ? node2.val : 0);
            mod = num % 10;
            q = num / 10;
            tmp = new ListNode(mod, tmp);
        }
        return tmp;
    }
}