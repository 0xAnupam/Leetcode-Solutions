int dp[1000][30];
        const long long mod=1e9+7;
        long long ways(int n,int k,int target,int cur,int ind){
                if(ind==n){
                        if(cur==target){
                                return 1;
                        }
                        return 0;
                }
                if(cur>=target){
                        return 0;
                }
                if(dp[cur][ind]!=-1){
                        return dp[cur][ind];
                }
                long long res=0;
                for(int i=1;i<=k;i++){
                        res+=(ways(n,k,target,cur+i,ind+1))%mod;
                        res%=mod;
                }
                return dp[cur][ind]=res;
        }
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
            memset(dp,-1,sizeof(dp));
        return ways(n,k,target,0,0);
    }
};