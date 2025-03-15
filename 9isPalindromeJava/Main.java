public class Main {
}

class Solution {
    public boolean isPalindrome(int x) {
        String arr = Integer.toString(x);
        int i = 0, j = arr.length() - 1;
        if (i == j) return true;
        while (i <= j) {
            if (i + 1 == j) {
                if (arr.charAt(i) == arr.charAt(j)) return true;
                else return false;
            } else {
                if (arr.charAt(i) == arr.charAt(j)) {
                    i++;
                    j--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}