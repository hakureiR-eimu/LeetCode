class Solution {
    public String removeStars(String s) {
        StringBuilder res = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (ch == '*') {
                res.deleteCharAt(res.length() - 1);
            } else res.append(ch);
        }
        return res.toString();
    }
}