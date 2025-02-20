import java.util.*;

public class Main {
    public static void main(String[] args) {
        String str = "01234";
        System.out.println(str.substring(0, 2));
    }
}

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> set = new HashSet<>();
        for (String item : wordDict) {
            set.add(item);
        }
        boolean[] dp = new boolean[s.length() + 1];
        Arrays.fill(dp, false);
        dp[0] = true;
        //dp[i]代表以i-1为末尾的s能否被wordDict表示，即s.substr(0,i)
        //i代表长度 下标范围0-i-1,j代表从此以前是否能包含
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] == true) {
                    String item = s.substring(j, i);
                    if (wordDict.contains(item)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
}