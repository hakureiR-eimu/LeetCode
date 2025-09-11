import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String ans = sol.sortVowels("lEetcOde");
        System.out.println(ans);
    }
}

class Solution {
    public String sortVowels(String s) {
        Set<Character> set = Set.of('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U');
        List<Character> list = new ArrayList<>(s.length());
        char[] res = s.toCharArray();
        for (char chh : s.toCharArray()) {
            if (set.contains(chh)) {
                list.add(chh);
            }
        }
        list.sort((a, b) -> {
            return a - b;
        });
        int loc = 0;
        int len = list.toArray().length;
        for (int i = 0; i < res.length; ++i) {
            if (set.contains(res[i])) {
                char ch = list.get(loc);
                res[i] = ch;
                loc++;
            }
        }
        return new String(res);

    }
}