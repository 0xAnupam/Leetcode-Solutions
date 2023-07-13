int dp[1001][1001][4];
const int mod=1e9+7;
int f(string &s,int i,int j,char c){
        if(i>j){
                return 0;
        }
        if(dp[i][j][c-'a']!=-1){
                return dp[i][j][c-'a'];
        }
        int res=0;
        if(s[i]==s[j] && s[i]==c){
                res+=2;
                res-=(i==j);
                for(char a='a';a<='d';a++){
                        res+=f(s,i+1,j-1,a);
                        if(res>=mod){
                                res%=mod;
                        }
                }
                return dp[i][j][c-'a']=res;
        }
        return dp[i][j][c-'a']=((f(s,i+1,j,c)+f(s,i,j-1,c))%mod+mod-f(s,i+1,j-1,c))%mod;
}
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int res=0,n=s.size();
            memset(dp,-1,sizeof(dp));
            for(char c='a';c<='d';c++){
                    res+=f(s,0,n-1,c);
                    if(res>=mod){
                            res%=mod;
                    }
            }
            return res;
    }
};