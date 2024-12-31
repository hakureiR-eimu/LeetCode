import java.util.*;

class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if (digits.isEmpty()) return ans;
        Map<Character, String> map = new HashMap<>() {
            {
                put('2', "abc");
                put('3', "def");
                put('4', "ghi");
                put('5', "jkl");
                put('6', "mno");
                put('7', "pqrs");
                put('8', "tuv");
                put('9', "wxyz");
            }
        };
        StringBuilder path = new StringBuilder();
        dfs(path, map, digits, 0, ans);

        return ans;
    }

    void dfs(StringBuilder path, Map<Character, String> map, String digits, int index, List<String> ans) {
        if (index == digits.length()) ans.add(path.toString());
        else {
            char digit = digits.charAt(index);
            String str = map.get(digit);
            for (int i = 0; i < str.length(); ++i) {
                path.append(str.charAt(i));
                dfs(path, map, digits, index + 1, ans);
                path.deleteCharAt(index);
            }
        }
    }
}