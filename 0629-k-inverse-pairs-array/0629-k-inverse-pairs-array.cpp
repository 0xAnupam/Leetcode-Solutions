const int N=1e3+1;
const int mod=1e9+7;
int dp[N][N];
int t(int n,int k){
        if(n==1)return k==0;
        if(k<0)return 0;
        if(dp[n][k]!=-1)return dp[n][k];
        return dp[n][k]= ((t(n,k-1)+t(n-1,k))%mod-t(n-1,k-n)+mod)%mod;
}
class Solution {
public:
    int kInversePairs(int n, int k) {
        if(2*k>n*(n-1))return 0;
            memset(dp,-1,sizeof(dp));
        return t(n,k);
    }
};