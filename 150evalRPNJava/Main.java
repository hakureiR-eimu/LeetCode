import java.util.*;

public class Main {
}

class Solution {
    public int evalRPN(String[] tokens) {

        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < tokens.length; ++i) {
            if (tokens[i].equals("+")) {
                int a = stk.pop();
                int b = stk.pop();
                stk.push(a + b);
            } else if (tokens[i].equals("-")) {
                int b = stk.pop();
                int a = stk.pop();
                stk.push(a - b);
            } else if (tokens[i].equals("*")) {
                int b = stk.pop();
                int a = stk.pop();
                stk.push(a * b);
            } else if (tokens[i].equals("/")) {
                int b = stk.pop();
                int a = stk.pop();
                stk.push(a / b);
            } else {
                Integer val = Integer.parseInt(tokens[i]);
                stk.push(val);
            }
        }
        return stk.pop();
    }
}
