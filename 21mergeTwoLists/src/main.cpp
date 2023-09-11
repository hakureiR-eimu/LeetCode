#include <iostream>

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1 = list1, *p2 = list2;
        ListNode *pre = new ListNode(-101);
        ListNode *cur = pre;
        while(p1 || p2){
            if(p1 && p2 && p2->val < p1->val){
                cur->next = p2;
                cur = cur->next;
                p2 = p2->next;
            }
            else if(p1 && p2){
                cur ->next = p1;
                cur = cur->next;
                p1 = p1->next;
            }
            else{
                cur->next = p1?p1:p2;
                p1?p1 = p1->next:p2 = p2->next;
                cur = cur->next;
            }
        }
        return pre->next;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
