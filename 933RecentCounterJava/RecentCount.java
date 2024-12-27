import java.util.*;

class RecentCounter {
    Queue<Integer> que;

    public RecentCounter() {
        que = new ArrayDeque<>();
    }

    public int ping(int t) {
        que.offer(t);
        //int count=0;
        while (que.peek() < t - 3000) {
            que.poll();
        }
        return que.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */