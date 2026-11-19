import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        LRUCache lruCache = new LRUCache(2);

        lruCache.put(1, 1);
        lruCache.put(2, 2);
        System.out.println(lruCache.get(1)); // 预期 1
        lruCache.put(3, 3);                  // 容量满，淘汰最久未用的 key 2
        System.out.println(lruCache.get(2)); // 预期 -1
        lruCache.put(4, 4);                  // 容量满，淘汰 key 1
        System.out.println(lruCache.get(1)); // 预期 -1
        System.out.println(lruCache.get(3)); // 预期 3
        System.out.println(lruCache.get(4)); // 预期 4
    }
}

class LRUCache {
    class LRUNode {
        int key;
        int val;
        LRUNode prev, next;

        LRUNode(int key, int val) {
            this.key = key;
            this.val = val;
        }

        LRUNode(int key, int val, LRUNode prev, LRUNode next) {
            this.key = key;
            this.val = val;
            this.prev = prev;
            this.next = next;
        }
    }

    LRUNode dummyHead;
    LRUNode dummyTail;
    int capacity, size;
    Map<Integer, LRUNode> keyToLRUNode;

    public LRUCache(int capacity) {
        dummyHead = new LRUNode(-1, -1);
        dummyTail = new LRUNode(-1, -1);
        dummyHead.next = dummyTail;
        dummyTail.prev = dummyHead;
        this.capacity = capacity;
        this.size = 0;
        keyToLRUNode = new HashMap<>();
    }

    public int get(int key) {
        if (keyToLRUNode.containsKey(key)) {
            LRUNode node = keyToLRUNode.get(key);
            moveToTail(node);
            return node.val;
        } else {
            return -1;
        }
    }

    private void moveToTail(LRUNode node) {
        listDelete(node);
        listAppend(node);
    }

    private void listAppend(LRUNode node) {
        LRUNode prev = dummyTail.prev;
        prev.next = node;
        node.prev = prev;
        dummyTail.prev = node;
        node.next = dummyTail;
        size++;
    }

    private void listDelete(LRUNode node) {
        LRUNode prev = node.prev;
        LRUNode next = node.next;
        prev.next = next;
        next.prev = prev;
        node.next = null;
        node.prev = null;
        size--;
    }


    public void put(int key, int value) {
        if (keyToLRUNode.containsKey(key)) {
            LRUNode node = keyToLRUNode.get(key);
            node.val = value;
            moveToTail(node);
        } else {
            if (size < capacity) {
                LRUNode node = new LRUNode(key, value);
                listAppend(node);
                keyToLRUNode.put(key, node);
            } else {
                LRUNode node = new LRUNode(key, value);
                LRUNode deleteNode = dummyHead.next;
                listDelete(deleteNode);
                listAppend(node);
                keyToLRUNode.put(key, node);
                keyToLRUNode.remove(deleteNode.key);
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */