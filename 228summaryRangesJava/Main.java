import java.util.*;

public class Main {
}

class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans=new ArrayList<>();
        int i=0;
        int n=nums.length;
        while(i<n){
            int low=i;
            i++;
            while(i<n&&nums[i]==nums[i-1]+1) i++;
            int high=i-1;
            StringBuffer temp=new StringBuffer(Integer.toString(nums[low]));
            if(low<high){
                temp.append("->");
                temp.append(Integer.toString(nums[high]));
            }
            ans.add(temp.toString());
        }
        return ans;
    }
}