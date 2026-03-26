import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        int[] nums = {9, 10, 9, -7, -4, -8, 2, -6};
        int k = 5;
        Solution sol = new Solution();
        int[] result = sol.maxSlidingWindow(nums, k);
    }
}

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        //使用最大堆,保持最上最大,
        //初始化
        int left = 0;
        int right = k - 1;
        int[] res = new int[nums.length - k + 1];
        PriorityQueue<Item> queue = new PriorityQueue<>((a, b) -> b.num - a.num);
        for (int i = left; i <= right; ++i) {
            Item item = new Item(i, nums[i]);
            queue.add(item);
        }
        while (right < nums.length) {
            while (!queue.isEmpty() && queue.peek().index < left) {
                queue.remove();
            }
            res[left] = queue.peek().num;
            left++;
            right++;
            if (right < nums.length) {
                queue.add(new Item(right, nums[right]));
            }
        }
        return res;
    }
}

class Item {
    int index;
    int num;

    Item(int index, int num) {
        this.index = index;
        this.num = num;
    }
}