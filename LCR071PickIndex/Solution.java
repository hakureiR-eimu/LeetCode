import java.util.Random;

class Solution {
    int[] w;
    int[] prefixSum;
    int sum;
    Random rand = new Random();

    public Solution(int[] w) {
        this.w = w;
        this.prefixSum = new int[w.length];
        int sum = 0;
        int prefix = 0;
        for (int i = 0; i < w.length; ++i) {
            int item = w[i];
            sum += item;
            prefix += item;
            prefixSum[i] = prefix;
        }
        this.sum = sum;
    }

    public int pickIndex() {
        // 给一个target=random(0,sum) 寻找index使得 preSum[index-1]<target<=preSum[index]
        int target = rand.nextInt(1, sum + 1);
        int left = 0, right = w.length - 1;
        //认为index在[left,right]内部 prefixSum[index]<=target<prefixSum[index+1]
        //前缀和 pre[inex-1]-pre[index]代表w[index]的范围
        //寻找第一个 index 使得preSum[index]>=target 认为index在[left,right]里，不断淘汰缩小范围
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSum[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */


// 如果使用前缀和
// index
// w
// preSum 单调递增
// 每个index获取的概率是w/index 区间落于[0,index]的概率是preSum/sum
// 给一个target=random(0,sum) 寻找index使得 preSum[index]<=target<preSum[index+1]