import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        String s = "ADOBECODEBANC";
        String t = "ABC";
        Solution sol = new Solution();
        String ans = sol.minWindow(s, t);
    }
}

class Solution {
    public String minWindow(String s, String t) {
        int left = 0, right = 0;
        Map<Character, Integer> sMap = new HashMap<>();
        Map<Character, Integer> tMap = new HashMap<>();

        for (int i = 0; i < t.length(); ++i) {
            Character tKey = t.charAt(i);
            if (tMap.containsKey(tKey)) {
                tMap.put(tKey, tMap.get(tKey) + 1);
            } else {
                tMap.put(tKey, 1);
            }
        }
        while (right < s.length()) {
            char srKey = s.charAt(right);
            if (tMap.containsKey(srKey)) {
                int num=sMap.getOrDefault(srKey,0);
                if(num<tMap.get(srKey)){

                }
            }
            right ++;
        }
    }
}