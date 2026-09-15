class Solution {
    public int divide(int a, int b) {
        //a/b的商
        //找到abs(a)/abs(b)的商，然后根据负号数量定符号
        boolean isMinus=false;
        if(a==0) return 0;
        else if((a>0&&b<0)||(a<0&&b>0)){
            isMinus=true;
        }
        a=Math.abs(a);
        b=Math.abs(b);

        //答案区间位于[1,b]之间 寻找最后一个num使得a*num<b
        int left=1,right=b;
        while(left<right){
            int mid=left+(right-left)/2;
            if(a*mid==b){
                return mid;
            }else if(a*mid<b){
                left=mid;
            }else{
                right=mid-1;
            }
        }
        return left;

    }
}