#include <iostream>
#include <algorithm>
using namespace std;

class MinStack
{
private:
    class Node
    {
    public:
        int val;
        int min;
        Node *next;
        Node(int _val, int _min) : val(_val), min(_min), next(NULL) {}
        Node() : val(), min(INT32_MAX), next(NULL) {}
        Node(int _val, int _min, Node *_next) : val(_val), min(_min), next(_next) {}
    };

public:
    Node *head = NULL;
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    MinStack()
    {
    }

    void push(int val)
    {
        if (isEmpty())
        {
            int _min = val;
            int _val = val;
            head = new Node(_val, _min);
        }
        else
        {
            int _min = head->min > val ? val : head->min;
            int _val = val;
            Node *p = new Node(_val, _min, head);
            head = p;
        }
    }

    void pop()
    {
        // Node *p = head->next;
        head = head->next;
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
