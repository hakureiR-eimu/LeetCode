public class Solution {
}
class KthLargest {
    private Queue<Integer> big

    public KthLargest(int k, int[] nums) {
        // 返回第k大的数
        // 应该是个小顶堆，顶部是堆里最小的数
        // 遍历nums，如果堆大小小于k，直接入堆
        // 如果堆大小大于等于k，此时堆顶元素表示o-i-1 里第k大的元素，
    }

    public int add(int val) {

    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */