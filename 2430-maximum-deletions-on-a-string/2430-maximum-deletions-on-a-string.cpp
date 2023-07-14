int16_t dp[4000];
int8_t eq(string &s,int i,int j,int &n){
        int len=j-i+1;
        if(n-j+1<len){
                return 0;
        }
        int cnt=0;
        while(i<j && s[i]==s[j+cnt]){
                i++;
                cnt++;
        }
        return cnt+1==len;
}
int f(string &s,int i,int n){
        if(i==n){
                return 0;
        }
        if(dp[i]){
                return dp[i];
        }
        int res=1;
        int len=(n-i+1)/2;
        len=min(i+len+1,n);
        int y=0;
        for(int j=i+1;j<len && y<100;j++){
                if(eq(s,i,j,n)){
                        res=max(res,1+f(s,j,n));
                        y++;
                }
        }
        return dp[i]=res;
}
class Solution {
public:
    int deleteString(string s) {
        memset(dp,0,sizeof(dp));
        return f(s,0,s.size());
    }
};