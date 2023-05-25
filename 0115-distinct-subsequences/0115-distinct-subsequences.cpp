unsigned long long dp[1001][1001];

class Solution {
public:
    int numDistinct(string s, string t) {
        int len1=s.size(), len2=t.size();
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=len1; i++){
            dp[i][len2] = 1;
        }

        for(int i=len1-1;i>=0;i--){
                for(int j=len2-1;j>=0;j--){
                        dp[i][j]=dp[i+1][j];
                        if(s[i]==t[j]){
                                dp[i][j]+=dp[i+1][j+1];
                        }
                }
        }
        return dp[0][0];
    }
};