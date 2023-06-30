int8_t dp[101][51];
bool f(string &s,int idx,int n,int k){
        if(n==idx){
                return k==0;
        }
        if(k<0){
                return 0;
        }
        if(k>(n>>1)){
                return 0;
        }
        if(dp[idx][k]!=-1){
                return dp[idx][k];
        }
        if(s[idx]=='*'){
                return dp[idx][k]=f(s,idx+1,n,k+1)|| f(s,idx+1,n,k)|| f(s,idx+1,n,k-1);
        }
        if(s[idx]=='('){
                return  dp[idx][k]=f(s,idx+1,n,k+1);
        }
        return dp[idx][k]=f(s,idx+1,n,k-1);
}
class Solution {
public:
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
            return f(s,0,s.size(),0);
    }
};