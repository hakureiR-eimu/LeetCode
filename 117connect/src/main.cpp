#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
private:
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            int levelCount = que.size();
            Node *pre = NULL;
            for (int i = 0; i < levelCount; i++)
            {
                Node *p = que.front();
                que.pop();
                if (pre != NULL)
                {
                    pre->next = p;
                }
                pre = p;
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
            }
        }
        return root;
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
