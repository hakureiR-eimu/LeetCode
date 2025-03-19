public class Main {
}

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = 0, j = 0, k = 0;
        int[] nums = new int[m + n];
        while (i < m || j < n) {
            if (i == m) {
                nums[k] = nums2[j];
                k++;
                j++;
            } else if (j == n) {
                nums[k] = nums1[i];
                i++;
                k++;
            } else if (nums1[i] <= nums2[j]) {
                nums[k] = nums1[i];
                i++;
                k++;
            } else {
                nums[k] = nums2[j];
                j++;
                k++;
            }
        }
        for (int index = 0; index < m + n; ++index) {
            {
                nums1[index] = nums[index];
            }
        }
    }
}