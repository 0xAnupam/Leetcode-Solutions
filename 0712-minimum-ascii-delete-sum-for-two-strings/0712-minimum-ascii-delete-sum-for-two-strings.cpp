int dp[501][501];
int f(string &a,string &b,int l,int h,int &n,int &m){
        if(l==n){
               int p=0;
                for(int i=h;i<m;i++){
                        p+=b[i];
                }
                return p;
        }
        if(h==m){
                int p=0;
                for(int i=l;i<n;i++){
                        p+=a[i];
                }
                return p;
        }
        if(dp[l][h]!=-1){
                return dp[l][h];
        }
        if(a[l]!=b[h]){
                return dp[l][h]=min(a[l]+f(a,b,l+1,h,n,m),b[h]+f(a,b,l,h+1,n,m));
        }
        return dp[l][h]=f(a,b,l+1,h+1,n,m);
}
class Solution {
public:
    int minimumDeleteSum(string &word1, string &word2) {
        memset(dp,-1,sizeof(dp));
        int n=word1.size(),m=word2.size();
            return f(word1,word2,0,0,n,m);
    
    }
};