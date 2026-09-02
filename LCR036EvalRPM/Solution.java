import java.util.Stack;

class Solution {
    public int evalRPN(String[] tokens) {
        //tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < tokens.length; ++i) {
            if (tokens[i].equals("+")) {
                int num1 = stk.pop();
                int num2 = stk.pop();
                stk.push(num1 + num2);
            } else if (tokens[i].equals("-")) {
                int num1 = stk.pop();
                int num2 = stk.pop();
                stk.push(num2 - num1);
            } else if (tokens[i].equals("*")) {
                int num1 = stk.pop();
                int num2 = stk.pop();
                stk.push(num1 * num2);
            } else if (tokens[i].equals("/")) {
                int num1 = stk.pop();
                int num2 = stk.pop();
                stk.push(num2 / num1);
            } else {
                int num = Integer.valueOf(tokens[i]);
                stk.push(num);
            }
        }
        return stk.pop();
    }
}