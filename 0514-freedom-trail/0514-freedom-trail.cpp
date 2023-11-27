const int N=1e2+1;
int dp[N][N];
int f(int i,int j,string &a,string &b,int n,int m){
        if(j==m){
                return 0;
        }
        if(dp[i][j]!=-1){
                return dp[i][j];
        }
        int op=0,res=INT_MAX;
        //clock
        while(op<n && a[(i+op)%n]!=b[j]){
                op++;
        }
        res=1+op+f((i+op)%n,j+1,a,b,n,m);
        //anti-clock
        op=0;
        while(op<n && a[(i-op+n)%n]!=b[j]){
                op++;
        }
        res=min(res,1+op+f((i-op+n)%n,j+1,a,b,n,m));
        return dp[i][j]=res;
}
class Solution {
public:
    int findRotateSteps(string ring, string key) {
       int n=ring.size(),m=key.size();
            memset(dp,-1,sizeof(dp));
            return f(0,0,ring,key,n,m);
    }
};