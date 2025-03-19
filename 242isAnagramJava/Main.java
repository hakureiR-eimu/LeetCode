import java.util.*;

public class Main {
}

class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> sMap = new HashMap<>();
        if (s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); ++i) {
            Character ch = s.charAt(i);
            if (!sMap.containsKey(ch)) {
                sMap.put(ch, 1);
            } else {
                int num = sMap.get(ch);
                sMap.put(ch, num+1);
            }
        }
        for (int i = 0; i < t.length(); ++i) {
            Character ch = t.charAt(i);
            if (!sMap.containsKey(ch) || sMap.get(ch) == 0) {
                return false;
            } else {
                sMap.put(ch, sMap.get(ch) - 1);
            }
        }
        return true;
    }
}