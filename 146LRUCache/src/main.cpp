#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class LRUCache
{
private:
    struct DLinkedNode
    {
        int key, value;
        DLinkedNode *prev;
        DLinkedNode *next;
        DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
        DLinkedNode(int _key, int _value)
            : key(_key), value(_value), prev(nullptr), next(nullptr)
        {
        }
    };
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size, capacity;

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int _key)
    {
        if (!cache.count(_key)) return -1;
        DLinkedNode *node = cache[_key];
        moveToHead(node);
        return node->value;
    }

    void put(int _key, int _value)
    {
        if (!cache.count(_key))
        {
            DLinkedNode *node = new DLinkedNode(_key, _value);
            cache[_key] = node;
            addToHead(node);
            ++size;
            if (size > capacity)
            {
                DLinkedNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        }
        else
        {
            DLinkedNode *node = cache[_key];
            moveToHead(node);
            node->value = _value;
        }
    }
    void moveToHead(DLinkedNode *_node)
    {
        removeNode(_node);
        addToHead(_node);
    }
    void addToHead(DLinkedNode *_node)
    {
        DLinkedNode *headNext = head->next;
        head->next = _node;
        _node->prev = head;
        _node->next = headNext;
        headNext->prev = _node;
    }
    void removeNode(DLinkedNode *_node)
    {
        DLinkedNode *_nodeNext = _node->next;
        DLinkedNode *_nodePrev = _node->prev;
        _nodePrev->next = _nodeNext;
        _nodeNext->prev = _nodePrev;
    }
    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(int argc, char **argv)
{
    LRUCache *p = new LRUCache(2);
    int res;
    p->put(2, 1);
    p->put(1, 1);
    p->put(2, 3);
    p->put(4, 1);
    cout << "hewllo" << endl;
    res = p->get(1);
    cout << res << endl;
    res = p->get(2);
    cout << res << endl;
    return 0;
}
