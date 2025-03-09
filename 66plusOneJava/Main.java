import java.util.*;
import java.math.*;

public class Main {
}

class Solution {
    public int[] plusOne(int[] digits) {

        BigDecimal ans = new BigDecimal(0);
        for (int item : digits) {
            ans=ans.multiply(new BigDecimal(10));
            ans=ans.add(new BigDecimal(item));
        }
        ans=ans.add(new BigDecimal(1));
        String str = String.valueOf(ans);
        int[] res = new int[str.length()];
        for (int i = 0; i < str.length(); ++i) {
            res[i] = str.charAt(i) - '0';
        }
        return res;
    }
}