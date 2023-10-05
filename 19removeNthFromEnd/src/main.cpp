#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
private:
    int num = 0;
    void dfs(ListNode* node, int n)
    {
        if (node == nullptr) return;
        dfs(node->next, n);
        num++;
        if (num == n + 1)
        {
            ListNode* p = node->next;
            node->next = p->next;
            delete p;
        }
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* pre = new ListNode();
        pre->next = head;
        dfs(pre, n);
        return pre->next;
    }
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
