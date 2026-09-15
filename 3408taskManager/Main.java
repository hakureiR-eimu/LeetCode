import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<List<Integer>> list = new ArrayList<>();
        list.add(List.of(1, 101, 10));
        list.add(List.of(2, 102, 20));
        list.add(List.of(3, 103, 15));
        TaskManager taskManager = new TaskManager(list);
        taskManager.add(4, 104, 5);
        taskManager.edit(102, 8);
        int a = taskManager.execTop();
        taskManager.rmv(101);
        taskManager.add(5, 105, 15);
        int b = taskManager.execTop();
        System.out.println(a);
        System.out.println(b);
    }
}

class Task {
    int userId;
    int taskId;
    int priority;
    boolean isDeleted;

    Task(int _userId, int _taskId, int _priority) {
        userId = _userId;
        taskId = _taskId;
        priority = _priority;
        isDeleted = false;
    }
}

class TaskManager {
    private PriorityQueue<Task> pq;
    private Map<Integer, Task> taskMap;
    private int MAX_NUM = 0x3f3f3f3f;

    public TaskManager(List<List<Integer>> tasks) {
        pq = new PriorityQueue<>((task1, task2) -> {
            if (task1.priority != task2.priority) return task2.priority - task1.priority;
            else {
                return task2.taskId - task1.taskId;
            }
        });
        taskMap = new HashMap<>();
        for (List<Integer> list : tasks) {
            Task task = new Task(list.get(0), list.get(1), list.get(2));
            pq.add(task);
            taskMap.put(task.taskId, task);
        }
    }

    public void add(int userId, int taskId, int priority) {
        Task task = new Task(userId, taskId, priority);
        taskMap.put(taskId, task);
        pq.add(task);
    }

    public void edit(int taskId, int newPriority) {
        Task oldTask = taskMap.get(taskId);
        oldTask.isDeleted = true;
        Task task = new Task(oldTask.userId, taskId, newPriority);
        taskMap.put(taskId, task);
        pq.add(task);
    }

    public void rmv(int taskId) {
        Task task = taskMap.get(taskId);
        task.isDeleted = true;
        taskMap.remove(taskId);
    }

    public int execTop() {
        while (!pq.isEmpty()) {
            Task task = pq.peek();
            if (taskMap.containsKey(task.taskId) && !task.isDeleted) {
                taskMap.remove(task.taskId);
                pq.remove();
                return task.userId;
            } else {
                pq.remove();
            }
        }
        return -1;
    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager obj = new TaskManager(tasks);
 * obj.add(userId,taskId,priority);
 * obj.edit(taskId,newPriority);
 * obj.rmv(taskId);
 * int param_4 = obj.execTop();
 */