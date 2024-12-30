import java.util.*;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> que = new PriorityQueue<>();
        //求最大k个数，就是构造size为k的最小堆
        for (int i : nums) {
            if (que.size() < k) {
                que.add(i);
            } else {
                if (i > que.peek()) {
                    que.remove();
                    que.add(i);
                }
            }
        }
        return que.peek();
    }
}