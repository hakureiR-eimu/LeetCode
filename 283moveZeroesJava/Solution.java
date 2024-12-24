class Solution {
    public void moveZeroes(int[] nums) {
        int right=0,left=0;
        while(right<nums.length){
            if(nums[right]==0){
                right++;
            }else{
                swap(nums,left,right);
                right++;
                left++;
            }
        }

    }
    void swap(int[] nums,int a,int b){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }

    public static void main(String[] args) {
        int[] A={0,0,1,2,3,4};
        Solution sol = new Solution();
        sol.moveZeroes(A);
        for(int i:A){
            System.out.printf("%d ",i);
        }
    }

}