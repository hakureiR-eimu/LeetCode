import java.util.HashSet;
import java.util.List;
import java.util.Set;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

// a,b,c 快慢指针在b位置相遇，则慢指针走了a+b,快指针走了a+b+c+b 2(a+b)=a+b+c+b 所以a=c
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head, fast = head;
        try {
            do {
                fast = fast.next.next;
                slow = slow.next;
            } while (slow != fast);
        } catch (NullPointerException e) {
            return null;
        }


        ListNode tar = head;
        while (tar != slow) {
            tar = tar.next;
            slow = slow.next;
        }
        return tar;
    }
}