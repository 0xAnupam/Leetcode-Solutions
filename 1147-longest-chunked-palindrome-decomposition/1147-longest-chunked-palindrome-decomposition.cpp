bool match(string &s,int l,int r,int n){
        int len=1;
        for(int i=r;i>=l;i--){
                if(s[i]!=s[n-l-len])return 0;
                len++;
        }
        return 1;
}
const int N=1e3+1;
int dp[N];
int f(string &s,int idx,int n){
        if(idx==n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int res=1;
        for(int i=idx;i<n;i++){
                if(match(s,idx,i,n)){
                        res=max(res,1+f(s,i+1,n));
                }
        }
        return dp[idx]=res;
        
        
}
class Solution {
public:
    int longestDecomposition(string text) {
        int n=text.size();
            memset(dp,-1,sizeof(dp));
            return f(text,0,n);
    }
};