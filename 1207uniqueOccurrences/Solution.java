import java.util.*;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> numMap = new HashMap<>();
        Set<Integer> countSet = new HashSet<>();

        for (int item : arr) {
            numMap.put(item, numMap.getOrDefault(item, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> item : numMap.entrySet()) {
            if (countSet.contains(item.getValue())) {
                return false;
            }
            countSet.add(item.getValue());
        }
        return true;
    }
}