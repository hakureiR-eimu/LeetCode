#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small = new ListNode(0);
        ListNode *smallHead = small;
        ListNode *large = new ListNode(0);
        ListNode *largeHead = large;
        ListNode *p = head;
        while (p != nullptr)
        {
            if (p->val < x)
            {
                small->next = p;
                small = small->next;
            }
            else
            {
                large->next = p;
                large = large->next;
            }
            p = p->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
