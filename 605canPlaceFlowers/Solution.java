class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int m = flowerbed.length;
        int[] a = new int[m + 2];
        for (int i = 0; i < m + 2; ++i) {
            if (i == 0) a[i] = 0;
            else if (i == m + 1) a[i] = 0;
            else a[i] = flowerbed[i - 1];
        }
        for (int i = 1; i < m + 1; ++i) {
            if (a[i] == 0 && a[i - 1] == 0 && a[i + 1] == 0) {
                a[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
}