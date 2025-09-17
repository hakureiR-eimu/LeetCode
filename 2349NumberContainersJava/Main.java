import java.util.*;

public class Main {
    public static void main(String[] args) {
        NumberContainers nc = new NumberContainers();
        nc.change(1, 10);
        System.out.println(nc.find(10));
        nc.change(1, 20);
        System.out.println(nc.find(10));
        System.out.println(nc.find(20));
        System.out.println(nc.find(30));

    }
}

class NumberContainers {
    private Map<Integer, PriorityQueue<Integer>> numberToLoc;
    private Map<Integer, Integer> locToNumber;


    public NumberContainers() {
        numberToLoc = new HashMap<>();
        locToNumber = new HashMap<>();
    }

    public void change(int index, int number) {
        locToNumber.put(index, number);
        if (!numberToLoc.containsKey(number)) numberToLoc.put(number, new PriorityQueue<>());
        numberToLoc.get(number).add(index);
    }

    public int find(int number) {
        if (!numberToLoc.containsKey(number)) return -1;
        else {
            PriorityQueue<Integer> pq = numberToLoc.get(number);
            if (pq.isEmpty()) return -1;
            while (locToNumber.get(pq.peek()) != number) {
                pq.remove();
                if (pq.isEmpty()) return -1;
            }
            if (!pq.isEmpty()) return pq.peek();
            return -1;
        }
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */