#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head -> next == nullptr){
            return false;
        }
        ListNode* fast = head -> next;
        ListNode* slow = head;
        while(slow != fast){
            if(fast == nullptr || fast -> next == nullptr){
                return false;
            }
            slow = slow -> next;
            fast = fast ->next -> next;
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
