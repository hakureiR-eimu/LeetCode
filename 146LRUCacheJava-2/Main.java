import java.util.*;

public class Main {
    public static void main(String[] args) {
        LRUCache lRUCache = new LRUCache(2);
        lRUCache.put(1, 1); // 缓存是 {1=1}
        lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
        lRUCache.get(1);    // 返回 1
        lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
        lRUCache.get(2);    // 返回 -1 (未找到)
        lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
        lRUCache.get(1);    // 返回 -1 (未找到)
        lRUCache.get(3);    // 返回 3
        lRUCache.get(4);    // 返回 4
    }
}

class LRUCache {
    private class Item {
        Item prev;
        Item next;
        int value;

        Item(int value) {
            this.value = value;
        }
    }

    private Map<Integer, Item> map = new HashMap<>();
    //dump head;dump tail;
    private Item head;
    private Item tail;
    private int capacity;
    private int num;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        num = 0;
        head = new Item(-1);
        tail = new Item(-1);
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        if (map.containsKey(key) && map.get(key).value >= 0) {
            Item item = map.get(key);
            remove(item);
            insert(item);
            return item.value;
        } else {
            return -1;
        }
    }

    public void put(int key, int value) {
        if (map.containsKey(key) && map.get(key).value >= 0) {
            Item item = map.get(key);
            item.value = value;
            remove(item);
            insert(item);
        } else {
            Item item = new Item(value);
            map.put(key, item);
            insert(item);
            num++;
            if (num > capacity) {
                tail.prev.value = -1;
                remove(tail.prev);
                num--;
            }
        }
    }

    //中间删除
    private void remove(Item item) {
        Item prev = item.prev;
        Item next = item.next;
        prev.next = next;
        next.prev = prev;
        item.prev = null;
        item.next = null;
    }

    //头部插入
    private void insert(Item item) {
        Item headNext = head.next;
        head.next = item;
        item.prev = head;
        item.next = headNext;
        headNext.prev = item;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */