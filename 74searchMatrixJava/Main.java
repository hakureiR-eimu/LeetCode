public class Main {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 7};
        Solution sol = new Solution();
        System.out.println(sol.binarySearch(arr, 0));
    }
}

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int colNum = binarySearchCol(matrix, target);
        if (colNum == -1) return false;
        int[] arr = matrix[colNum];
        int res = binarySearch(arr, target);
        if (res >= 0 && arr[res] == target) return true;
        return false;
    }

    private int binarySearchCol(int[][] matrix, int target) {
        int low = 0, high = matrix.length - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (matrix[mid][0] <= target) {
                low = mid + 1;
            } else high = mid - 1;
        }
        return high;
    }

    public int binarySearch(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (arr[mid] <= target) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
}