bool pal[2001][2001];
int dp[2001];
void fun(string &s,int idx,int n){
        int l=idx,r=idx;
        while(l>=0 && r<n && s[l]==s[r] ){
                pal[l][r]=1;
                l--;
                r++;
        }
        l=idx;
        r=l+1;
        while(l>=0 && r<n && s[l]==s[r] ){
                pal[l][r]=1;
                l--;
                r++;
        }
        
}
int f(string &s,int idx,int n){
        if(idx==n){
                return 0;
        }
        if(dp[idx]!=-1){
                return dp[idx];
        }
        int res=n;
        for(int i=idx;i<n;i++){
                if(pal[idx][i]){
                        res=min(res,1+f(s,i+1,n));
                }
        }
        return dp[idx]=res;
}
class Solution {
public: 
    int minCut(string &s) {
            memset(dp,-1,sizeof(dp));
            memset(pal,0,sizeof(pal));
        int n=s.size();
            for(int i=0;i<n;i++){
                    fun(s,i,n);
            }
            return f(s,0,n)-1;
    }
};