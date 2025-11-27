import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {-8};
        int k = 1;
        long res = sol.maxSubarraySum(nums, k);
        System.out.println(res);
    }
}

class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long ans = Long.MIN_VALUE;

        // 前缀和 prefix[i] 表示前 i 个元素的和
        long[] prefix = new long[n + 1];
        // groups[r] 存储所有满足 index % k == r 的前缀和下标
        Map<Integer, List<Integer>> groups = new HashMap<>();
        // 初始
        groups.computeIfAbsent(0, x -> new ArrayList<>()).add(0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
            int idx = i + 1;
            groups.computeIfAbsent(idx % k, x -> new ArrayList<>()).add(idx);
        }

        // 遍历每个分组
        for (List<Integer> indices : groups.values()) {
            // 无法构成子数组
            if (indices.size() < 2) {
                continue;
            }
            // 组内维护出现的最小前缀和
            long min_p = Long.MAX_VALUE;

            for (int idx : indices) {
                // 对应的前缀和值
                long cur_sum = prefix[idx];
                // 之前记录过 min_p
                if (min_p != Long.MAX_VALUE) {
                    // 计算子数组和并更新最大值
                    ans = Math.max(ans, cur_sum - min_p);
                }
                // 更新最小前缀和
                min_p = Math.min(min_p, cur_sum);
            }
        }

        return ans != Long.MIN_VALUE ? ans : 0;
    }
}
