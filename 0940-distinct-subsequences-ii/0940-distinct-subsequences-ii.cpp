const int N=2e3+1;
const long long mod=1e9+7;
int dp[N][26];
long long f(string &s,int idx,int n,char c){
        if(idx==n){
                return 0;
        }
        if(dp[idx][c-'a']!=-1){
                return dp[idx][c-'a'];
        }
        if(s[idx]==c){
                long long res=1;
                for(char a='a';a<='z';a++){
                        res+=f(s,idx+1,n,a);
                        if(res>=mod){
                                res%=mod;
                        }
                }
                return dp[idx][c-'a']=res;
        }
         return dp[idx][c-'a']=f(s,idx+1,n,c);
}
class Solution {
public:
    int distinctSubseqII(string s) {
        long long res=0;
        memset(dp,-1,sizeof(dp));    
        int n=s.size();    
        for(char a='a';a<='z';a++){
                res+=f(s,0,n,a);
                if(res>=mod){
                        res%=mod;
                }
        }
            return res;
    }
};