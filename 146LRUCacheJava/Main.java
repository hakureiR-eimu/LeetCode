import java.util.*;

public class Main {
    public static void main(String[] args) {
        LRUCache lru = new LRUCache(1);
        lru.put(2, 1);
        lru.get(2);
    }
}

class LRUCache {
    class LinkedNode {
        int key, val;

        LinkedNode next, prev;

        LinkedNode(int _key, int _val) {
            super();
            this.val = _val;
            this.key = _key;
        }

        LinkedNode() {

        }
    }

    Map<Integer, LinkedNode> cache = new HashMap<>();
    int capacity;
    int size;
    LinkedNode dummyHead, dummyTail;

    private void moveToHead(LinkedNode node) {
        removeNode(node);
        addToHead(node);
    }

    private void removeNode(LinkedNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void addToHead(LinkedNode node) {
        node.next = dummyHead.next;
        node.prev = dummyHead;
        dummyHead.next.prev = node;
        dummyHead.next = node;
    }

    private LinkedNode removeTail() {
        LinkedNode res = dummyTail.prev;
        removeNode(res);
        return res;
    }

    public LRUCache(int capacity) {
        //cache = new HashMap<>();
        this.capacity = capacity;
        size = 0;
        dummyHead = new LinkedNode();
        dummyTail = new LinkedNode();
        dummyHead.next = dummyTail;
        dummyTail.prev = dummyHead;
    }

    public int get(int key) {
        LinkedNode node = cache.get(key);
        if (node == null) return -1;
        moveToHead(node);
        return node.val;
    }

    public void put(int key, int value) {
        LinkedNode node = cache.get(key);
        if (node == null) {
            LinkedNode newNode = new LinkedNode(key, value);
            cache.put(key, newNode);
            addToHead(newNode);
            ++size;
            if (size > capacity) {
                LinkedNode tail = removeTail();
                cache.remove(tail.key);
                --size;
            }
        } else {
            node.val = value;
            moveToHead(node);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */