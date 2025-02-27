import java.util.*;

public class Main {
}

class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        final int mod = (int) (1e9 + 7);
        if (k == 0) return 0;
        Person[] persons = new Person[n];
        for (int i = 0; i < n; ++i) {
            persons[i] = new Person(speed[i], efficiency[i]);
        }
        //效率从大往小
        Arrays.sort(persons, (a, b) -> b.efficiency - a.efficiency);
        //定一个动一个，枚举效率的最小值，然后求k-1个人速度的最大值，使用小根堆保存最大的k-1个人
        //使用pq维护最大的k个人的速度
        //pq在进入循环时候最多k-1个
        PriorityQueue<Person> pq = new PriorityQueue<>((a, b) -> a.speed - b.speed);
        long ans = -0x3f3f3f3f;
        long cur = 0;
        for (int i = 0; i < n; ++i) {
            Person person = persons[i];
            long cur_t = cur + person.speed;
            long eff = person.efficiency;
            ans = Math.max(ans, cur_t * eff);
            cur += person.speed;
            pq.offer(person);
            if (pq.size() == k) {
                Person removePerson = pq.remove();
                cur -= removePerson.speed;
            }

        }
        return (int) (ans % mod);
    }

    class Person {
        int speed;
        int efficiency;

        Person(int speed, int efficiency) {
            this.speed = speed;
            this.efficiency = efficiency;
        }
    }
}