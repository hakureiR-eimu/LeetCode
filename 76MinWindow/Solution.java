class Solution {
    public String minWindow(String s, String t) {
        //int[26]表示字符串的字母哈希表
        int[] sMap = new int[128];
        int[] tMap = new int[128];
        t.chars().forEach(c -> tMap[c]++);
        //[i,j)表示子串
        int i = 0, j = 0;
        String minStr;
        int missing = t.length();
        //初始化，找到第一个子串
        while (missing != 0 && j < s.length()) {
            char ch = s.charAt(j);
            if (sMap[ch] < tMap[ch]) {
                sMap[ch]++;
                missing--;
            } else {
                sMap[ch]++;
            }
            j++;
        }
        if (missing != 0) {
            return "";
        } else {
            while (sMap[s.charAt(i)] > tMap[s.charAt(i)]) {
                sMap[s.charAt(i)]--;
                i++;
            }
            minStr = s.substring(i, j);
        }
        //已经找到第一个子串了，j是未访问过的
        //先尝试增加i，如果i自增(sMap[s.charAt(i)--)以后sMap的字符数依旧和t的字符数相等，则可以自增，用while循环得到最大的i。再试图更新minStr
        //再访问j,更新sMap
        //再自增j
        while (j < s.length()) {
            sMap[s.charAt(j)]++;
            while (sMap[s.charAt(i)] > tMap[s.charAt(i)]) {
                sMap[s.charAt(i)]--;
                i++;
            }
            j++;
            if (j - i < minStr.length()) {
                minStr = s.substring(i, j);
            }
        }
        return minStr;
    }
}