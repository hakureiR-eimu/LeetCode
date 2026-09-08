import java.util.PriorityQueue;

public class Main {
}

class KthLargest {
    //最小堆保存最大的k个数
    //当最小堆容量不满 不存在第k大元素 遍历元素时直接入队列
    //当最小堆满。则堆顶就是第k大元素。遍历元素，如果大于堆顶，删除堆顶再插入元素。否则丢弃。
    private PriorityQueue<Integer> smallHeap;
    private int maxHeapSize;

    public KthLargest(int k, int[] nums) {
        smallHeap = new PriorityQueue<>();
        maxHeapSize = k;
        for (int num : nums) {
            if (smallHeap.size() < maxHeapSize) {
                smallHeap.add(num);
            } else {
                int top = smallHeap.peek();
                if (num > top) {
                    smallHeap.poll();
                    smallHeap.add(num);
                }
            }
        }
    }

    public int add(int val) {


        if (smallHeap.size() < maxHeapSize) {
            smallHeap.add(val);
        } else {
            int top = smallHeap.peek();
            if (val > top) {
                smallHeap.poll();
                smallHeap.add(val);
            }
        }
        if (smallHeap.isEmpty()) return -1;
        else {
            return smallHeap.peek();
        }
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */