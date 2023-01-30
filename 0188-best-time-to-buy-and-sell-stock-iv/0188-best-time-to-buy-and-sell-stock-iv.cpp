int dp[1001][101];
int f(vector<int>&prices,int idx,int n,int k){
        if(idx>=n || k==0){
                return 0;
        }
        if(dp[idx][k]!=-1){
                return dp[idx][k];
        }
        int res=f(prices,idx+1,n,k);
        for(int i=idx+1;i<n;i++){
                if(prices[i]>prices[idx]){
                res=max(res,prices[i]-prices[idx]+f(prices,i+1,n,k-1));
                        }
        }
        return dp[idx][k]=res;
}
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
            return f(prices,0,prices.size(),k);
    }
};