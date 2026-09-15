public class Main {
    public static void main(String[] args){
        Solution sol=new Solution();
        /**
         * 1,7,9,8,2
         *  1,0,2    =-1
         *  1,2,1    =8
         *  2,3,0         =16
         *  2,4,1   =14
         */

        int[] prices = {1, 7, 9, 8, 2};
        int k=2;
        long res=sol.maximumProfit(prices,k);
        System.out.println(k);
    }
}
class Solution {
    public long maximumProfit(int[] prices, int k) {
        if(k==0||prices.length==0) return 0;
        //profit ijk
        //i     当k==1,代表已经结束i笔交易;k==0||k==2代表已经结束i-1笔交易，正在第i笔交易
        //day     第day天结束
        //status 2=持有股票 1=持有现金 0=持有空单
        int days=prices.length;
        long[][][] profit=new long[k+1][days][3];
        //完成0笔交易 利润为0
        //第0天，利润为-profit[0];0;+profit[0]
        //初始化，第一天如果开始交易
        profit[1][0][2]=-prices[0];
        profit[1][0][0]=prices[0];
        for(int i=1;i<=k;++i){
            for(int day=1;day<days;++day){
                //如果当天结束以后持有股票
                //当天不买入，寻找之前买入的最大利润
                long maxProfit=Long.MIN_VALUE;
                for(int pre=0;pre<day;++pre){
                    maxProfit=Math.max(maxProfit,profit[i-1][pre][2]);
                }
                profit[i][day][2]=maxProfit;
                //当天买入，寻找之前持有现金的最大利润
                maxProfit=Long.MIN_VALUE;
                for(int pre=0;pre<day;++pre){
                    maxProfit=Math.max(maxProfit,profit[i-1][pre][1]);
                }
//                profit[day][i][2]=Math.max(maxProfit,profit[day-1][i-1][1]-prices[day]);
                profit[i][day][2]=Math.max(maxProfit,profit[i-1][day-1][1]-prices[day]);

                //如果当天结束以后持有现金
                maxProfit=Long.MIN_VALUE;
                for(int pre=0;pre<day;++pre){
                    maxProfit=Math.max(maxProfit,profit[i-1][pre][1]);
                }
                //当天平多
                profit[i][day][1]=Math.max(maxProfit,profit[i-1][day-1][2]+prices[day]);
                //当天平空
                profit[i][day][1]=Math.max(maxProfit,profit[i-1][day-1][0]-prices[day]);

                //如果当天结束以后持有空单
                maxProfit=Long.MIN_VALUE;
                for(int pre=0;pre<day;++pre){
                    maxProfit=Math.max(maxProfit,profit[i-1][pre][0]);
                }
                //当天做空
                profit[i][day][0]=Math.max(maxProfit,profit[i-1][day-1][1]+prices[day]);
            }
        }
        long maxProfit=Long.MIN_VALUE;
        for(int i=0;i<=k;++i){
            maxProfit=Math.max(maxProfit,profit[i][days-1][1]);
        }
        return maxProfit;
    }
}