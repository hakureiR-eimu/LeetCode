import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {

    }
}

class Solution {
    public int subarraySum(int[] nums, int k) {
        //获取nums中和为k的子数组个数
        //遍历数组，对每个元素，认为其为起点，遍历到结尾，计算其和，保存和
        if (nums.length == 0) {
            return 0;
        }
        int res = 0;
        int[] prefix = new int[nums.length];
        prefix[0] = nums[0];
        Map<Integer, List<Integer>> prefixToIndex = new HashMap<>();
        prefixToIndex.put(prefix[0], new ArrayList<>(List.of(0)));
        if (nums[0] == k) {
            res++;
        }
        for (int i = 1; i < nums.length; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
            if (prefix[i] == k) {
                res++;
            }
            int key = prefix[i] - k;
            if (prefixToIndex.containsKey(key)) {
                res += prefixToIndex.get(key).size();
            }
            if (prefixToIndex.containsKey(prefix[i])) {
                prefixToIndex.get(prefix[i]).add(i);
            } else {
                prefixToIndex.put(prefix[i], new ArrayList<>(List.of(i)));
            }


        }

        return res;
    }
}
// prefix[i]代表以i为index结尾的前缀和
// 读取i,获取prefix数组，则要求index，使得sum[index,i]==k
// 也就是prefix[i]-prefix[index-1]==k
// 找prefix[index-1]==prefix[i]-k;index=key+1;
//