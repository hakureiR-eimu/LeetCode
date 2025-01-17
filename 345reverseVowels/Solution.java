import java.util.*;

class Solution {
    public String reverseVowels(String s) {
        Set<Character> set = new HashSet<>();

        set.add('a');
        set.add('A');
        set.add('e');
        set.add('E');
        set.add('i');
        set.add('I');
        set.add('o');
        set.add('O');
        set.add('u');
        set.add('U');

        char[] chs = s.toCharArray();
        int i = 0, j = chs.length - 1;
        while (i < j) {
            while (i < j && !set.contains(chs[i])) {
                i++;
            }
            while (i < j && !set.contains(chs[j])) {
                j--;
            }
            if (i < j) {
                char temp = chs[i];
                chs[i] = chs[j];
                chs[j] = temp;
                ++i;
                --j;
            }

        }
        String ans = new String(chs);
        return ans;
    }
}