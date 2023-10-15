long long dp[501][501];
class Solution {
public:
        
        const long long m=1e9+7;
       long long ways(int k,int cur,int n){
                if(k==0){
                        return cur==0;
                }
                if(cur<0){
                        return 0;
                }
                if(cur>min(k,n-1)){
                        return 0;
                }
               if(dp[k][cur]!=-1){
                       return dp[k][cur];
               }
                return dp[k][cur]=(ways(k-1,cur,n)%m +ways(k-1,cur+1,n)%m+ways(k-1,cur-1,n)%m)%m;
        }
        
    int numWays(int steps, int arrLen) {
            memset(dp,-1,sizeof(dp));
        return ways(steps,0,arrLen);
    }
};