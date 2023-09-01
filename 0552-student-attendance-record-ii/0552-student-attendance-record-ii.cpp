const int N=1e5+1;
const int mod=1e9+7;
int dp[N][2][3];
int f(int n,int abs,int late){
        if(abs==2){
                return 0;
        }
        if(late==3){
                return 0;
        }
        if(n==0){
                return 1;
        }
        if(dp[n][abs][late]!=-1){
                return dp[n][abs][late];
        }
        int present=f(n-1,abs,0);
        int absent=f(n-1,abs+1,0);
        int late_again=f(n-1,abs,late+1);
        return dp[n][abs][late]=((present+absent)%mod+late_again)%mod;
}
class Solution {
public:
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
            return f(n,0,0);
    }
};