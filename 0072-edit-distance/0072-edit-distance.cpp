int dp[501][501];
int f(string &a,string &b,int l,int h,int &n,int &m){
        if(l==n){
                return m-h;
        }
        if(h==m){
                return n-l;
        }
        if(dp[l][h]!=-1){
                return dp[l][h];
        }
        if(a[l]!=b[h]){
                return dp[l][h]=1+min({f(a,b,l+1,h,n,m),f(a,b,l,h+1,n,m),f(a,b,l+1,h+1,n,m)});
        }
        return dp[l][h]=f(a,b,l+1,h+1,n,m);
}
class Solution {
public:
    int minDistance(string &word1, string &word2) {
        memset(dp,-1,sizeof(dp));
        int n=word1.size(),m=word2.size();
            return f(word1,word2,0,0,n,m);
    }
};