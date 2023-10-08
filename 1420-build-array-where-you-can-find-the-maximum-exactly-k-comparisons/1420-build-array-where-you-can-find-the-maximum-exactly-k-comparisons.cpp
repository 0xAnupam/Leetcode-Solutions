const int mod=1e9+7;
int dp[51][101][51];
int f(int idx,int n,int m,int k,int p){
        if(idx==n){
                return k==0;
        }
        if(n-idx<k){
                return 0;
        }
        if(k<0){
                return 0;
        }
        if(dp[idx][p][k]!=-1){
                return dp[idx][p][k];
        }
        int res=(p*1LL*f(idx+1,n,m,k,p))%mod;
        for(int i=p+1;i<=m;i++){
                res+=f(idx+1,n,m,k-1,i);
                res%=mod;
        }
        return dp[idx][p][k]=res;
}
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
            memset(dp,-1,sizeof(dp));
        return f(0,n,m,k,0);
    }
};