class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int gondola=0,waiting=0,time=1,idx=0,n=customers.size(),board=0;
            int res=0,ans=-1;
            for(int i=0;i<n;i++){
                    customers[i]+=waiting;
                    waiting=0;
                    int p=min(4,customers[i]);
                    board+=p;
                    waiting=customers[i]-p;
                    if(board*boardingCost-time*runningCost > res){
                            res=board*boardingCost-time*runningCost;
                            ans=time;
                    }
                    time++;
            }
            while(waiting){
                    int p=min(4,waiting);
                    board+=p;
                    waiting-=p;
                    if(board*boardingCost-time*runningCost > res){
                            res=board*boardingCost-time*runningCost;
                            ans=time;
                    }
                    time++;
            }
            return ans;
    }
};