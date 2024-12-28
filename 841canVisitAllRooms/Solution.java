import java.util.*;

class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Stack<Integer> stk = new Stack<Integer>();
        int[] visited = new int[rooms.size()];
        stk.push(0);
        while (!stk.empty()) {
            int roomNum = stk.pop();
            if (visited[roomNum] == 1) continue;
            List<Integer> list = rooms.get(roomNum);
            visited[roomNum] = 1;
            for (int i : list) {
                stk.push(i);
            }
        }
        boolean flag = true;
        for (int i : visited) {
            if (i == 0) flag = false;
        }
        return flag;
    }

}