#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
private:
    unordered_map<Node *, Node *> visited;

public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        if (visited.find(node) != visited.end())
            return visited[node];
        Node *newNode = new Node(node->val);
        visited[node] = newNode;
        for (Node *neighbor : node->neighbors)
        {
            newNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return newNode;
    }
};
int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    return 0;
}
