int dp[501][2][2];
const int N=1e9;
int f(string &s,string &t,int idx,int n,int k,int g,int x){
        if(idx==n){
                if(k==0 && g==0){
                        return 0;
                }
                return N;
        }
        if(dp[idx][g][k]!=-1){
                return dp[idx][g][k];
        }
        int c=s[idx]-'0',res=1e9;
        if(k==1){
                c++;
                c&=1;       
        }
        if(c==t[idx]-'0'){
                res=min(res,f(s,t,idx+1,n,0,g,x));
        }
        c++;
        c&=1;
        if(c==t[idx]-'0'){
                res=min(res,1+f(s,t,idx+1,n,1,g,x));
                if(g){
                       res=min(res,f(s,t,idx+1,n,0,g-1,x));
                }
                else{
                 res=min(res,x+f(s,t,idx+1,n,0,g+1,x));
                }
        }
        return  dp[idx][g][k]=res;
       
}
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int n=s1.size();
            memset(dp,-1,sizeof(dp));
            int res=f(s1,s2,0,n,0,0,x);
            return res >=N ? -1:res;
    }
};