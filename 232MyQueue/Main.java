import java.util.Stack;

public class Main {
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
class MyQueue {
    Stack<Integer> stk1 = new Stack<>();
    Stack<Integer> stk2 = new Stack<>();

    public MyQueue() {

    }

    public void push(int x) {
        stk1.push(x);
    }

    public int pop() {
        if (stk1.isEmpty() && stk2.isEmpty()) return -1;
        else if (!stk2.isEmpty()) {
            return stk2.pop();
        } else {
            while (!stk1.isEmpty()) {
                stk2.push(stk1.pop());
            }
            return stk2.pop();
        }
    }

    public int peek() {
        if (stk1.isEmpty() && stk2.isEmpty()) return -1;
        else if (!stk2.isEmpty()) {
            return stk2.peek();
        } else {
            while (!stk1.isEmpty()) {
                stk2.push(stk1.pop());
            }
            return stk2.peek();
        }
    }

    public boolean empty() {
        if (stk2.isEmpty() && stk1.isEmpty()) return true;
        return false;
    }
}
