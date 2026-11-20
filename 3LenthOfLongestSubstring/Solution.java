import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String input = sc.next();
        Solution sol = new Solution();
        int ans = sol.lengthOfLongestSubstring(input);
        System.out.println(ans);
    }

    public int lengthOfLongestSubstring(String s) {
        //设置双指针 i j 假设[i,j)之间不存在重复字符 那j不在[i,j]里面存在重复字符就可以认为[i,j]成立了
        int ans = 0;

        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0, j = 0; j < s.length(); ++j) {
            char chJ = s.charAt(j);
            i = Math.max(i, map.getOrDefault(chJ, -1) + 1);
            int len = j - i + 1;
            ans = Math.max(ans, len);
            map.put(chJ, j);
        }
        return ans;
    }
}