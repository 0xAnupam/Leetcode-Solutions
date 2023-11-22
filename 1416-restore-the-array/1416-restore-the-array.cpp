const int N=1e5+1;
const int mod=1e9+7;
int dp[N];
int f(string &s,int idx,int n,int k){
        if(idx==n){
                return 1;
        }
        if(dp[idx]!=-1){
                return dp[idx];
        }
        if(s[idx]=='0'){
                return dp[idx]=0;
        }
        int j=idx;
        long long cur=0,res=0;
        while(j<n && cur<=k){
                cur*=10;
                cur+=(s[j]-'0');
                j++;
                if(cur<=k){
                        res+=f(s,j,n,k);
                        res%=mod;
                }
        }
        return dp[idx]=res;
}
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n=s.size();
            memset(dp,-1,n*sizeof(dp[0]));
            return f(s,0,n,k);
    }
};