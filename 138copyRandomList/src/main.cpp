#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node *pre;
        Node *cur;
        Node *p = head;
        Node *tmp;
        while(p){
            tmp = p->next;
            p->next = new Node(p->val);
            p->next->next = tmp;
            p = tmp;
        }
        p = head;
        pre = p->next;
        while(p){
            tmp = p;
            cur = tmp->next;
            p = p->next->next;
            if(tmp->random){
                cur->random = tmp->random->next;
            }else{
                cur->random = NULL;
            }
            if(cur->next){
                cur->next = cur->next->next;
            }
            else {
                cur->next = NULL;
            }
        }
        return pre;
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
