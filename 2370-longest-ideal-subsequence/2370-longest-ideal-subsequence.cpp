int dp[100001][26];
int f(string &s,int idx,int n,int p,int k){
        if(idx>=n){
                return 0;
        }
        if(dp[idx][p]!=-1){
                return dp[idx][p];
        }
        if(abs(s[idx]-'a'-p)<=k){
                return dp[idx][p]=max(1+f(s,idx+1,n,s[idx]-'a',k),f(s,idx+1,n,p,k));
        }
        return dp[idx][p]=f(s,idx+1,n,p,k);
}
class Solution {
public:
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
            int res=1,n=s.size();
            for(int i=0;i<n-res;i++){
                    res=max(res,1+f(s,i+1,n,s[i]-'a',k));
            }
            return res;
    }
        
};