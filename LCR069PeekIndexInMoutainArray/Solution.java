class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            if (left == right) {
                return left;
            } else {
                int mid = left + (right - left) / 2;
                /**
                 * 边界left=k right=k+1 mid=k
                 * left=k right=k+2 mid=k
                 * 不管如何mid+1都有意义
                 */

                //顶峰在最右
                if (mid + 1 == arr.length) {
                    return mid;
                } else {
                    if (arr[mid] > arr[mid + 1]) {
                        //峰顶在mid及左
                        right = mid;
                    } else {
                        //峰顶在mid+1及右
                        left = mid + 1;
                    }
                }
            }
        }
        return 0;
    }

}

// l   top   mid  r  arr[mid]>arr[l]  arr[mid]> arr[r]
//