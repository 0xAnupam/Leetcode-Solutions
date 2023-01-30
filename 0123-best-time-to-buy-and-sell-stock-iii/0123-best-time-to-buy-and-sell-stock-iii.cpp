class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<int> dp(n);
            dp[n-1]=0;
            int pmax=prices[n-1];
            for(int i=n-2;i>=0;i--){
                    pmax=max(pmax,prices[i]);
                    dp[i]=max(dp[i+1],pmax-prices[i]);
            }
            int res=dp[0],p=1e6;
            for(int i=0;i<n-1;i++){
                    p=min(p,prices[i]);
                    res=max(res,prices[i]-p+dp[i+1]);
            }
            return res;
            
    }
};