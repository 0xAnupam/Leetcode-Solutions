int dp[301][27][27];
int dist(int a,int b){
        int i=a/6,j=b/6;
        int n=a%6,m=b%6;
        return abs(i-j)+abs(n-m);
}
int f(string &s,int idx,int n,int a,int b){
        if(idx==n){
                return 0;
        }
        if(a==26 && b==26){
                return f(s,idx+1,n,s[idx]-'A',b);
        }
        if(dp[idx][a][b]!=-1){
                return dp[idx][a][b];
        }
        if(b==26){
                return dp[idx][a][b]=min(dist(a,s[idx]-'A')+f(s,idx+1,n,s[idx]-'A',b),f(s,idx+1,n,a,s[idx]-'A'));
        }
        
        int c=s[idx]-'A';
        return dp[idx][a][b]=min(dist(a,c)+f(s,idx+1,n,c,b),dist(b,c)+f(s,idx+1,n,a,c));
}
class Solution {
public:
    int minimumDistance(string& word) {
            memset(dp,-1,sizeof(dp));
        return f(word,0,word.size(),26,26);
    }
};