const int maxN=1e5+1;
const int mod=1e9+7;
int dp[maxN][10];
int f(string &s,int idx,int n,int back){
        if(idx==n)return 1;
        if(dp[idx][back]!=-1)return dp[idx][back];
        if(s[idx]=='*'){
                int res=0;
        
                for(int i=1;i<=9;i++){
                        res+=f(s,idx+1,n,i);
                        res%=mod;
                }
                if(back==1){
                        for(int i=1;i<=9;i++){
                                res+=f(s,idx+1,n,0);
                                res%=mod;
                        }
                }      
                else if(back==2){
                        for(int i=1;i<=6;i++){
                                res+=f(s,idx+1,n,0);
                                res%=mod;
                        }
                        
                }
                return dp[idx][back]=res;
        }
        if(s[idx]=='0'){
                if(!(back==1 || back==2))return 0;
                return dp[idx][back]=f(s,idx+1,n,0);
        }
        if(back==1)return dp[idx][back]=(f(s,idx+1,n,0)+f(s,idx+1,n,s[idx]-'0'))%mod;
        if(back==2 && s[idx]<='6') return dp[idx][back] =(f(s,idx+1,n,0)+f(s,idx+1,n,s[idx]-'0'))%mod;
        return dp[idx][back]=f(s,idx+1,n,s[idx]-'0');
        
}
class Solution {
public:
    int numDecodings(string s) {
            memset(dp,-1,sizeof(dp));
        return f(s,0,s.size(),0);
    }
};