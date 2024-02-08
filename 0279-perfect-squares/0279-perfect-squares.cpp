class Solution {
public:
    int numSquares(int n) {
        int memo[n+1];
            memset(memo,-1,sizeof(memo));
            return solve(n,memo);
    }
        int solve(int n,int* memo){
                if(n<4){
                        return n;
                }
                if(memo[n]!=-1){
                        return memo[n];
                }
                int ans=n;
                for(int i=1;i*i<=n;i++){
                        int sq=i*i;
                        ans=min(ans,1+solve(n-sq,memo));
                }
                return memo[n]=ans;
        }
};