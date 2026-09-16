import java.util.*;

public class RandomizedSet {
    private Map<Integer, Integer> valToIndex = new HashMap<>();
    private int[] validArr;
    private int len = 0;

    /**
     * Initialize your data structure here.
     */
    public RandomizedSet() {
        validArr = new int[(int) (2 * 1e5 + 5)];
    }

    /**
     * Inserts a value to the set. Returns true if the set did not already contain the specified element.
     */
    public boolean insert(int val) {
        if (valToIndex.containsKey(val)) return false;
        else {
            validArr[len] = val;
            valToIndex.put(val, len);
            len++;
            return true;
        }
    }

    /**
     * Removes a value from the set. Returns true if the set contained the specified element.
     */
    public boolean remove(int val) {
        //删除的情况如下
        //如果不存在元素，返回false
        //如果存在元素，但是元素在有效范围外，返回false
        //否则 如果是最后一个元素，使得len缩小
        //否则 交换最后一个位置和index位置 再使得len减小
        if (!valToIndex.containsKey(val)) {
            return false;
        } else {
            int index = valToIndex.get(val);
            if (index >= len) {
                valToIndex.remove(val);
                return false;
            } else {
                if (index == len - 1) {
                    valToIndex.remove(val);
                    len--;
                    return true;
                } else {
                    //更新index位置和len-1位置的元素，
                    int lastVal = validArr[len - 1];
                    valToIndex.remove(val);
                    valToIndex.remove(lastVal);
                    validArr[index] = lastVal;
                    len--;
                    valToIndex.put(lastVal, index);
                    return true;
                }
            }
        }
    }

    /**
     * Get a random element from the set.
     */
    public int getRandom() {
        int random = new Random().nextInt(0, len);
        return validArr[random];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */