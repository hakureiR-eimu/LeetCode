public class Main {
}

class Solution {
    public boolean isBalanced(String num) {
        int odd = 0, normal = 0;
        for (int i = 0; i < num.length(); ++i) {
            if (i % 2 == 0) {
                odd += num.charAt(i) - '0';
            } else {
                normal += num.charAt(i) - '0';
            }
        }
        if (odd == normal) return true;
        else return false;
    }
}