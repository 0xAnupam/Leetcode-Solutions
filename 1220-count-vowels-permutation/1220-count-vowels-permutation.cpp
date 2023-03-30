const int N=2e4+1;
const long long mod=1e9+7;
long long dp[N][5];
long long f(int n,int pre){
        if(n==0){
                return 1;
        }
        if(dp[n][pre]!=-1){
                return dp[n][pre];
        }
        
        if(pre==0){
                return dp[n][pre]=f(n-1,1)%mod;
        }
        if(pre==1){
                return dp[n][pre]=(f(n-1,0)%mod+f(n-1,2)%mod)%mod;
        }
        if(pre==2){
                 return dp[n][pre]=(f(n-1,0)%mod+f(n-1,1)%mod+f(n-1,3)%mod+f(n-1,4)%mod)%mod;
        }
        if(pre==3){
                return dp[n][pre]=(f(n-1,2)%mod+f(n-1,4)%mod)%mod;
        }
        return dp[n][pre]=f(n-1,0)%mod;
}
class Solution {
public:
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
           return (f(n-1,2)%mod+f(n-1,0)%mod+f(n-1,1)%mod+f(n-1,3)%mod+f(n-1,4)%mod)%mod;
    }
};