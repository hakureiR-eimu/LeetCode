import java.util.*;

public class Main {
}

class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> set = new HashSet<>();
        for (char c : brokenLetters.toCharArray()) {
            set.add(c);
        }
        int ans = 0;
        String[] list = text.trim().split(" ");
        for (String item : list) {
            boolean flag = true;
            for (char c : item.toCharArray()) {
                if (set.contains(c)) {
                    flag = false;
                }
            }
            if (flag == true) ans++;

        }
        return ans;
    }
}