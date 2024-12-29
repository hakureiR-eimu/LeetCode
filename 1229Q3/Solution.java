import java.util.*;

class Solution {
    public long numberOfSubsequences(int[] nums) {
        HashMap<Long, List<int[]>> map = new HashMap<>();
        long ans = 0;
        if (nums.length < 4) return 0;
        for (int i = 0; i < nums.length; ++i) {
            for (int j = i + 1; j < nums.length; ++j) {
                long tar = (long) nums[i] * nums[j];
                // List<Integer> list = List.of(i, j);
//                if (map.containsKey(tar))
//                    map.get(tar).add(list);
//                else {
//                    map.put(tar, List.of(list));
//                }
                if (!map.containsKey(tar)) {
                    map.put(tar, new ArrayList<>());
                }
                map.get(tar).add(new int[]{i, j});
            }
        }
        for (Map.Entry<Long, List<int[]>> entry : map.entrySet()) {
            if (entry.getValue().size() < 2) {
                continue;
            } else {
                //System.out.println(entry.getKey());
                List<int[]> hashList = entry.getValue();
                for (int i = 0; i < hashList.size(); ++i) {
                    for (int j = i + 1; j < hashList.size(); ++j) {
                        int[] list1 = hashList.get(i);
                        int[] list2 = hashList.get(j);
                        int p = list1[0], r = list1[1], q = list2[0], s = list2[1];
                        if (p < q) {
                            if (q - p > 1 && r - q > 1 && s - r > 1) {
                                ans++;

                            }
                        } else if (p > q) {
                            if (p - q > 1 && s - p > 1 && r - s > 1) {
                                ans++;

                            }
                        }
                    }
                }
            }
        }
        return ans;
    }

}