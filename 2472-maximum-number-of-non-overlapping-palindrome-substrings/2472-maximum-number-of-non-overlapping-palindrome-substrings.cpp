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
int f(string &s,int idx,int n,int k){
        if(idx==n){
                return 0;
        }
        if(dp[idx]!=-1){
                return dp[idx];
        }
        int res=f(s,idx+1,n,k);
        int l=idx+k-1;
        for(int i=l;i<n;i++){
                if(pal[idx][i]){
                        res=max(res,1+f(s,i+1,n,k));
                }
        }
        return dp[idx]=res;
}
class Solution {
public:
    int maxPalindromes(string s, int k) {
        memset(pal,0,sizeof(pal));
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        for(int i=0;i<n;i++){
                fun(s,i,n);
        }    
        
            return f(s,0,n,k);
    }
};