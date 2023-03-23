int dp[101][101][101];
const long long mod=1e9+7;
long long f(vector<int>&profit,vector<int>&grp,int idx,int n,int k,int N){
        if(N<0){
                return 0;
        }
        if(k<=0){
             k=0;
        }
        if(dp[idx][k][N]!=-1){
                return dp[idx][k][N];
        }
        if(idx==n){
                return  dp[idx][k][N]=k==0;
        }
        return  dp[idx][k][N]= (f(profit,grp,idx+1,n,k,N)%mod+f(profit,grp,idx+1,n,k-profit[idx],N-grp[idx])%mod)%mod;
}
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
            memset(dp,-1,sizeof(dp));
        return f(profit,group,0,group.size(),minProfit,n);
    }
};