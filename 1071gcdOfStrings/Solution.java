class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        int len = gcd(Math.max(str1.length(), str2.length()), Math.min(str1.length(), str2.length()));
        return str1.substring(0, len);
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else return gcd(b, a % b);
    }
}