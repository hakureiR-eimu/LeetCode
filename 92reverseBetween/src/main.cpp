#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    void reverseLinkedList(ListNode *head) {

        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {

        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *pre = dummyNode;

        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }


        ListNode *leftNode = pre->next;
        ListNode *curr = rightNode->next;

        pre->next = nullptr;
        rightNode->next = nullptr;


        reverseLinkedList(leftNode);


        pre->next = rightNode;
        leftNode->next = curr;
        return dummyNode->next;
    }
};


int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
