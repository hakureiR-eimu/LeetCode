#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int   val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val    = _val;
        next   = NULL;
        random = NULL;
    }
};

class Solution
{
private:
    unordered_map<Node*, Node*> cachedNode;

public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr) return nullptr;
        if (! cachedNode.count(head))
        {
            Node* newNode    = new Node(head->val);
            cachedNode[head] = newNode;
            newNode->random  = copyRandomList(head->random);
            newNode->next    = copyRandomList(head->next);
        }
        return cachedNode[head];
    }
};

int main(int argc, char** argv)
{
    cout << "hello world!" << endl;
    return 0;
}
