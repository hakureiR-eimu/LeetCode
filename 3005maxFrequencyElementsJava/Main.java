import java.util.HashMap;
import java.util.Map;

public class Main {
}

class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> map = new HashMap();

        int max = -1;
        for (int item : nums) {
            if (map.containsKey(item)) {
                map.put(item, map.get(item) + 1);
                max = Math.max(max, map.get(item));
            } else {
                map.put(item, 1);
                max = Math.max(max, 1);
            }
        }
        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() == max) {
                ans += max;
            }
        }
        return ans;
    }
}