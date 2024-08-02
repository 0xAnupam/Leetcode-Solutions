class Solution {
public:
    int fun(vector<int>& cost , int index , int n ,vector<int> &dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=INT_MIN){
            return dp[index];
        }
        int res=cost[index]+min(fun(cost,index+1,n,dp), fun(cost,index+2,n,dp));
        return dp[index]=res;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,INT_MIN);
        return min(fun(cost,0,n,dp) ,fun(cost,1,n,dp));
    }
};