#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tmp1 = 0,tmp2 = 0,cf = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* pre = new ListNode();
        ListNode* cur = pre;
        while(p1 != nullptr|| p2 != nullptr){
            tmp1 = p1?p1->val:0;
            tmp2 = p2?p2->val:0;
            int num = tmp1 + tmp2 + cf;
            cf = 0;
            if(num >= 10) {
                cf = 1;
            }
            cur->next = new ListNode(num % 10);
            cur = cur->next;
            p1 = p1?p1->next:nullptr;
            p2 = p2?p2->next:nullptr;
        }
        if(p1 == nullptr && p2 == nullptr && cf == 1){
            cur->next = new ListNode(1);
            cur = cur->next;
        }
        return pre->next;
    }
    
};
int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
