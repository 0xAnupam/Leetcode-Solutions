const int N=1e5+1;
int dp[N][3];
const int mod=1e9+7;
int f(string &s,int idx,int n,int k){
        if(idx==n){
                return k==2;
        }
        if(k>2){
                return 0;
        }
        if(dp[idx][k]!=-1){
                return dp[idx][k];
        }
        if(k==2){
                return dp[idx][k]=(f(s,idx+1,n,k+(s[idx]=='S'))+f(s,idx+1,n,(s[idx]=='S')))%mod;
        }
        return dp[idx][k]=f(s,idx+1,n,k+(s[idx]=='S'));
}
class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size();
            memset(dp,-1,sizeof(dp));
            return f(corridor,0,n,0);
    }
};