int dp[1000][1000];
class Solution {
public:
        int res(string &s,string &p,int l,int h){
                if(h==p.size()){
                        return 1;
                }
                if(l==s.size()){
                        return 0;
                }
                if(dp[l][h]!=-1){
                        return dp[l][h];
                }
                if(s[l]==p[h]){
                        return dp[l][h]=res(s,p,l+1,h+1)+res(s,p,l+1,h);
                }
                return dp[l][h]=res(s,p,l+1,h);
        }
    int numDistinct(string &s, string &t) {
        memset(dp,-1,sizeof(dp));
            return res(s,t,0,0);
    }
};