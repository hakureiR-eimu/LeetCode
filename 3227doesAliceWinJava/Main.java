import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
}

class Solution {
    public boolean doesAliceWin(String s) {
        //小红先手
        //如果0个元音，小红输
        //如果有奇数个元音 小红全删，赢
        //如果偶数个元音，小红删奇数个，变奇数个元音，小明删掉偶数个，小红全删，赢
        List<Character> setList = Arrays.asList('a', 'e', 'i', 'o', 'u');
        Set<Character> set = new HashSet<>(setList);
        for (Character ch : s.toCharArray()) {
            if (set.contains(ch)) return true;
        }
        return false;
    }
}